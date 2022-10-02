#pragma once

#include "VertexBuffer.h"
#include "Shader.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Renderer.h"

class Square
{
private:
	std::string m_color;
	VertexBuffer m_vb;
	IndexBuffer m_ib;
	Shader m_shader;

	void SetColor(Shader& sh) const;
public:
	Square(float posX, float posY, float size, const std::string& color, VertexArray& va);
	~Square() {};

	void Draw(Renderer& r, VertexArray& va);
	void UnbindPropeties() const;
};

