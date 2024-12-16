cmake_minimum_required(VERSION 3.22)
project(asr_svc)

set(CMAKE_CXX_STANDARD 20)

function(IMPORT_NANOMSG)
    set(NN_ENABLE_DOC OFF)
    add_subdirectory(${CMAKE_SOURCE_DIR}/../thirdparty/nanomsg-1.2.1 nanomsg.out)
endfunction()

function(IMPORT_WHISPER_CPP)
    add_subdirectory(${CMAKE_SOURCE_DIR}/../thirdparty/whisper.cpp-1.7.2 whisper.cpp.out)
endfunction()

IMPORT_NANOMSG()
IMPORT_WHISPER_CPP()

set(TARGET_NAME ${PROJECT_NAME})
file(GLOB_RECURSE ${TARGET_NAME}_SERVER_SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp")

add_executable(${TARGET_NAME})
target_sources(${TARGET_NAME} PRIVATE ${${TARGET_NAME}_SERVER_SOURCE_FILES})
target_link_libraries(${TARGET_NAME} PRIVATE whisper)
