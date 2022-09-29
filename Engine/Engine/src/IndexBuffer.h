#pragma once
class IndexBuffer
{
private:
	unsigned int m_graphicsId;
	unsigned int m_size;

public:
	IndexBuffer();
	IndexBuffer(unsigned int size, const void* data);
	~IndexBuffer();

	void AddData(unsigned int size, const void* data);
	void Bind() const;
	void Unbind() const;
	inline unsigned int getSize() const{ return m_size; };
};

