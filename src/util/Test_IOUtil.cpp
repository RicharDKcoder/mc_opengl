#include "IOUtil.hpp"
#include <iostream>
#include <string>
#include <filesystem>

int main(int argc, const char** argv) {
    std::cout << "this is main" << std::endl;
    std::cout << "cur path:" << std::filesystem::current_path() << std::endl;
    std::cout << "exists:" << std::filesystem::exists("../../resources/shader/chunk.vs") << std::endl;
    std::string content = IOUtil::readFile("../../resources/shader/chunk.frag");
    std::cout << content << std::endl;
    return 0;
}