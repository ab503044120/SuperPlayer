//
// Created by 听见 on 2021/5/8.
//

#ifndef SUPERPLAYER_SUPERPLAYER_H
#define SUPERPLAYER_SUPERPLAYER_H
#include "demuxer/ffmpegDemuxer.h"
#include "libavformat/avformat.h"
#include "utils/Log.h"
#include "thread"
enum PlayStatus {
  PLAYER_IDLE = 0,
  PLAYER_INITIALZED,
  PLAYER_PREPARINIT,
  PLAYER_PREPARING,
  PLAYER_PREPARED,
  PLAYER_PLAYING,
  PLAYER_PAUSED,
  PLAYER_STOPPED,
  PLAYER_COMPLETION,
  PLAYER_ERROR = 99
};

class SuperPlayer {
 private:
  std::atomic<PlayStatus> mPlayStatus = {PLAYER_IDLE};
  ffmpegDemuxer demuxer;
//  std::thread messageThread;

 public:
  void setDataSource(const char *url);

//  void setSurface(jobject surface, JNIEnv *env);

  void prepare();

  void start();

  void pause();

  void reset();

  void stop();

  void release();

};

#endif //SUPERPLAYER_SUPERPLAYER_H
