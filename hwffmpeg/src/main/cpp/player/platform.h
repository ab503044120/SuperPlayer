//
// Created by 听见 on 2021/10/15.
//

#ifndef SUPERPLAYER_HWFFMPEG_SRC_MAIN_CPP_PLAYER_PLATFORM_H_
#define SUPERPLAYER_HWFFMPEG_SRC_MAIN_CPP_PLAYER_PLATFORM_H_
namespace hwffpmpegPlayer {
namespace log {

extern void (*logv)(const char *, const char *, ...);

extern void (*logd)(const char *, const char *, ...);

extern void (*logi)(const char *, const char *, ...);

extern void (*logw)(const char *, const char *, ...);

extern void (*loge)(const char *, const char *, ...);
}
}

#endif //SUPERPLAYER_HWFFMPEG_SRC_MAIN_CPP_PLAYER_PLATFORM_H_
