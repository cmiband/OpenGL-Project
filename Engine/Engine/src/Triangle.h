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
	float* positions;
	
	void SetColor(Shader& sh) const;
	void ChangePositionsArray(const math::Vector2<float>& vec);
public:
	Triangle(const math::Vector2<float>& position, float size, const std::string& color, VertexArray& va);
	~Triangle(){};

	void Draw(Renderer& r, VertexArray& va);
	void UnbindPropeties() const;
	void Move(const math::Vector2<float>& vector);
};

