cmake_minimum_required(VERSION 3.14)
project(calculator VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(BINARY_RUN ${CMAKE_PROJECT_NAME}_run)
set(CALCULATOR_LIB ${CMAKE_PROJECT_NAME}_lib)
set(BINARY_TEST ${CMAKE_PROJECT_NAME}_test)
include_directories(src)
include_directories(include)
include_directories(include/nodes)

add_library(CALCULATOR_LIB STATIC 
    src/Parser.cpp include/Parser.h
    src/Lexer.cpp include/Lexer.h
    src/Userhandler.cpp include/Userhandler.h
    src/nodes/Variable.cpp include/nodes/Variable.h
    src/nodes/Value.cpp include/nodes/Value.h
    src/nodes/Sum.cpp include/nodes/Sum.h
    src/nodes/Subtraction.cpp include/nodes/Subtraction.h
    src/nodes/Multiplication.cpp include/nodes/Multiplication.h
    src/nodes/Division.cpp include/nodes/Division.h
    include/nodes/INode.h
    )

add_executable(BINARY_RUN src/main.cpp)
#add_executable(BINARY_RUN src/mainTest.cpp)

target_link_libraries(BINARY_RUN PUBLIC CALCULATOR_LIB)


# Testing
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG 6910c9d9165801d8827d628cb72eb7ea9dd538c5 # release v1.16.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

include(GoogleTest)

add_executable(BINARY_TEST
 tests/TestParser.cpp
 tests/TestSum.cpp)

target_link_libraries(BINARY_TEST PUBLIC CALCULATOR_LIB  GTest::gtest_main )

gtest_discover_tests(BINARY_TEST)