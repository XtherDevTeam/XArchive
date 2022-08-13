cmake_minimum_required(VERSION 3.23)
project(XArchive)

set(CMAKE_CXX_STANDARD 20)

file(GLOB SRC_FILES
        Exceptions/*.cpp
        Sources/*.cpp)

add_executable(XArchive main.cpp ${SRC_FILES})
set(CMAKE_EXE_LINKER_FLAGS "--static -lpthread")