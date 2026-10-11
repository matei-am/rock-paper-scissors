
add_executable(GameEngineTests
    GameEngineTest.cpp
)

target_link_libraries(GameEngineTests
    PRIVATE
        game_logic
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(GameEngineTests)
