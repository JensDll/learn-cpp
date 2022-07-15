add_executable(learn_cpp main.cpp)

target_link_libraries(learn_cpp PRIVATE project_warnings project_options learn_cpp_data_structures)

# cmake_print_properties(
#   TARGETS project_options
#   PROPERTIES TYPE
#              # Compiler flags
#              INCLUDE_DIRECTORIES
#              COMPILE_DEFINITIONS
#              COMPILE_OPTIONS
#              INTERFACE_INCLUDE_DIRECTORIES
#              INTERFACE_COMPILE_DEFINITIONS
#              INTERFACE_COMPILE_OPTIONS
#              # Linker flags
#              LINK_LIBRARIES
#              LINK_OPTIONS
#              LINK_FLAGS
#              STATIC_LIBRARY_OPTIONS
#              STATIC_LIBRARY_FLAGS)

# cmake_print_properties(
#   TARGETS project_warnings
#   PROPERTIES TYPE
#              # Compiler flags
#              INCLUDE_DIRECTORIES
#              COMPILE_DEFINITIONS
#              COMPILE_OPTIONS
#              INTERFACE_INCLUDE_DIRECTORIES
#              INTERFACE_COMPILE_DEFINITIONS
#              INTERFACE_COMPILE_OPTIONS
#              # Linker flags
#              LINK_LIBRARIES
#              LINK_OPTIONS
#              LINK_FLAGS
#              STATIC_LIBRARY_OPTIONS
#              STATIC_LIBRARY_FLAGS)
