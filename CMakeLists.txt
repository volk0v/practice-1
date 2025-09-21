cmake_minimum_required(VERSION 3.15)
project(neatcounter LANGUAGES CXX)

include_directories(include)

set(CMAKE_CXX_VERSION 23)

add_executable(
    neatcounter 
    main.cpp 
    src/console_parser.cpp include/console_parser.h
    src/file_parser.cpp  include/file_parser.h
    include/errors.h
)
