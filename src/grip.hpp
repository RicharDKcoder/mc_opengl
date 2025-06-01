#pragma once
#include "vao.hpp"

class Grip: public VAO
{
public:
    Grip();
    Grip(Grip &&) = default;
    Grip(const Grip &) = default;
    Grip &operator=(Grip &&) = default;
    Grip &operator=(const Grip &) = default;
    ~Grip();

    Grip(int width, int height);
    void build();
private:
    int width, height;
};