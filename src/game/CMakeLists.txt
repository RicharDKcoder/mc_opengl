cmake_minimum_required(VERSION 3.10.0)
project(main VERSION 0.1.0 LANGUAGES C CXX)

# 自动扫描src/下所有.cpp文件
file(GLOB_RECURSE SOURCES 
    "*.cpp"
    "*.hpp" 
)

# find_package(glfw3 CONFIG REQUIRED)
# find_package(glad CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(Stb REQUIRED)
find_package(imgui CONFIG REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCES})

# 包含目录
target_include_directories(${PROJECT_NAME} PRIVATE
    ${Stb_INCLUDE_DIR}
)

target_link_libraries(${PROJECT_NAME} PRIVATE 
    # glfw
    # glad::glad
    engine
    glm::glm
    imgui::imgui
)

