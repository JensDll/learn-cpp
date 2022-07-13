cmake_minimum_required(VERSION 3.23)
project(LearnCPP VERSION 0.0.0)

option(BUILD_TESTING "Build all tests." OFF)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

if(BUILD_TESTING)
  FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        4556086674e4dfae2aa5f042d9e7844fc5ef9b89
  )

  FetchContent_MakeAvailable(googletest)

  enable_testing()

  message(STATUS "Building tests")
endif()

add_subdirectory(modules/data_structures)
add_subdirectory(modules/main)

# if(BUILD_TESTING)
#   FetchContent_Declare(
#     googletest
#     GIT_REPOSITORY https://github.com/google/googletest.git
#     GIT_TAG        4556086674e4dfae2aa5f042d9e7844fc5ef9b89
#   )

#   FetchContent_MakeAvailable(googletest)

#   enable_testing()

#   message(STATUS "Building tests")

#   add_executable(
#     foo_test
#     foo_test.cpp
#   )

#   target_link_libraries(
#     foo_test
#     GTest::gtest_main
#   )

#   include(GoogleTest)
#   gtest_discover_tests(foo_test)
# endif()
