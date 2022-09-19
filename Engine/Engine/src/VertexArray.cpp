#include "VertexArray.h"

#include "Macros.h"

VertexArray::VertexArray() : m_count(0), m_graphicsId(0) {
	GLCall(glGenVertexArrays(1, &m_graphicsId));
	Bind();
}

VertexArray::~VertexArray() {
	GLCall(glDeleteVertexArrays(1, &m_graphicsId));
}

void VertexArray::AddBuffer(int size, bool normalized, unsigned int stride) {
	GLCall(glVertexAttribPointer(m_count, size, GL_FLOAT, normalized, stride, (const void*)(m_count*size*sizeof(float))));
	GLCall(glEnableVertexAttribArray(m_count));
	m_count++;
}

void VertexArray::Bind() const{
	GLCall(glBindVertexArray(m_graphicsId));
}

void VertexArray::Unbind() const{
	GLCall(glBindVertexArray(0));
}