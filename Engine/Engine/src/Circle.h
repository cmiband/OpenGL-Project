#pragma once

#include "VertexBuffer.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "Matrix.h"
#include "Renderer.h"
#include "glm.hpp"

class Circle
{
private:
	VertexArray m_va;
	VertexBuffer m_vb;
	IndexBuffer m_ib;
	Shader m_shader;
	float* m_positions;
	unsigned int* m_indices;
	float m_radius;

	int m_numberOfVertices;

	void SetColor(Shader& sh, const math::Color4<float>& c) const;
	void generateVerticesAndIndices(float r, float x, float y, float sides);
	void AddVectorToPositions(const glm::vec2& vec);
public:
	Circle(const glm::vec2& position, float radius, const math::Color4<float>& color);
	~Circle() { delete m_positions; };

	void Draw(Renderer& r);
	void UnbindPropeties() const;
	void Move(const glm::vec2& vector);
	void SetPosition(const glm::vec2& vector);
};

