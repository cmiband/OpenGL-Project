#pragma once

#define SCREEN_WIDTH 640.0f
#define SCREEN_HEIGTH 640.0f

class VertexArray
{
private:
	unsigned int m_graphicsId;

public:
	VertexArray();
	~VertexArray();

	void AddBuffer(int size, bool normalized, unsigned int stride);
	void Bind() const;
	void Unbind() const;
};

