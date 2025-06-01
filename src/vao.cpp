#include "vao.hpp"

VAO::VAO()
{
}

VAO::~VAO()
{
}

// void VAO::build(float* vertices, int verticeSize, unsigned int *indices, int indiceSize)
// {

// 	float offset[] = {
// 		-2.0,0.0,0.0,
// 		0.0,0.0,0.0,
// 		2.0,0.0,0.0,
// 	};

// 	GLuint VBO, VAO, EBO;
// 	glGenVertexArrays(1, &VAO);
// 	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
// 	glBindVertexArray(VAO);
// 		// vbo
// 		glGenBuffers(1, &VBO);
// 		// 第一个数据缓存定义完成
// 		glBindBuffer(GL_ARRAY_BUFFER, VBO);
// 		glBufferData(GL_ARRAY_BUFFER, verticeSize, vertices, GL_STATIC_DRAW);
// 		//ebo
// 		if (indiceSize > 0)
// 		{
// 			glGenBuffers(1, &EBO);
// 			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
// 			glBufferData(GL_ELEMENT_ARRAY_BUFFER, indiceSize, indices, GL_STATIC_DRAW);
// 		}

// 		// position attribute
// 		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
// 		glEnableVertexAttribArray(0);
// 		// texture attribute
// 		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
// 		glEnableVertexAttribArray(1);
// 		glBindBuffer(GL_ARRAY_BUFFER, 0);


// 		GLuint VBO_Instance;
// 		glGenBuffers(1, &VBO_Instance);
// 		// 第一个数据缓存定义完成
// 		glBindBuffer(GL_ARRAY_BUFFER, VBO_Instance);
// 		glBufferData(GL_ARRAY_BUFFER, sizeof(offset), offset, GL_STATIC_DRAW);
// 		// offset attribute
// 		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
// 		glEnableVertexAttribArray(2);
// 		glBindBuffer(GL_ARRAY_BUFFER, 0);
// 		glVertexAttribDivisor(2, 1); // tell OpenGL this is an instanced vertex attribute.
// 	glBindVertexArray(0);
// 	this->id = VAO;
// }


GLuint VAO::getId() {
	return this->id;
}


