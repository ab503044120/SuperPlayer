# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.18.1)

# Declares and names the project.
add_library(hwffplayer HWFFmpegPlayer.cpp platform.cpp)

target_link_libraries(hwffplayer PUBLIC ${FFMPEG_LIBRARY} ${OPENSSL_LIBRARY} log)
target_include_directories(hwffplayer PUBLIC ./)
