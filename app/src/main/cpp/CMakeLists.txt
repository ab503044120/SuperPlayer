# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.18.1)

# Declares and names the project.

project("superplayer")
include(third_part/third.cmake)

add_subdirectory(third_part)
add_subdirectory(common)
add_subdirectory(player)

add_subdirectory(jni)
