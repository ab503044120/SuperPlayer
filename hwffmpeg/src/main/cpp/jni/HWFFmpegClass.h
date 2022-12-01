//
// Created by 听见 on 2021/10/14.
//

#ifndef SUPERPLAYER_HWFFMPEGCLASS_H
#define SUPERPLAYER_HWFFMPEGCLASS_H
#include "fbjni/fbjni.h"
using namespace facebook::jni;

class SurfaceClass : public JavaClass<SurfaceClass>{
 public:
  static constexpr auto kJavaDescriptor = "Landroid/view/Surface;";
};

class HWFFmpegClass : public JavaClass<HWFFmpegClass> {
 public:
  static constexpr auto kJavaDescriptor = "Lorg/huihui/hwffmpeg/HWFFmpeg;";
  static void regist();

  static void init(alias_ref<HWFFmpegClass> thiz);

  static void start(alias_ref<HWFFmpegClass> thiz, alias_ref<JString> path);

  static void stop(alias_ref<HWFFmpegClass> thiz);

  static void setSurface(alias_ref<HWFFmpegClass> thiz, alias_ref<SurfaceClass> surface);

  static void setSurfaceSize(alias_ref<HWFFmpegClass> thiz, jint width, jint height);

  static void release(alias_ref<HWFFmpegClass> thiz);
};

#endif //SUPERPLAYER_HWFFMPEGCLASS_H
