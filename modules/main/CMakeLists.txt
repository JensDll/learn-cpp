add_executable(learn_cpp main.cpp)

target_link_libraries(
  learn_cpp
  PRIVATE project_warnings
          project_options
          learn_cpp_data_structures
          fmt::fmt
          spdlog::spdlog)
