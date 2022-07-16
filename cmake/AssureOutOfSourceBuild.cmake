function(assure_out_of_source_build)
  # Make sure to resolve possible symlinks
  file(REAL_PATH ${CMAKE_SOURCE_DIR} srcDir)
  file(REAL_PATH ${CMAKE_BINARY_DIR} bindir)

  # Disallow in-source builds
  if("${srcdir}" STREQUAL "${bindir}")
    message(
      FATAL_ERROR
        "In-source builds are disabled. "
        "Please create a separate build directory and run cmake from there.")
  endif()
endfunction()

assure_out_of_source_build()
