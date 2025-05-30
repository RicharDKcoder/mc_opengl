project(util)

file(GLOB_RECURSE SOURCES 
    "*.cpp"
    "*.hpp" 
)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

# test
add_executable(Test_IOUtil Test_IOUtil.cpp)
target_link_libraries(Test_IOUtil util)
add_test(NAME IOUtil_FILE_READ_TEST COMMAND Test_IOUtil)