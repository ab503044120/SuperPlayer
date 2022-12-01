package org.huihui.superplayer

import android.view.Surface
import android.view.SurfaceHolder

/*
 * @Description: 
 * @version 1.0
 * @author 陈松辉
 * @date 2021/5/10 16:49
 */
class SuperPlayer {


    companion object {
        init {
            System.loadLibrary("mediaplayer_jni")
        }
    }

    private var nativePtr = -1L

    private var surfaceHolder: SurfaceHolder? = null

    init {
        nativePtr = nInit()
    }

    private external fun nInit(): Long

    private external fun nSetDataSource(ptr: Long, url: String)

    private external fun nSetSurface(ptr: Long, surface: Surface)

    private external fun nPrepare(ptr: Long)

    private external fun nStart(ptr: Long)

    private external fun nReset(ptr: Long)

    external private fun nPause(ptr: Long)

    private external fun nStop(ptr: Long)

    private external fun nRelease(ptr: Long)

    fun setDataSource(url: String) {
        if (nativePtr != -1L) {
            nSetDataSource(nativePtr, url)
        }
    }

    fun setSurface(surface: SurfaceHolder?) {
        surfaceHolder = surface
        if (nativePtr != -1L) {
            val surface1 = surface?.surface
            if (surface1 != null) {
                nSetSurface(nativePtr, surface1)
            }
        }
    }

    fun prepare() {
        if (nativePtr != -1L) {
            nPrepare(nativePtr)
        }
    }

    fun start() {
        if (nativePtr != -1L) {
            nStart(nativePtr)
        }
    }

    fun pause() {
        if (nativePtr != -1L) {
            nPause(nativePtr)
        }
    }

    fun reset() {
        if (nativePtr != -1L) {
            nReset(nativePtr)
        }
    }

    fun stop() {
        if (nativePtr != -1L) {
            nStop(nativePtr)
        }
    }

    fun release() {
        if (nativePtr != -1L) {
            nRelease(nativePtr)
            nativePtr = -1L
        }
    }
}