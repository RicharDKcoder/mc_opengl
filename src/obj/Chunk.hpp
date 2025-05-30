#pragma once

#include "Render.hpp"

class Chunk : public Render
{
public:
    Chunk();
    Chunk(Chunk &&) = default;
    Chunk(const Chunk &) = default;
    Chunk &operator=(Chunk &&) = default;
    Chunk &operator=(const Chunk &) = default;
    ~Chunk();

protected:
    void initData();
    void initShader();
    void render();
};