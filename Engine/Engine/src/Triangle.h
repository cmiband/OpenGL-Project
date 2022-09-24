#pragma once
#include "VertexBuffer.h"
#include "Shader.h"

class Triangle
{
private:
	int m_color;
	VertexBuffer *m_vb;
	Shader *m_shader;
	
public:
	Triangle();
	~Triangle();

	void Draw();
	void SetColor();
};

