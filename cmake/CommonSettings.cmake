if(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
  set(isClangCompiler ON)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  set(isGnuCompiler ON)
endif()

get_property(isMultiConfig GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)

if(isMultiConfig)
  # Add custom configuration types here
  # Professional CMake: A Practical Guide 12th Edition, p. 143
else()
  set(allowedBuildTypes
      Debug
      Release
      MinSizeRel
      RelWithDebInfo)

  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS ${allowedBuildTypes})

  # Set a default build type if none was specified
  if(NOT CMAKE_BUILD_TYPE)
    message(
      STATUS "Setting build type to 'RelWithDebInfo' as none was specified")
    set(CMAKE_BUILD_TYPE
        RelWithDebInfo
        CACHE STRING "Choose the type of build" FORCE)
  elseif(
    NOT
    CMAKE_BUILD_TYPE
    IN_LIST
    allowedBuildTypes)
    message(FATAL_ERROR "Unknown build type: ${CMAKE_BUILD_TYPE}")
  endif()
endif()

# Require C++20 and disable extensions for all targets
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Treat C++20 as a minimum requirement
set(CMAKE_CXX_EXTENSIONS OFF)
# Generate compile_commands.json to make it easier to work with clang based tools
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# Make sure that link libaries are valid targets
# Professional CMake: A Practical Guide 12th Edition, p. 161
set(CMAKE_LINK_LIBRARIES_ONLY_TARGETS ON)

option(ENABLE_IPO
       "Enable Interprocedural Optimization, aka Link Time Optimization (LTO)"
       OFF)

if(ENABLE_IPO)
  include(CheckIPOSupported)

  check_ipo_supported(RESULT isSupported OUTPUT output)

  if(isSupported)
    set(CMAKE_INTERPROCEDURAL_OPTIMIZATION ON)
  else()
    message(SEND_ERROR "IPO is not supported: ${output}")
  endif()
endif()

if(isClangCompiler)
  add_compile_options(-fcolor-diagnostics)

  option(ENABLE_BUILD_WITH_TIME_TRACE
         "Enable -ftime-trace to generate time tracing .json files on clang"
         OFF)

  if(ENABLE_BUILD_WITH_TIME_TRACE)
    target_compile_options(project_options INTERFACE -ftime-trace)
  endif()
elseif(isGnuCompiler)
  add_compile_options(-fdiagnostics-color=always)
else()
  message(
    STATUS
      "No colored compiler diagnostic set for '${CMAKE_CXX_COMPILER_ID}' compiler"
  )
endif()
