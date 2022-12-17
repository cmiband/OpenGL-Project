#pragma once

#include "VertexBuffer.h"
#include "Shader.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Renderer.h"
#include "Math/Vectors.h"
#include "glm.hpp"

#include <iostream>

class Triangle
{
private:
	VertexArray m_va;
	VertexBuffer m_vb;
	IndexBuffer m_ib;
	Shader m_shader;
	float* m_positions;
	float m_size;
	
	void SetColor(Shader& sh, const math::Color4<float>& vec) const;
	void ChangePositionsArray(const glm::vec2& c);
public:
	Triangle(const glm::vec2& position, float size, const math::Color4<float>& color);
	~Triangle() { delete[] m_positions; };

	void Draw(Renderer& r);
	void UnbindPropeties() const;
	void Move(const glm::vec2& vector);
	void SetPosition(const glm::vec2& vector);

	inline glm::vec2 GetPosition() const { return { m_positions[0],m_positions[1] }; };
};

