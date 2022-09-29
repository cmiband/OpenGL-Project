#include "VertexBuffer.h"

#include "Macros.h"

VertexBuffer::VertexBuffer() : m_graphicsId(0)
{
	GLCall(glGenBuffers(1, &m_graphicsId););
	Bind();
}

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

void VertexBuffer::AddData(unsigned int size, const void* data) const
{
	GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

void VertexBuffer::Bind() const {
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_graphicsId));
}

void VertexBuffer::Unbind() const {
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
