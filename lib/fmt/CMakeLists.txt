FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  # https://github.com/fmtlib/fmt/releases/tag/9.0.0
  GIT_TAG c4ee726532178e556d923372f29163bd206d7732)

FetchContent_MakeAvailable(fmt)

set(fmt_SOURCE_DIR
    ${fmt_SOURCE_DIR}
    PARENT_SCOPE)
