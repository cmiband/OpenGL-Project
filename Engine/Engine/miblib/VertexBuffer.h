#pragma once

class VertexBuffer
{
private:
	unsigned int m_graphicsId;

public:
	VertexBuffer();
	VertexBuffer(unsigned int size, const void* data);
	~VertexBuffer();

	void AddData(unsigned int size, const void* data) const;
	void RemoveData() const;
	void Bind() const;
	void Unbind() const;
};

