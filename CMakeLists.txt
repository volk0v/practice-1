cmake_minimum_required(VERSION 3.15)
project(neatcounter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

add_library(${PROJECT_NAME}_sources OBJECT
    src/console_parser.cpp include/console_parser.h
    src/file_parser.cpp include/file_parser.h
    include/errors.h
)
target_include_directories(${PROJECT_NAME}_sources PRIVATE include)

enable_testing()
add_subdirectory(tests)

add_executable(
    neatcounter
    main.cpp
    $<TARGET_OBJECTS:neatcounter_sources>
)
target_include_directories(${PROJECT_NAME} PRIVATE include)
