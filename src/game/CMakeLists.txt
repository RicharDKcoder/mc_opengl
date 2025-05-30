cmake_minimum_required(VERSION 3.10.0)
project(main VERSION 0.1.0 LANGUAGES C CXX)

# 自动扫描src/下所有.cpp文件
file(GLOB_RECURSE SOURCES 
    "*.cpp"
    "*.hpp" 
)

# find_package(glfw3 CONFIG REQUIRED)
# find_package(glad CONFIG REQUIRED)
# find_package(glm CONFIG REQUIRED)
find_package(Stb REQUIRED)
find_package(imgui CONFIG REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCES})

message("CMAKE_SOURCE_DIR" ${CMAKE_SOURCE_DIR})
message("CMAKE_BINARY_DIR" ${CMAKE_BINARY_DIR})
add_custom_target(copy_resources ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/resources
        ${CMAKE_BINARY_DIR}/resources
        COMMENT "Copying resources into binary directory"
)
add_dependencies(${PROJECT_NAME} copy_resources)

# 包含目录
target_include_directories(${PROJECT_NAME} PRIVATE
    ${Stb_INCLUDE_DIR}
)

target_link_libraries(${PROJECT_NAME} PRIVATE 
    # glfw
    # glad::glad
    obj
    imgui::imgui
)

