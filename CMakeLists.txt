cmake_minimum_required(VERSION 3.15)
project(neatcounter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(include)
add_subdirectory(src)

enable_testing()
add_subdirectory(tests)

add_executable(
    neatcounter
    main.cpp
    $<TARGET_OBJECTS:neatcounter_src>
    $<TARGET_OBJECTS:neatcounter_headers>
)
target_include_directories(${PROJECT_NAME} PRIVATE include)
