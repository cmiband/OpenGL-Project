#pragma once
class IndexBuffer
{
private:
	unsigned int m_graphicsId;
	unsigned int m_size;

public:
	IndexBuffer() : m_graphicsId(0), m_size(0) {};
	IndexBuffer(int size, const void* data);
	~IndexBuffer();

	void Bind() const;
	void Unbind() const;
	inline unsigned int getSize() const{ return m_size; };
};

