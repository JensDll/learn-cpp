if(BUILD_TESTING)
  include(FetchContent)

  FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        4556086674e4dfae2aa5f042d9e7844fc5ef9b89
  )

  FetchContent_MakeAvailable(googletest)

  enable_testing()

  message(STATUS "Building tests")
  include(GoogleTest)
endif()
