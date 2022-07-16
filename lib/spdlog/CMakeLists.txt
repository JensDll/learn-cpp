FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  # https://github.com/gabime/spdlog/releases/tag/v1.10.0
  GIT_TAG 76fb40d95455f249bd70824ecfcae7a8f0930fa3)

FetchContent_MakeAvailable(spdlog)

target_compile_definitions(spdlog PUBLIC SPDLOG_FMT_EXTERNAL)
target_include_directories(spdlog PRIVATE "${fmt_SOURCE_DIR}/include")
