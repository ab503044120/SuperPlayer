# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.18.1)
add_library(utils utils/Platform.cpp utils/JniEnv.cpp)
target_link_libraries(utils log)
target_include_directories(utils PUBLIC ${CMAKE_CURRENT_LIST_DIR})
