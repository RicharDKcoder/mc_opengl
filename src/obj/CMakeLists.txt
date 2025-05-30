project(obj)

file(GLOB_RECURSE SOURCES 
    "*.cpp"
    "*.hpp" 
)

find_package(glm CONFIG REQUIRED)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE 
    engine
    glm::glm
)