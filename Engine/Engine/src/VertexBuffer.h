#pragma once

class VertexBuffer
{
private:
	unsigned int graphicsId;

public:
	VertexBuffer(unsigned int size, const void* data);
	~VertexBuffer();

	void Bind() const;
	void Unbind() const;
};

