//
// Created by 听见 on 2021/5/11.
//

#include "ffmpegDemuxer.h"
void ffmpegDemuxer::start() {
  std::lock_guard<std::recursive_mutex> lockGuard(mDemuxerMutex);
  if (isStart.load()) {
    if (thread.joinable()) {
      thread.join();
      isStart.store(false);
    }
  }
  thread = std::thread(&ffmpegDemuxer::run, this);
  isStart.store(true);

}
void ffmpegDemuxer::pause() {

}
void ffmpegDemuxer::stop() {

}

void ffmpegDemuxer::run() {
  bool isEof = false;
  std::unique_lock<std::recursive_mutex> lock(mDemuxerMutex);
  mAvFormatContext = avformat_alloc_context();
  int32_t ret = avformat_open_input(&mAvFormatContext, url.c_str(), nullptr, nullptr);
  if (ret < 0) {
    lock.unlock();
    goto out;
  }
  ret = avformat_find_stream_info(mAvFormatContext, nullptr);
  for (int i = 0; i < mAvFormatContext->nb_streams; ++i) {
    if (mAvFormatContext->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_AUDIO && mCurrentAudioIndex < 0) {

    } else if (mAvFormatContext->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO && mCurrentAudioIndex < 0) {

    }
  }
  if (ret < 0) {
    lock.unlock();
    goto out;
  }

  lock.unlock();
  while (true) {
    if (!isStart.load()) {
      break;
    }

  }
  out:
  lock.lock();
  if (ret < 0) {
    if (mDemuxerCallback) {
      mDemuxerCallback->onError(ret);
    }
  }
  if (mAvFormatContext != nullptr) {
    avformat_close_input(&mAvFormatContext);
  }
  isStart = false;
  lock.unlock();
}

void ffmpegDemuxer::setDemuxerCallback(DemuxerCallback *mDemuxerCallback) {
  ffmpegDemuxer::mDemuxerCallback = mDemuxerCallback;
}
