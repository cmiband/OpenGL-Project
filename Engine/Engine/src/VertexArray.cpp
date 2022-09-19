#include "VertexArray.h"

#include "Macros.h"

VertexArray::VertexArray(int size, bool normalized, unsigned int stride) {
	count = 0;

	GLCall(glGenVertexArrays(1, &graphicsId));
	Bind();
}

VertexArray::~VertexArray() {
	GLCall(glDeleteVertexArrays(1, &graphicsId));
}

void VertexArray::AddBuffer() {

}

void VertexArray::Bind() const{
	GLCall(glBindVertexArray(graphicsId));
}

void VertexArray::Unbind() const{
	GLCall(glBindVertexArray(0));
}

void VertexArray::Enable() const {

}