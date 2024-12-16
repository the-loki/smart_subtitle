# Install script for directory: E:/Development/Private/Cpp/smart_subtitle/subtitle_server/thirdparty/llama.cpp-b4329/ggml

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/subtitle_server")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/Users/57470/AppData/Local/Programs/CLion/bin/mingw/bin/objdump.exe")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("E:/Development/Private/Cpp/smart_subtitle/subtitle_server/cmake-build-debug/thirdparty/llama.cpp-b4329/ggml/src/cmake_install.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "E:/Development/Private/Cpp/smart_subtitle/subtitle_server/cmake-build-debug/thirdparty/llama.cpp-b4329/ggml/src/ggml.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "E:/Development/Private/Cpp/smart_subtitle/subtitle_server/thirdparty/llama.cpp-b4329/ggml/include/ggml.h"
    "E:/Development/Private/Cpp/smart_subtitle/subtitle_server/thirdparty/llama.cpp-b4329/ggml/include/ggml-cpu.h"
    "E:/Development/Private/Cpp/smart_subtitle/subtitle_server/thirdparty/llama.cpp-b4329/ggml/include/ggml-alloc.h"
    "E:/Development/Private/Cpp/smart_subtitle/subtitle_server/thirdparty/llama.cpp-b4329/ggml/include/ggml-backend.h"
    "E:/Development/Private/Cpp/smart_subtitle/subtitle_server/thirdparty/llama.cpp-b4329/ggml/include/ggml-blas.h"
    "E:/Development/Private/Cpp/smart_subtitle/subtitle_server/thirdparty/llama.cpp-b4329/ggml/include/ggml-cann.h"
    "E:/Development/Private/Cpp/smart_subtitle/subtitle_server/thirdparty/llama.cpp-b4329/ggml/include/ggml-cuda.h"
    "E:/Development/Private/Cpp/smart_subtitle/subtitle_server/thirdparty/llama.cpp-b4329/ggml/include/ggml-kompute.h"
    "E:/Development/Private/Cpp/smart_subtitle/subtitle_server/thirdparty/llama.cpp-b4329/ggml/include/ggml-opt.h"
    "E:/Development/Private/Cpp/smart_subtitle/subtitle_server/thirdparty/llama.cpp-b4329/ggml/include/ggml-metal.h"
    "E:/Development/Private/Cpp/smart_subtitle/subtitle_server/thirdparty/llama.cpp-b4329/ggml/include/ggml-rpc.h"
    "E:/Development/Private/Cpp/smart_subtitle/subtitle_server/thirdparty/llama.cpp-b4329/ggml/include/ggml-sycl.h"
    "E:/Development/Private/Cpp/smart_subtitle/subtitle_server/thirdparty/llama.cpp-b4329/ggml/include/ggml-vulkan.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "E:/Development/Private/Cpp/smart_subtitle/subtitle_server/cmake-build-debug/thirdparty/llama.cpp-b4329/ggml/src/ggml-base.a")
endif()

