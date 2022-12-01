package org.huihui.hwffmpeg

import android.view.Surface

/*
 * @Description: 
 * @version 1.0
 * @author 陈松辉
 * @date 2021/10/13 22:05
 */
class HWFFmpeg {
    companion object {
        init {
            System.loadLibrary("hwffmpeg")
        }
    }

    private var nativeObj: Long = -1L

    init {
        init()
    }

    external fun init()

    external fun start(path: String)

    external fun stop()

    external fun setSurface(surface: Surface)

    external fun setSurfaceSize(width: Int, height: Int)

    external fun release()
}