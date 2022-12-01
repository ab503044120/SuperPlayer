# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.18.1)

find_package(fbjni REQUIRED CONFIG)
#find_package(jsoncpp REQUIRED CONFIG)
add_library(hwffmpeg SHARED hwffmpegJNI.cpp HWFFmpegClass.cpp Log.cpp)

target_link_libraries(hwffmpeg PUBLIC log fbjni::fbjni hwffplayer)

