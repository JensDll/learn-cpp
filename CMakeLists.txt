cmake_minimum_required(VERSION 3.23.2)
project(LearnCPP VERSION 0.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# include(FetchContent)

# FetchContent_Declare(
#   googletest
#   GIT_REPOSITORY https://github.com/google/googletest.git
#   GIT_TAG        4556086674e4dfae2aa5f042d9e7844fc5ef9b89
# )

# FetchContent_MakeAvailable(googletest)

add_subdirectory(modules/data_structures)
add_subdirectory(modules/main)

# enable_testing()

# add_executable(
#   hello_test
#   hello_test.cpp
# )
# target_link_libraries(
#   hello_test
#   gtest_main
# )

# include(GoogleTest)
# gtest_discover_tests(hello_test)
