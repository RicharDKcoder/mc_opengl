# CMakeList.txt: cmake_learn 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.10)

# 如果支持，请为 MSVC 编译器启用热重载。
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("main")

file(GLOB_RECURSE  SOURCES 
    "**.hpp" 
    "**.cpp"
)

find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(Stb REQUIRED)

# 将源代码添加到此项目的可执行文件。
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

target_include_directories(${PROJECT_NAME} PRIVATE 
	${Stb_INCLUDE_DIR}
)

target_link_libraries(${PROJECT_NAME} PRIVATE 
	glad::glad
	glfw
	glm::glm
	imgui::imgui
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
endif()