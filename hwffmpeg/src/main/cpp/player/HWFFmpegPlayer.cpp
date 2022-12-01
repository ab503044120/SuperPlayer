//
// Created by 听见 on 2021/10/14.
//

#include "HWFFmpegPlayer.h"
#include "platform.h"
#include <utility>
extern"C"{
#include "libavutil/avutil.h"
}
void HWFFmpegPlayer::start(std::string path) {
  startPlay = true;
  this->path = std::move(path);
  playThread = std::thread(&HWFFmpegPlayer::run, this);
}
void HWFFmpegPlayer::stop() {
  startPlay = false;
  if (playThread.joinable()) {
	playThread.join();
  }
}
//enum AVPixelFormat get_hw_format(AVCodecContext *ctx,
//                                 const enum AVPixelFormat *pix_fmts)
//{
//  const enum AVPixelFormat *p;
//
//  for (p = pix_fmts; *p != -1; p++) {
//    if (*p == hw_pix_fmt)
//      return *p;
//  }
//
//  fprintf(stderr, "Failed to get HW surface format.\n");
//  return AV_PIX_FMT_NONE;
//}

void HWFFmpegPlayer::run() {
  av_log(nullptr,AV_LOG_VERBOSE,"%s\n","running");
  AVFormatContext *ctx= nullptr;
  int32_t videoStreamId = -1;
  AVStream * videoStream = nullptr;
  AVCodecContext * videoCodecCtx = nullptr;
  const char* hwName = "mediacodec";
  AVCodec *videoCodec = nullptr;
  AVHWDeviceType hwType = AVHWDeviceType::AV_HWDEVICE_TYPE_NONE;
  enum AVPixelFormat hw_pix_fmt=AV_PIX_FMT_NONE;
  int32_t ret;
  ret = avformat_open_input(&ctx, path.c_str(), nullptr, nullptr);
  if (ret < 0) {
    goto out;
  }
  ret = avformat_find_stream_info(ctx, nullptr);
  if (ret < 0) {
    goto out;
  }
  for (int i=0;i<ctx->nb_streams;i++){
    if(ctx->streams[i]->codecpar->codec_type==AVMediaType::AVMEDIA_TYPE_VIDEO){
      videoStreamId = i;
      videoStream = ctx->streams[i];
      break;
    }
  }
  videoCodec = avcodec_find_decoder(videoStream->codecpar->codec_id);
  hwType = av_hwdevice_find_type_by_name(hwName);
  for (int i=0;;i++){
    const AVCodecHWConfig * config = avcodec_get_hw_config(videoCodec, i);
    if(!config){
      goto out;
    }
    if(config->methods & AV_CODEC_HW_CONFIG_METHOD_HW_DEVICE_CTX &&
        config->device_type == hwType){
      hw_pix_fmt = config->pix_fmt;
      break;
    }
  }

  videoCodecCtx = avcodec_alloc_context3(videoCodec);
  avcodec_parameters_to_context(videoCodecCtx,videoStream->codecpar);
//  videoCodecCtx->get_format = ;
  out:
  if(ret<0)
    av_log(nullptr,AV_LOG_VERBOSE,"start error %s\n",av_err2str(ret));
  if(ctx!=nullptr){
    avformat_close_input(&ctx);
  }
}
