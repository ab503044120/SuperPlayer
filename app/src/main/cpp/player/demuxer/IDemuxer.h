//
// Created by 听见 on 2021/5/10.
//

#ifndef SUPERPLAYER_IDEMUXER_H
#define SUPERPLAYER_IDEMUXER_H
#include "string"
#include "mutex"
#include "condition_variable"
#include "thread"

class IDemuxer {
 protected:
  std::atomic<bool> isStart{true};
  std::recursive_mutex mDemuxerMutex;
  std::condition_variable_any mDemuxerCond;
  std::thread thread;
 public:
  virtual void start() = 0;

  virtual void pause() = 0;

  virtual void stop() = 0;

};

#endif //SUPERPLAYER_IDEMUXER_H
