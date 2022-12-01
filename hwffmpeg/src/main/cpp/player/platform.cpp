//
// Created by 听见 on 2021/10/15.
//
#include <cstdint>
#include "platform.h"
namespace hwffpmpegPlayer {
namespace log {
void (*logv)(const char *, const char *, ...);

void (*logd)(const char *, const char *, ...);

void (*logi)(const char *, const char *, ...);

void (*logw)(const char *, const char *, ...);

void (*loge)(const char *, const char *, ...);
}
}