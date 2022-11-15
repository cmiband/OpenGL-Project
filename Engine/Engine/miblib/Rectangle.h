#pragma once

#include "VertexBuffer.h"
#include "Shader.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Renderer.h"
#include "Math/Vectors.h"
#include "glm.hpp"
#include <vector>
#include <utility>

class Rectangle
{
private:
	VertexArray m_va;
	VertexBuffer m_vb;
	IndexBuffer m_ib;
	Shader m_shader;
	float *m_positions;
	float m_width;
	float m_height;
	std::vector<std::pair<float, float>> m_corners;

	void SetColor(Shader& sh, const math::Color4<float>& c) const;
	void AddVectorToPositions(const glm::vec2& vec);
	void SetCorners(std::vector<std::pair<float, float>>& corners);
public:
	Rectangle(const glm::vec2& position, float width, float heigth, const math::Color4<float>& color);
	~Rectangle() { delete[] m_positions; };

	void Draw(Renderer& r);
	void UnbindPropeties() const;
	void Move(const glm::vec2& vector);
	void SetPosition(const glm::vec2& vector);

	inline glm::vec2 getPosition() const { return { m_positions[0],m_positions[1] }; };
};

