#include "VertexBuffer.h"

#include "Macros.h"

VertexBuffer::VertexBuffer(unsigned int size, const void* data) : m_graphicsId(0)
{
	glGenBuffers(1, &m_graphicsId);
	Bind();
	GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &m_graphicsId);
}

void VertexBuffer::Bind() const {
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_graphicsId));
}

void VertexBuffer::Unbind() const {
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
