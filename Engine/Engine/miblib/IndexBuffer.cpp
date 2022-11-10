#include "IndexBuffer.h"

#include "Macros.h"

IndexBuffer::IndexBuffer() : m_graphicsId(0), m_size(0)
{
	GLCall(glGenBuffers(1, &m_graphicsId));
	Bind();
}

IndexBuffer::IndexBuffer(unsigned int size, const void* data) : m_graphicsId(0), m_size(size)
{
	GLCall(glGenBuffers(1, &m_graphicsId));
	Bind();
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer()
{
	GLCall(glDeleteBuffers(1, &m_graphicsId));
}

void IndexBuffer::AddData(unsigned int size, const void* data)
{
	m_size = size;
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

void IndexBuffer::RemoveData()
{
	m_size = 0;
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, 0, 0, GL_STATIC_DRAW));
}

void IndexBuffer::Bind() const
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_graphicsId));
}

void IndexBuffer::Unbind() const
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}
