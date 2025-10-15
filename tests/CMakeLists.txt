include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/releases/download/v1.16.0/googletest-1.16.0.tar.gz
    DOWNLOAD_EXTRACT_TIMESTAMP ON
    FIND_PACKAGE_ARGS NAMES GTest
)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

file(GLOB ${PROJECT_NAME}_tests_files ./*.cpp)

add_executable(
    ${PROJECT_NAME}_tests
    ${${PROJECT_NAME}_tests_files}
    $<TARGET_OBJECTS:neatcounter_src>
    $<TARGET_OBJECTS:neatcounter_headers>
)

target_include_directories(${PROJECT_NAME}_tests PRIVATE ../include)
target_link_libraries(${PROJECT_NAME}_tests GTest::gtest_main)

gtest_discover_tests(${PROJECT_NAME}_tests)
