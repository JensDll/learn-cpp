add_library(
  learn_cpp_data_structures
  include/data_structures.hpp
)

set_target_properties(learn_cpp_data_structures PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(
  learn_cpp_data_structures
  INTERFACE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)

if(BUILD_TESTING)
  message(STATUS "Adding learn_cpp_data_structures_test executable")

  add_executable(
    learn_cpp_data_structures_test
    tests/linked_list_test.cpp
  )

  target_link_libraries(
    learn_cpp_data_structures_test
    GTest::gtest_main
  )

  include(GoogleTest)
  gtest_discover_tests(learn_cpp_data_structures_test)
endif()
