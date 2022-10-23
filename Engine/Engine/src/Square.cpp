#include "Square.h"

Square::Square(const glm::vec2& position, float size, const math::Color4<float>& color) : m_size(size)
{
	m_positions = new float[8] {
		position.x, position.y,
		position.x+size, position.y,
		position.x + size,position.y + size,
		position.x, position.y+size
	};

	unsigned int indices[6] = {
		0,1,2,
		2,3,0
	};

	m_vb.AddData(4 * 2 * sizeof(float), m_positions);
	
	m_va.AddBuffer(2, false, 2 * sizeof(float));

	m_ib.AddData(6 * sizeof(unsigned int), indices);
	m_shader.CreatePostInitialization("res/shaders/Basic.shader");
	SetColor(m_shader, color);
}

void Square::Draw(Renderer& r)
{
	r.Draw(m_va, m_ib, m_shader);
}

void Square::UnbindPropeties() const
{
	m_va.Unbind();
	m_vb.Unbind();
	m_ib.Unbind();
	m_shader.Unbind();
}

void Square::Move(const glm::vec2& vector)
{
	ChangePositionsArray(vector);
	m_vb.Bind();
	m_vb.AddData(4 * 2 * sizeof(float), m_positions);
}

void Square::SetPosition(const glm::vec2& vector)
{
	m_positions[0] = vector.x;
	m_positions[1] = vector.y;
	m_positions[2] = vector.x + m_size;
	m_positions[3] = vector.y;
	m_positions[4] = vector.x + m_size;
	m_positions[5] = vector.y + m_size;
	m_positions[6] = vector.x;
	m_positions[7] = vector.y + m_size;

	m_vb.Bind();
	m_vb.AddData(4 * 2 * sizeof(float), m_positions);
}

void Square::ChangePositionsArray(const glm::vec2& vec)
{
	m_positions[0] = m_positions[0] + vec.x;
	m_positions[1] = m_positions[1] + vec.y;
	m_positions[2] = m_positions[2] + vec.x;
	m_positions[3] = m_positions[3] + vec.y;
	m_positions[4] = m_positions[4] + vec.x;
	m_positions[5] = m_positions[5] + vec.y;
	m_positions[6] = m_positions[6] + vec.x;
	m_positions[7] = m_positions[7] + vec.y;
}

void Square::SetColor(Shader& sh,const math::Color4<float>& c) const
{
	sh.SetUniform4f("u_Color", c);
}
