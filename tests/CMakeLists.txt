include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/955c7f837efad184ec63e771c42542d37545eaef.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
  EXCLUDE_FROM_ALL
)

set(TEST_SOURCES
    test_op_add.cpp
    # main.cpp
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(gbmu_tests ${TEST_SOURCES})

target_link_libraries(gbmu_tests PRIVATE gbmu_core GTest::gtest_main)

target_include_directories(gbmu_tests
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

include(GoogleTest)
gtest_discover_tests(gbmu_tests)
