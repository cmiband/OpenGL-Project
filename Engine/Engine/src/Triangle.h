#pragma once

#include "VertexBuffer.h"
#include "Shader.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Renderer.h"

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
	inline VertexBuffer getVB() const { return m_vb; };
	inline IndexBuffer getIB() const { return m_ib; };
	inline Shader getShader() const { return m_shader; };
};

