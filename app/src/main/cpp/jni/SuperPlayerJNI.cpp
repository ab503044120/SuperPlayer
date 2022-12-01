#include <jni.h>
#include <string>
#include "SuperPlayer.h"
#include "utils/JniEnv.h"
extern "C"
JNIEXPORT jlong JNICALL
Java_org_huihui_superplayer_SuperPlayer_nInit(JNIEnv *env, jobject thiz) {
  return reinterpret_cast<jlong>(new SuperPlayer());
}

extern "C"
JNIEXPORT void JNICALL
Java_org_huihui_superplayer_SuperPlayer_nSetDataSource(JNIEnv *env, jobject thiz, jlong ptr, jstring url) {
  char *cUrl = (char *) env->GetStringUTFChars(url, nullptr);
  reinterpret_cast<SuperPlayer *>(ptr)->setDataSource(cUrl);
  env->ReleaseStringUTFChars(url, cUrl);
}
extern "C"
JNIEXPORT void JNICALL
Java_org_huihui_superplayer_SuperPlayer_nSetSurface(JNIEnv *env, jobject thiz, jlong ptr, jobject surface) {
//    reinterpret_cast<SuperPlayer *>(ptr)->setSurface(surface, env);
}
extern "C"
JNIEXPORT void JNICALL
Java_org_huihui_superplayer_SuperPlayer_nPrepare(JNIEnv *env, jobject thiz, jlong ptr) {
  reinterpret_cast<SuperPlayer *>(ptr)->prepare();
}
extern "C"
JNIEXPORT void JNICALL
Java_org_huihui_superplayer_SuperPlayer_nStart(JNIEnv *env, jobject thiz, jlong ptr) {
}
extern "C"
JNIEXPORT void JNICALL
Java_org_huihui_superplayer_SuperPlayer_nPause(JNIEnv *env, jobject thiz, jlong ptr) {
}
extern "C"
JNIEXPORT void JNICALL
Java_org_huihui_superplayer_SuperPlayer_nReset(JNIEnv *env, jobject thiz, jlong ptr) {
}
extern "C"
JNIEXPORT void JNICALL
Java_org_huihui_superplayer_SuperPlayer_nStop(JNIEnv *env, jobject thiz, jlong ptr) {
}


extern "C"
JNIEXPORT void JNICALL
Java_org_huihui_superplayer_SuperPlayer_nRelease(JNIEnv *env, jobject thiz, jlong ptr) {
  reinterpret_cast<SuperPlayer *>(ptr)->release();
  delete reinterpret_cast<SuperPlayer *>(ptr);
}

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) {
  JniEnv::init(vm);
  return JNI_VERSION_1_6;
}