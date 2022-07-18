FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  # https://github.com/catchorg/Catch2/releases/tag/v3.1.0
  GIT_TAG 97c48e0c343d26d50764fafdc90b1e630fbd10ce)

FetchContent_MakeAvailable(Catch2)

list(APPEND CMAKE_MODULE_PATH "${catch2_SOURCE_DIR}/extras")

include(CTest)
include(Catch)
