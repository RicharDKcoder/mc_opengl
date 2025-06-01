#include <glad/glad.h>

class VAO
{
public:
	VAO();
	~VAO();

	// void build(float* vertices, int verticeSize, unsigned int* indices, int indiceSize);
	virtual void build() = 0;
	GLuint getId();
protected:
	GLuint id;
private:
};