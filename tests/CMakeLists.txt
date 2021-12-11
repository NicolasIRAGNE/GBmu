cmake_minimum_required(VERSION 3.12)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/955c7f837efad184ec63e771c42542d37545eaef.zip
)

include (CTest)

set(TEST_SOURCES
    test_op_add.cpp
    # main.cpp
)

add_compile_options("--coverage")
add_link_options("--coverage")

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(gbmu_tests ${TEST_SOURCES})

set_property(TARGET gbmu_tests PROPERTY CXX_STANDARD 20)
target_link_libraries(gbmu_tests gbmu_lib)

target_include_directories(gbmu_tests
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

target_link_libraries(
    gbmu_tests
    gtest_main
)

install(TARGETS gbmu_tests 
  RUNTIME DESTINATION bin
  )

include(GoogleTest)
gtest_discover_tests(gbmu_tests)
