#pragma once

class VertexArray
{
private:
	unsigned int graphicsId;
	int count;

public:
	VertexArray(int size, bool normalized, unsigned int stride);
	~VertexArray();

	void AddBuffer();
	void Bind() const;
	void Unbind() const;
	void Enable() const;
};

