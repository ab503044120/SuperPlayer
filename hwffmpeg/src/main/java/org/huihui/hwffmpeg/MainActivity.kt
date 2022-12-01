package org.huihui.hwffmpeg

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        HWFFmpeg().start("https://stream7.iqilu" +
                ".com/10339/article/202002/17/778c5884fa97f460dac8d90493c451de.mp4")
    }
}