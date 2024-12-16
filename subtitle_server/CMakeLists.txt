cmake_minimum_required(VERSION 3.22)
project(subtitle_server)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(thirdparty)
add_subdirectory(asr_svc)
add_subdirectory(llm_svc)
