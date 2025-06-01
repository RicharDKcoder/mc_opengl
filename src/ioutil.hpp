#pragma once

#include <string>

class IOUtil
{
public:
    IOUtil();
    IOUtil(IOUtil &&) = default;
    IOUtil(const IOUtil &) = default;
    IOUtil &operator=(IOUtil &&) = default;
    IOUtil &operator=(const IOUtil &) = default;
    ~IOUtil();

    static std::string readFileContent(std::string filePath);
private:
    
};