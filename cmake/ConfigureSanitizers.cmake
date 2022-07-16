function(configure_sanitizers projectName)

  if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES
                                             ".*Clang")
    option(ENABLE_COVERAGE "Enable coverage reporting for gcc/clang" OFF)

    if(ENABLE_COVERAGE)
      target_compile_options(${projectName} INTERFACE --coverage -O0 -g)
      target_link_libraries(${projectName} INTERFACE --coverage)
    endif()

    set(sanitizers "")

    option(ENABLE_SANITIZER_ADDRESS "Enable address sanitizer" OFF)
    if(ENABLE_SANITIZER_ADDRESS)
      list(APPEND sanitizers "address")
    endif()

    option(ENABLE_SANITIZER_LEAK "Enable leak sanitizer" OFF)
    if(ENABLE_SANITIZER_LEAK)
      list(APPEND sanitizers "leak")
    endif()

    option(ENABLE_SANITIZER_UNDEFINED_BEHAVIOR
           "Enable undefined behavior sanitizer" OFF)
    if(ENABLE_SANITIZER_UNDEFINED_BEHAVIOR)
      list(APPEND sanitizers "undefined")
    endif()

    option(ENABLE_SANITIZER_THREAD "Enable thread sanitizer" OFF)
    if(ENABLE_SANITIZER_THREAD)
      if("address" IN_LIST sanitizers OR "leak" IN_LIST sanitizers)
        message(
          WARNING
            "Thread sanitizer does not work with Address and Leak sanitizer enabled"
        )
      else()
        list(APPEND sanitizers "thread")
      endif()
    endif()

    option(ENABLE_SANITIZER_MEMORY "Enable memory sanitizer" OFF)
    if(ENABLE_SANITIZER_MEMORY AND CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
      message(
        WARNING
          "Memory sanitizer requires all the code (including libc++) to be MSan-instrumented otherwise it reports false positives"
      )
      if("address" IN_LIST sanitizers
         OR "thread" IN_LIST sanitizers
         OR "leak" IN_LIST sanitizers)
        message(
          WARNING
            "Memory sanitizer does not work with Address, Thread and Leak sanitizer enabled"
        )
      else()
        list(APPEND sanitizers "memory")
      endif()
    endif()

    list(
      JOIN
      sanitizers
      ","
      joinedSanitizers)

  endif()

  if(joinedSanitizers
     AND NOT
         "${joinedSanitizers}"
         STREQUAL
         "")
    target_compile_options(${projectName}
                           INTERFACE -fsanitize=${joinedSanitizers})
    target_link_options(${projectName} INTERFACE -fsanitize=${joinedSanitizers})

  endif()

endfunction()
