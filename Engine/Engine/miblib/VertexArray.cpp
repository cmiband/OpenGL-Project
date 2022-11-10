#include "VertexArray.h"

#include "Macros.h"

VertexArray::VertexArray() : m_graphicsId(0) {
	GLCall(glGenVertexArrays(1, &m_graphicsId));
	Bind();
}

VertexArray::~VertexArray() {
	GLCall(glDeleteVertexArrays(1, &m_graphicsId));
}

void VertexArray::AddBuffer(int size, bool normalized, unsigned int stride) {
	GLCall(glVertexAttribPointer(0, size, GL_FLOAT, normalized, stride, (const void*)0));
	GLCall(glEnableVertexAttribArray(0));
}

void VertexArray::Bind() const{
	GLCall(glBindVertexArray(m_graphicsId));
}

void VertexArray::Unbind() const{
	GLCall(glBindVertexArray(0));
}