#include "Triangle.h"
#include "Matrix.h"

Triangle::Triangle(const glm::vec2& position, float size, const math::Color4<float>& color) : m_size(size)
{
	m_positions = new float[6] {
		position.x, position.y,
		position.x + size, position.y,
		position.x + (size / 2), position.y + size
	};

	unsigned int indices[] = {
		0,1,2
	};

	m_vb.AddData(3*2*sizeof(float), m_positions);

	m_va.AddBuffer(2, false, 2 * sizeof(float));

	m_ib.AddData(3 * sizeof(unsigned int), &indices);
	m_shader.CreatePostInitialization("res/shaders/Basic.shader");
	SetColor(m_shader, color);

	Matrix matrix(640.0f, 640.0f);
	
	m_shader.SetUniformMatf("u_MVP", matrix.getMVP());
}

void Triangle::Draw(Renderer& r)
{
	r.Draw(m_va, m_ib, m_shader);
}

void Triangle::UnbindPropeties() const
{
	m_va.Unbind();
	m_vb.Unbind();
	m_ib.Unbind();
	m_shader.Unbind();
}

void Triangle::Move(const glm::vec2& vector)
{
	ChangePositionsArray(vector);
	m_vb.Bind();
	m_vb.AddData(3 * 2 * sizeof(float), m_positions);
}

void Triangle::SetPosition(const glm::vec2& vector)
{
	m_positions[0] = vector.x;
	m_positions[1] = vector.y;
	m_positions[2] = vector.x + m_size;
	m_positions[3] = vector.y;
	m_positions[4] = vector.x + (m_size/2);
	m_positions[5] = vector.y + m_size;

	m_vb.Bind();
	m_vb.AddData(3 * 2 * sizeof(float), m_positions);
}

void Triangle::ChangePositionsArray(const glm::vec2& vec)
{
	m_positions[0] = m_positions[0] + vec.x;
	m_positions[1] = m_positions[1] + vec.y;
	m_positions[2] = m_positions[2] + vec.x;
	m_positions[3] = m_positions[3] + vec.y;
	m_positions[4] = m_positions[4] + vec.x;
	m_positions[5] = m_positions[5] + vec.y;
}

void Triangle::SetColor(Shader& sh, const math::Color4<float>& c) const{
	sh.SetUniform4f("u_Color", c);
}


