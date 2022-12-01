# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.18.1)

set(DEMUXER_SRC demuxer/IDemuxer.cpp demuxer/ffmpegDemuxer.cpp )

add_library(SuperPlayer SHARED
        ${DEMUXER_SRC}
        SuperPlayer.cpp)
target_link_libraries(SuperPlayer PUBLIC ${FFMPEG_LIBRARY} utils)
target_include_directories(SuperPlayer PUBLIC ${CMAKE_CURRENT_LIST_DIR})