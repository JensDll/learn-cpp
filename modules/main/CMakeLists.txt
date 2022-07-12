add_executable(learn_cpp main.cpp)

target_link_libraries(
  learn_cpp PRIVATE
  learn_cpp_data_structures
)
