//
// Created by huihui on 2019/8/21.
//


#ifndef LOG_LIB_H
#define LOG_LIB_H
#include "android/log.h"
#include <string>
#include <chrono>

std::chrono::steady_clock::time_point currentTime();

bool negativeValueCheck(int32_t value);

#define LOGGER_WITH_TRACK(logger, level, format, ...) \
  logger->log(level,format "\n stack: %s %s %d \n",__VA_ARGS__,__FILE__,__FUNCTION__,__LINE__)

#define LOG_WITH_TRACK(tag, level, format, ...) \
  Logger::log(level,tag,format "\n stack: %s %s %d \n",__VA_ARGS__,__FILE__,__FUNCTION__,__LINE__)

#define LOG(tag, level, format, ...) \
  Logger::log(level,tag,format ,__VA_ARGS__)

#define CHECK_FAIL_LOGE(tag, value, valueCheck, format, ...)  \
  if(valueCheck(value)){                                      \
    Logger::log(ANDROID_LOG_ERROR,tag,format ,__VA_ARGS__);   \
    goto fail;                                                \
  }

#define CHECK_NEGATIVE_FAIL_LOGE(tag, value, format, ...)  \
  if(negativeValueCheck(value)){                                      \
    Logger::log(ANDROID_LOG_ERROR,tag,format ,__VA_ARGS__);   \
    goto fail;                                                \
  }

class Logger {
  std::string tag;
 public:
  Logger(std::string tag);
  static void log(int32_t level, const char *tag, const char *format, va_list vaList);
  static void log(int32_t level, const char *tag, const char *format, ...);
  void log(int32_t level, const char *format, ...);
  void loge(const char *format, ...);
  void logd(const char *format, ...);
  void logw(const char *format, ...);
  void logi(const char *format, ...);
};

void logv(const char *tag, const char *format, ...);

void logd(const char *tag, const char *format, ...);

void logi(const char *tag, const char *format, ...);

void logw(const char *tag, const char *format, ...);

void loge(const char *tag, const char *format, ...);

void logf(const char *tag, const char *format, ...);
#endif
