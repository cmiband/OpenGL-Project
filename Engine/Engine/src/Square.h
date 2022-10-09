#pragma once

#include "VertexBuffer.h"
#include "Shader.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Renderer.h"
#include "Math/Vectors.h"

class Square
{
private:
	std::string m_color;
	VertexBuffer m_vb;
	IndexBuffer m_ib;
	Shader m_shader;
	float *positions;
	float m_size;

	void SetColor(Shader& sh) const;
	void ChangePositionsArray(const math::Vector2<float> &vec);
public:
	Square(const math::Vector2<float> &position, float size, const std::string& color, VertexArray& va);
	~Square() { delete[] positions; };

	void Draw(Renderer& r, VertexArray& va);
	void UnbindPropeties() const;
	void Move(const math::Vector2<float>& vector);
};

