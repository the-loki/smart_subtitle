cmake_minimum_required(VERSION 3.22)
project(asr_svc)

set(CMAKE_CXX_STANDARD 20)

set(TARGET_NAME ${PROJECT_NAME})
file(GLOB_RECURSE ${TARGET_NAME}_SERVER_SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable(${TARGET_NAME})
target_sources(${TARGET_NAME} PRIVATE ${${TARGET_NAME}_SERVER_SOURCE_FILES})
target_link_libraries(${TARGET_NAME} PUBLIC whisper)
