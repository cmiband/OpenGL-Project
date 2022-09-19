#pragma once
class IndexBuffer
{
private:
	unsigned int m_graphicsId;

public:
	IndexBuffer(int size, const void* data);
	~IndexBuffer();

	void Bind() const;
	void Unbind() const;
};

