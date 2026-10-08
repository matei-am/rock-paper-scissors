cmake_minimum_required(VERSION 3.28)
project(RockPaperScissors LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SOURCE_FILES
    src/GameEngine.cpp
    src/main.cpp
    src/Move.cpp
)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.tar.gz
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(RockPaperScissors ${SOURCE_FILES})
target_include_directories(RockPaperScissors PRIVATE include)