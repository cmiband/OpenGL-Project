#pragma once

#include "VertexBuffer.h"
#include "VertexArray.h";
#include "IndexBuffer.h"
#include "Shader.h"
#include "Renderer.h"
#include "Math/Vectors.h"
#include "glm.hpp"

class Line
{
private:
	VertexArray m_va;
	VertexBuffer m_vb;
	IndexBuffer m_ib;
	Shader m_shader;
	float* m_positions;
	float m_size;

	void SetColor(Shader& sh, const math::Color4<float>& c) const;
	void ChangePositionsArray(const glm::vec2& vec);
public:
	Line(const glm::vec2& start,const glm::vec2& end, const math::Color4<float>& color);
	~Line(){};

	void Draw(Renderer& r);
	void UnbindPropeties() const;
	void Move(const glm::vec2& vector);
	void SetPosition(const glm::vec2& start, const glm::vec2& end);

	inline glm::vec2 getPosition() const { return { m_positions[0],m_positions[1] }; };
};

