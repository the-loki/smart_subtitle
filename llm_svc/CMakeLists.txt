cmake_minimum_required(VERSION 3.22)
project(llm_svc)

set(CMAKE_CXX_STANDARD 20)

function(IMPORT_NANOMSG)
    set(NN_ENABLE_DOC OFF)
    add_subdirectory(${CMAKE_SOURCE_DIR}/../thirdparty/nanomsg-1.2.1 nanomsg.out)
endfunction()

function(IMPORT_LLAMA_CPP)
    add_subdirectory(${CMAKE_SOURCE_DIR}/../thirdparty/llama.cpp-b4329 llama.cpp.out)

    if(MSVC)
        target_compile_options(llama PRIVATE /Zc:__cplusplus)
    endif ()
endfunction()

IMPORT_NANOMSG()
IMPORT_LLAMA_CPP()

set(TARGET_NAME ${PROJECT_NAME})
file(GLOB_RECURSE ${TARGET_NAME}_SERVER_SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp")

message(status "server source files: ${${TARGET_NAME}_SERVER_SOURCE_FILES}")

add_executable(${TARGET_NAME})
target_sources(${TARGET_NAME} PRIVATE ${${TARGET_NAME}_SERVER_SOURCE_FILES})
target_link_libraries(${TARGET_NAME} PRIVATE llama)
