add_library(
  learn_cpp_data_structures
  "include/data_structures.hpp"
)

set_target_properties(learn_cpp_data_structures PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(
  learn_cpp_data_structures
  INTERFACE
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
  "${CMAKE_CURRENT_SOURCE_DIR}/src"
)
