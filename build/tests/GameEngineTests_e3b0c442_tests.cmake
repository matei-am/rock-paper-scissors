add_test([=[PlayerTest.AddWinIncrementsWinCount]=]  /Users/matei_a.m/Documents/Work/Rock-Paper-Scissors/rock-paper-scissors/build/tests/GameEngineTests [==[--gtest_filter=PlayerTest.AddWinIncrementsWinCount]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[PlayerTest.AddWinIncrementsWinCount]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/Users/matei_a.m/Documents/Work/Rock-Paper-Scissors/rock-paper-scissors/tests/GameEngineTest.cpp:6]==]
    WORKING_DIRECTORY [==[/Users/matei_a.m/Documents/Work/Rock-Paper-Scissors/rock-paper-scissors/build/tests]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[PlayerTest.AddLoseIncrementsLoseCount]=]  /Users/matei_a.m/Documents/Work/Rock-Paper-Scissors/rock-paper-scissors/build/tests/GameEngineTests [==[--gtest_filter=PlayerTest.AddLoseIncrementsLoseCount]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[PlayerTest.AddLoseIncrementsLoseCount]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/Users/matei_a.m/Documents/Work/Rock-Paper-Scissors/rock-paper-scissors/tests/GameEngineTest.cpp:12]==]
    WORKING_DIRECTORY [==[/Users/matei_a.m/Documents/Work/Rock-Paper-Scissors/rock-paper-scissors/build/tests]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[PlayerTest.AddDrawIncrementsDrawCount]=]  /Users/matei_a.m/Documents/Work/Rock-Paper-Scissors/rock-paper-scissors/build/tests/GameEngineTests [==[--gtest_filter=PlayerTest.AddDrawIncrementsDrawCount]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[PlayerTest.AddDrawIncrementsDrawCount]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/Users/matei_a.m/Documents/Work/Rock-Paper-Scissors/rock-paper-scissors/tests/GameEngineTest.cpp:17]==]
    WORKING_DIRECTORY [==[/Users/matei_a.m/Documents/Work/Rock-Paper-Scissors/rock-paper-scissors/build/tests]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[PlayerTest.CheckStatsDisplay]=]  /Users/matei_a.m/Documents/Work/Rock-Paper-Scissors/rock-paper-scissors/build/tests/GameEngineTests [==[--gtest_filter=PlayerTest.CheckStatsDisplay]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[PlayerTest.CheckStatsDisplay]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/Users/matei_a.m/Documents/Work/Rock-Paper-Scissors/rock-paper-scissors/tests/GameEngineTest.cpp:23]==]
    WORKING_DIRECTORY [==[/Users/matei_a.m/Documents/Work/Rock-Paper-Scissors/rock-paper-scissors/build/tests]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
set(GameEngineTests_TESTS [==[PlayerTest.AddWinIncrementsWinCount]==] [==[PlayerTest.AddLoseIncrementsLoseCount]==] [==[PlayerTest.AddDrawIncrementsDrawCount]==] [==[PlayerTest.CheckStatsDisplay]==])
