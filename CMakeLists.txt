cmake_minimum_required(VERSION 3.24)

project(according_to_my_calculations)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.8.1
)

FetchContent_MakeAvailable(Catch2)

add_executable(calculator_test tests/calculator_test.cpp src/calculator.cpp)
add_executable(main main.cpp src/calculator.cpp)

target_link_libraries(calculator_test PRIVATE Catch2::Catch2WithMain)
