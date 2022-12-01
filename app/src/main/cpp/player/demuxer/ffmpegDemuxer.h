//
// Created by 听见 on 2021/5/11.
//

#ifndef SUPERPLAYER_FFMPEGDEMUXER_H
#define SUPERPLAYER_FFMPEGDEMUXER_H
#include "IDemuxer.h"
extern "C" {
#include "libavformat/avformat.h"
};
class DemuxerCallback {

 public:
  virtual void onReady() = 0;

  virtual void onPacket(AVPacket *avPacket, int32_t result) = 0;

  virtual void onError(int32_t result) = 0;

  virtual void onFinish() = 0;

};

class ffmpegDemuxer : IDemuxer {
 private:
  std::string url;
  DemuxerCallback *mDemuxerCallback = nullptr;
  AVFormatContext *mAvFormatContext = nullptr;

  int32_t mCurrentAudioIndex = -1;
  int32_t mCurrentVideoIndex = -1;

  void run();
 public:

  void setDemuxerCallback(DemuxerCallback *mDemuxerCallback);

  void start() override;

  void pause() override;

  void stop() override;

};

#endif //SUPERPLAYER_FFMPEGDEMUXER_H
