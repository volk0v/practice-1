include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/releases/download/v1.16.0/googletest-1.16.0.tar.gz
    DOWNLOAD_EXTRACT_TIMESTAMP ON
    FIND_PACKAGE_ARGS NAMES GTest
)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

add_library(${PROJECT_NAME}_tests_sources OBJECT
    console_parser_tests.cpp
)
target_include_directories(${PROJECT_NAME}_tests_sources PRIVATE ../include)

add_executable(
    ${PROJECT_NAME}_tests
    $<TARGET_OBJECTS:neatcounter_sources>
    $<TARGET_OBJECTS:neatcounter_tests_sources>
)

target_include_directories(${PROJECT_NAME}_tests PRIVATE ../include)
target_link_libraries(${PROJECT_NAME}_tests GTest::gtest_main)

gtest_discover_tests(${PROJECT_NAME}_tests)
