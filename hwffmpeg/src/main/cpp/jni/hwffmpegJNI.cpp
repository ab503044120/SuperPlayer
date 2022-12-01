//
// Created by 听见 on 2021/10/13.
//

#include <jni.h>
#include "HWFFmpegClass.h"
extern "C" {
#include <libavcodec/jni.h>
#include "libavformat/avformat.h"
#include "libavcodec/avcodec.h"
}
#include "platform.h"
#include "Log.h"
namespace fbjni = facebook::jni;
void callback(void *avcl, int level, const char *fmt, va_list vl) {
  int32_t l = ANDROID_LOG_VERBOSE;
  switch (level) {
	case AV_LOG_FATAL   : l = ANDROID_LOG_FATAL;
	  break;
	case AV_LOG_ERROR   : l = ANDROID_LOG_ERROR;
	  break;
	case AV_LOG_WARNING : l = ANDROID_LOG_WARN;
	  break;
	case AV_LOG_INFO    : l = ANDROID_LOG_INFO;
	  break;
	case AV_LOG_VERBOSE : l = ANDROID_LOG_VERBOSE;
	  break;
	case AV_LOG_DEBUG   : l = ANDROID_LOG_DEBUG;
	  break;
	default: l = ANDROID_LOG_VERBOSE;
  }
  Logger::log(l, "ffmpeg", fmt, vl);
}
JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) {
  hwffpmpegPlayer::log::logv = logv;
  hwffpmpegPlayer::log::logd = logd;
  hwffpmpegPlayer::log::logi = logi;
  hwffpmpegPlayer::log::logw = logw;
  hwffpmpegPlayer::log::loge = loge;
  av_jni_set_java_vm(vm, nullptr);
  av_log_set_level(AV_LOG_TRACE);
  av_log_set_callback(callback);
  return fbjni::initialize(vm, []() -> void {
	HWFFmpegClass::regist();
  });
}
