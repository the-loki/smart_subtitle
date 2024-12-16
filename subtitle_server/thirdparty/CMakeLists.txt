cmake_minimum_required(VERSION 3.22)

function(IMPORT_NANOMSG)
    set(NN_ENABLE_DOC OFF)
    add_subdirectory(nanomsg-1.2.1)
endfunction()

function(IMPORT_LLAMA_CPP)
    add_subdirectory(llama.cpp-b4329)
endfunction()

function(IMPORT_WHISPER_CPP)
    add_subdirectory(whisper.cpp-1.7.2)
endfunction()

IMPORT_NANOMSG()
IMPORT_LLAMA_CPP()
IMPORT_WHISPER_CPP()