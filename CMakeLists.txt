cmake_minimum_required(VERSION 4.0)
project(RockPaperScissors LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SOURCE_FILES
    src/GameEngine.cpp
    src/main.cpp
    src/Move.cpp
)

add_executable(RockPaperScissors ${SOURCE_FILES})
target_include_directories(RockPaperScissors PRIVATE include)