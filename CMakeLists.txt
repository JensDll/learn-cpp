cmake_minimum_required(VERSION 3.23)

project(
  LearnCPP
  VERSION 0.0.0
  LANGUAGES C CXX)

include(FetchContent)
include(CMakePrintHelpers)

include(cmake/CommonSettings.cmake)
include(cmake/AssureOutOfSourceBuild.cmake)

# Link this library to set the project's compile-time options
add_library(project_options INTERFACE)

# Link this library to use the warnings specified in Warnings.cmake
add_library(project_warnings INTERFACE)

# Enable cache system
include(cmake/Cache.cmake)

# Configure linker options
include(cmake/ConfigureLinker.cmake)
configure_linker(project_options)

# Configure sanitizer options if supported by compiler
include(cmake/ConfigureSanitizers.cmake)
configure_sanitizers(project_options)

# Configure compiler warnings
include(cmake/ConfigureWarnings.cmake)
configure_warnings(project_warnings)

# Enable doxygen
include(cmake/Doxygen.cmake)
enable_doxygen()

# Allow for static analysis options
include(cmake/StaticAnalyzers.cmake)

option(BUILD_SHARED_LIBS "Enable compilation of shared libraries" OFF)
option(ENABLE_TESTING "Enable Test Builds" ON)

if(ENABLE_TESTING)
  enable_testing()
  message(STATUS "Building tests")
  add_subdirectory(lib/Catch2)
endif()

add_subdirectory(lib/fmt)
add_subdirectory(lib/spdlog)

add_subdirectory(modules/data_structures)
add_subdirectory(modules/main)
