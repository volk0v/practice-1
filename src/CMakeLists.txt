file(GLOB ${PROJECT_NAME}_src_files ./*.cpp)

add_library(${PROJECT_NAME}_src OBJECT
    ${${PROJECT_NAME}_src_files}
)
target_include_directories(${PROJECT_NAME}_src PRIVATE ../include)
