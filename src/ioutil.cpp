#include "ioutil.hpp"
#include <cerrno>
#include <iostream>
#include <fstream>
#include <string>

IOUtil::IOUtil()
{
}

IOUtil::~IOUtil()
{
}

std::string IOUtil::readFileContent(std::string filePath){
    std::ifstream in(filePath, std::ios::binary);
    if(!in.good()){
        std::cout << "file is not good" << std::endl;
        throw(errno);
    }
    if(in){
        std::string content;
        in.seekg(0, std::ios::end);
        content.resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&content[0], content.size());
        in.close();
        return content;
    }
    throw(errno);
}