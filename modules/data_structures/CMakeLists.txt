add_library(learn_cpp_data_structures INTERFACE include/data_structures.hpp)

target_include_directories(learn_cpp_data_structures INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

if(ENABLE_TESTING)
  add_executable(learn_cpp_data_structures_tests tests/linked_list_test.cpp tests/heap_test.cpp)

  target_link_libraries(
    learn_cpp_data_structures_tests
    PRIVATE project_warnings
            project_options
            learn_cpp_data_structures
            Catch2::Catch2WithMain)

  catch_discover_tests(learn_cpp_data_structures_tests TEST_PREFIX "unittests.")
endif()
