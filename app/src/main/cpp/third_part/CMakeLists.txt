# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.18.1)
include(third.cmake)
foreach (component ${FFMPEG_LIBRARY})
    add_library(${component}
            SHARED IMPORTED GLOBAL)
    set_target_properties(${component} PROPERTIES IMPORTED_LOCATION
            ${CMAKE_CURRENT_LIST_DIR}/ffmpeg/${ANDROID_ABI}/lib/lib${component}.so)
    target_include_directories(${component} INTERFACE ${CMAKE_CURRENT_LIST_DIR}/ffmpeg/${ANDROID_ABI}/include)
endforeach ()
