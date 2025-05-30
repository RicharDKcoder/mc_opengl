project(engine)

file(GLOB_RECURSE SOURCES 
    "*.cpp"
    "*.hpp" 
)
find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE 
    glfw
    glad::glad
)