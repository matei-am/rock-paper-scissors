# Rock, Paper, Scissors

A small C++17 console application where a human player competes against the computer in Rock, Paper, Scissors. The project is structured around separate classes for players, game flow, and the rules, with automated tests for the game logic and player behavior.

## Features

- Prompts for the human player's name and the number of rounds.
- Validates that the round count is a positive integer.
- Accepts `rock`, `paper`, or `scissors` as the human player's move.
- Lets the computer select a move and compares both moves using the game rules.
- Tracks wins, losses, and draws for both players and displays the final statistics.

## Design and structure

The implementation uses object-oriented design where it helps keep responsibilities separate:

- **`Player`** is an abstract base class. It defines the common player interface and stores the win, loss, and draw counters.
- **`Human` and `Computer`** implement the player interface. The game can work with either through a `Player` reference, using polymorphism rather than separate round-handling logic for each player type.
- **`Rules::determineOutcome`** contains the move-comparison rules in a separate, deterministic function. This keeps the core rules independent of console input and output and makes all move combinations straightforward to unit test.
- **`Game`** coordinates rounds, updates player scores based on the outcome, and displays round and final results.
- **`runGame()`** wires the players and game together to start the console application.

Keeping the rule evaluation, player behavior, scoring, and application entry flow in separate components makes the code easier to read, test, and extend—for example, by introducing another player type without duplicating the round-resolution logic.

## Project layout

.
├── CMakeLists.txt
├── include/
│   ├── Computer.h
│   ├── GameEngine.h
│   ├── GameRules.h
│   ├── Human.h
│   ├── Player.h
│   └── RunGame.h
├── src/
│   ├── Computer.cpp
│   ├── GameEngine.cpp
│   ├── GameRules.cpp
│   ├── Human.cpp
│   ├── Player.cpp
│   ├── RunGame.cpp
│   └── main.cpp
└── tests/
    ├── CMakeLists.txt
    ├── GameEngineTest.cpp
    ├── GameRulesTests.cpp
    ├── PlayerTests.cpp
    ├── HumanTestPlayer.h
    ├── TestComputer.h
    └── TestPlayer.h


## Requirements

- **CMake 3.28 or later**
- A C++17-compatible compiler
- **GoogleTest** for the automated tests; CMake downloads the pinned GoogleTest v1.15.2 dependency using `FetchContent` when testing is enabled, so an internet connection is needed the first time the project is configured unless the dependency is already available in the build cache.
- **GCC/G++ and the matching `gcov` tool** for the coverage configuration described below. The current coverage flags (`--coverage`) target GCC-compatible toolchains and are not intended for MSVC.
- **Python and `gcovr`** only if you want to generate the HTML coverage report.

## Build and run

Run the commands from the project root.

Configure the project with testing enabled:

cmake -S . -B build -DBUILD_TESTING=ON

Build the application and test executable:

cmake --build build

Run the console application:

- On Linux/macOS with a single-configuration generator: `./build/RockPaperScissors`
- On Windows with a single-configuration MinGW generator: `./build/RockPaperScissors.exe`
- With a multi-configuration generator such as Visual Studio, the executable is typically under `build/Debug/` or `build/Release/` (for example, `build/Debug/RockPaperScissors.exe`).

The program asks for a name, a positive number of rounds, and a move each round. Enter the moves in lowercase: `rock`, `paper`, or `scissors`.

## Automated tests: GoogleTest and CTest

The project uses **GoogleTest** to define test cases and assertions, and **CTest** to discover and run those tests through CMake. These tools have related but different roles:

- **GoogleTest** is the test framework. Its `TEST`, `EXPECT_EQ`, and related macros make individual cases readable and report which expectations fail. It avoids the need to build and maintain a custom test harness.
- **CTest** is the test runner integrated with CMake. `gtest_discover_tests()` registers the GoogleTest cases so they can be run consistently with one command. CTest returns a failing status when a test fails and can show failure details, making it useful locally and in automated build pipelines.

This combination was chosen because it keeps test definitions close to the C++ project, works with the existing CMake build, and provides a repeatable command for running the full suite.

Run the tests after building:

ctest --test-dir build --output-on-failure

For a multi-configuration generator such as Visual Studio, specify the configuration used to build the tests:

ctest --test-dir build -C Debug --output-on-failure

### What the tests cover

- **`GameRulesTests.cpp`** tests the nine possible combinations of Rock, Paper, and Scissors and verifies the expected win, loss, or draw result.
- **`PlayerTests.cpp`** tests score counters, independent player state, player names, accepted human moves, and that the computer returns one of the supported moves.
- **`GameEngineTest.cpp`** checks that round outcomes update both players' scores, that round and final results are displayed, and that the application asks for the player's name.

The rule tests focus on deterministic unit behavior. The game tests exercise interactions between the game coordinator and player implementations, using test-player classes where predictable moves are needed.

## Code coverage: gcovr

The project includes an `ENABLE_COVERAGE` CMake option. When enabled, CMake adds GCC's `--coverage` instrumentation (with debug-friendly `-O0 -g` options) to the game logic and dependent targets. Running the tests then produces coverage data, which **gcovr** collects and turns into a readable report.

**Why gcovr:** raw compiler coverage files are not convenient to review directly. Gcovr summarizes coverage and can generate an HTML report with source-level detail, making it easier to find lines that the current tests did not execute and decide where additional tests would be valuable.

Install gcovr:

python -m pip install gcovr

Configure a separate coverage build with GCC/G++:

cmake -S . -B build-coverage -DBUILD_TESTING=ON -DENABLE_COVERAGE=ON -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=g++

Build and run the tests to generate coverage data:


cmake --build build-coverage
ctest --test-dir build-coverage --output-on-failure


Generate a detailed HTML report for implementation files under `src/`:

gcovr --root . --filter 'src/.*' --html-details coverage.html build-coverage

Open `coverage.html` in a browser to review the report. Run `gcovr` **after** the tests; the instrumentation is written while the instrumented test code executes. Use a GCC-compatible compiler and the matching `gcov` executable on your `PATH`. The exact compiler setup matters because the current CMake coverage flags are GCC-specific.

## Tool choices at a glance

| Tool | Role in this project | Why it was chosen |
|---|---|---|
| **CMake** | Configures the C++17 build, defines the reusable `game_logic` library and application target, and connects optional testing and coverage settings. | Keeps build configuration in one place, supports multiple IDEs and compiler toolchains, and makes clean builds reproducible without manually compiling each source file. |
| **GoogleTest** | Defines test cases and assertions. | Provides established test macros, clear failure reports, and test isolation without a custom testing framework. Its version is pinned in CMake for repeatable dependency selection. |
| **CTest** | Discovers and runs the registered tests. | Integrates with CMake and exposes a consistent test command (`ctest`) that can be used locally or in CI. |
| **gcovr** | Reads GCC coverage data and produces summary/detail reports. | Converts low-level coverage data into an HTML report that helps identify untested code and guide further test development. |

Project can also be found on: https://github.com/matei-am/rock-paper-scissors
