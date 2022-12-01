//
// Created by 听见 on 2021/10/14.
//

#ifndef SUPERPLAYER_HWFFMPEGPLAYER_H
#define SUPERPLAYER_HWFFMPEGPLAYER_H
extern "C" {
#include "libavformat/avformat.h"
#include "libavcodec/avcodec.h"
}
#include <thread>
#include <string>
enum PLAY_STATUS {
  IDEL,
  START,
};
class HWFFmpegPlayer {
 private:
  PLAY_STATUS status = IDEL;
  std::thread playThread;
  bool startPlay = false;
  std::string path;
 public:
  void start(std::string path);
  void stop();
  void run();
};

#endif //SUPERPLAYER_HWFFMPEGPLAYER_H
