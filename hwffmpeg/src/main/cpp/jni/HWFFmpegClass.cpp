//
// Created by 听见 on 2021/10/14.
//

#include "HWFFmpegClass.h"
#include "HWFFmpegPlayer.h"

void HWFFmpegClass::regist() {
  javaClassStatic()->registerNatives(
	  {
		  makeNativeMethod("init", HWFFmpegClass::init),
		  makeNativeMethod("start", HWFFmpegClass::start),
		  makeNativeMethod("stop", HWFFmpegClass::stop),
		  makeNativeMethod("setSurface", HWFFmpegClass::setSurface),
		  makeNativeMethod("setSurfaceSize", HWFFmpegClass::setSurfaceSize),
		  makeNativeMethod("release", HWFFmpegClass::release)
	  });
}

void HWFFmpegClass::init(alias_ref<HWFFmpegClass> thiz) {
  int64_t ptr = thiz->getFieldValue(javaClassStatic()->getField<jlong>("nativeObj"));
  if (ptr < 0) {
	thiz->setFieldValue(javaClassStatic()->getField<jlong>("nativeObj"),
						reinterpret_cast<jlong>(new HWFFmpegPlayer()));
  }
}

void HWFFmpegClass::start(alias_ref<HWFFmpegClass> thiz, alias_ref<JString> path) {
  int64_t ptr = thiz->getFieldValue(javaClassStatic()->getField<jlong>("nativeObj"));
  if (ptr > 0) {
	reinterpret_cast<HWFFmpegPlayer *>(ptr)->start(path->toStdString());
  }
}

void HWFFmpegClass::stop(alias_ref<HWFFmpegClass> thiz) {
  int64_t ptr = thiz->getFieldValue(javaClassStatic()->getField<jlong>("nativeObj"));
  if (ptr > 0) {
	reinterpret_cast<HWFFmpegPlayer *>(ptr)->stop();
  }
}

void HWFFmpegClass::setSurface(alias_ref<HWFFmpegClass> thiz, alias_ref<SurfaceClass> surface) {
  int64_t ptr = thiz->getFieldValue(javaClassStatic()->getField<jlong>("nativeObj"));
  if (ptr > 0) {
  }
}

void HWFFmpegClass::setSurfaceSize(alias_ref<HWFFmpegClass> thiz, jint width, jint height) {
  int64_t ptr = thiz->getFieldValue(javaClassStatic()->getField<jlong>("nativeObj"));
  if (ptr > 0) {

  }
}

void HWFFmpegClass::release(alias_ref<HWFFmpegClass> thiz) {
  int64_t ptr = thiz->getFieldValue(javaClassStatic()->getField<jlong>("nativeObj"));
  if (ptr > 0) {
	delete reinterpret_cast<HWFFmpegPlayer *>(ptr);
	thiz->setFieldValue(javaClassStatic()->getField<jlong>("nativeObj"),
						-1L);
  }

}
