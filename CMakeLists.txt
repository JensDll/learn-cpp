cmake_minimum_required(VERSION 3.23)

project(
  LearnCPP
  VERSION 0.0.0
  LANGUAGES C CXX)

include(FetchContent)
include(CMakePrintHelpers)

include(cmake/StandardProjectSettings.cmake)
include(cmake/PreventInSourceBuilds.cmake)

# Link this library to set the c++ standard / compile-time options requested
add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_20)

if(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
  option(ENABLE_BUILD_WITH_TIME_TRACE "Enable -ftime-trace to generate time tracing .json files on clang" OFF)

  if(ENABLE_BUILD_WITH_TIME_TRACE)
    target_compile_options(project_options INTERFACE -ftime-trace)
  endif()
endif()

# Link this library to use the warnings specified in Warnings.cmake
add_library(project_warnings INTERFACE)

# Enable cache system
include(cmake/Cache.cmake)

# Configure linker options
include(cmake/Linker.cmake)
configure_linker(project_options)

# Configure sanitizer options if supported by compiler
include(cmake/Sanitizers.cmake)
configure_sanitizers(project_options)

# Configure compiler warnings
include(cmake/Warnings.cmake)
configure_warnings(project_warnings)

# Enable doxygen
include(cmake/Doxygen.cmake)
enable_doxygen()

# Allow for static analysis options
include(cmake/StaticAnalyzers.cmake)

option(BUILD_SHARED_LIBS "Enable compilation of shared libraries" OFF)

option(ENABLE_CONAN "Use Conan for dependency management" OFF)
if(ENABLE_CONAN)
  include(cmake/Conan.cmake)
  run_conan()
endif()

option(ENABLE_TESTING "Enable Test Builds" OFF)
if(ENABLE_TESTING)
  enable_testing()
  message("Building tests")
  add_subdirectory(lib/Catch2)
endif()

add_subdirectory(lib/fmt)
add_subdirectory(lib/spdlog)

# option(ENABLE_FUZZING "Enable Fuzzing Builds" OFF)
# if(ENABLE_FUZZING)
#   message("Building Fuzz Tests, using fuzzing sanitizer https://www.llvm.org/docs/LibFuzzer.html")
#   add_subdirectory(fuzz_test)
# endif()

add_subdirectory(modules/data_structures)
add_subdirectory(modules/main)
