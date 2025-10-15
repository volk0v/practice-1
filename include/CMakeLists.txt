file(GLOB ${PROJECT_NAME}_headers_files ./*.h)

add_library(${PROJECT_NAME}_headers OBJECT
    ${${PROJECT_NAME}_headers_files}
)
