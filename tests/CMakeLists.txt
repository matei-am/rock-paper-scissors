include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

FetchContent_MakeAvailable(googletest)

add_executable(GameEngineTests
    GameEngineTest.cpp
)

target_include_directories(GameEngineTests
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(GameEngineTests
    PRIVATE
        game_logic
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(GameEngineTests)
