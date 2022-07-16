FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  # https://github.com/catchorg/Catch2/releases/tag/v3.0.1
  GIT_TAG 605a34765aa5d5ecbf476b4598a862ada971b0cc)

FetchContent_MakeAvailable(Catch2)

list(APPEND CMAKE_MODULE_PATH "${catch2_SOURCE_DIR}/extras")

include(CTest)
include(Catch)
