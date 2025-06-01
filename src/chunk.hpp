#pragma once
#include "vao.hpp"

class Chunk
{
public:
	Chunk();
	~Chunk();

	void build();
private:
float vertices[];
};