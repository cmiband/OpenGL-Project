#pragma once

class VertexBuffer
{
private:
	unsigned int m_graphicsId;

public:
	VertexBuffer() : m_graphicsId(0) {};
	VertexBuffer(unsigned int size, const void* data);
	~VertexBuffer();

	void Bind() const;
	void Unbind() const;
};

