cmake_minimum_required(VERSION 3.22)
project(subtitle_server)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(thirdparty)
add_subdirectory(whisper_server)
add_subdirectory(translate_server)
