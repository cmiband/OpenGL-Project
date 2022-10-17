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
	VertexArray m_va;
	VertexBuffer m_vb;
	IndexBuffer m_ib;
	Shader m_shader;
	float *m_positions;
	float m_size;

	void SetColor(Shader& sh, const math::Color4<float>& c) const;
	void ChangePositionsArray(const math::Vector2<float> &vec);
public:
	Square(const math::Vector2<float> &position, float size, const math::Color4<float>& color);
	~Square() { delete[] m_positions; };

	void Draw(Renderer& r);
	void UnbindPropeties() const;
	void Move(const math::Vector2<float>& vector);
	void SetPosition(const math::Vector2<float>& vector);
};

