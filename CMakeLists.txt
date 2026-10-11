
cmake_minimum_required(VERSION 3.28)

project(RockPaperScissors LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Reusable game implementation
add_library(game_logic
    src/GameEngine.cpp
    src/GameRules.cpp
    src/Player.cpp
    src/Human.cpp
    src/Computer.cpp
    src/RunGame.cpp
)

target_include_directories(game_logic
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

# Main application
add_executable(RockPaperScissors
    src/main.cpp
)

target_link_libraries(RockPaperScissors
    PRIVATE
        game_logic
)

# Testing

option(ENABLE_COVERAGE "Enable gcov coverage" OFF)
if(ENABLE_COVERAGE)
    target_compile_options(game_logic PUBLIC --coverage -O0 -g)
    target_link_options(game_logic PUBLIC --coverage)
endif()

include(CTest)

if(BUILD_TESTING)
    include(FetchContent)

    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.tar.gz
    )

    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    FetchContent_MakeAvailable(googletest)

    add_subdirectory(tests)
endif()
