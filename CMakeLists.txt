cmake_minimum_required(VERSION 3.28)
project(RockPaperScissors LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SOURCE_FILES
    src/GameEngine.cpp
    src/main.cpp
    src/Player.cpp
    src/Human.cpp
    src/Computer.cpp
)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.tar.gz
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

include(CTest)

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()

add_executable(RockPaperScissors ${SOURCE_FILES})

add_library(game_logic
    src/GameEngine.cpp
    src/Player.cpp
)

target_include_directories(game_logic PRIVATE include)
target_include_directories(RockPaperScissors PRIVATE include)
