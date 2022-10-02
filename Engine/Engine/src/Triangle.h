#pragma once

#include "VertexBuffer.h"
#include "Shader.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Renderer.h"
#include "Math/Vectors.h"

#include <iostream>

class Triangle
{
private:
	std::string m_color;
	VertexBuffer m_vb;
	IndexBuffer m_ib;
	Shader m_shader;
	
	void SetColor(Shader& sh) const;
public:
	Triangle(float posX, float posY, float size, const std::string& color, VertexArray& va);
	~Triangle(){};

	void Draw(Renderer& r, VertexArray& va);
	void UnbindPropeties() const;
};

