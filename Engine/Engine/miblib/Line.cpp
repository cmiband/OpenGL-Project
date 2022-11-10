#include "Line.h"
#include "Matrix.h"

Line::Line(const glm::vec2& start, const glm::vec2& end, const math::Color4<float>& color)
{
	m_positions = new float[4]{
		start.x, start.y,
		end.x, end.y
	};

	unsigned int indices[] = {
		0,1
	};

	m_vb.AddData(2 * 2 * sizeof(float), m_positions);

	m_va.AddBuffer(2, false, 2 * sizeof(float));

	m_ib.AddData(2 * sizeof(unsigned int), indices);
	m_shader.CreatePostInitialization("res/shaders/Basic.shader");
	SetColor(m_shader, color);

	Matrix matrix(640.0f, 640.0f);

	m_shader.SetUniformMatf("u_MVP", matrix.getMVP());
}

void Line::Draw(Renderer& r)
{
	r.DrawLine(m_va, m_ib, m_shader);
}

void Line::UnbindPropeties() const
{
	m_va.Unbind();
	m_vb.Unbind();
	m_ib.Unbind();
	m_shader.Unbind();
}

void Line::Move(const glm::vec2& vector)
{
	ChangePositionsArray(vector);
	m_vb.Bind();
	m_vb.AddData(2 * 2 * sizeof(float), m_positions);
}

void Line::SetPosition(const glm::vec2& start, const glm::vec2& end)
{
	m_positions[0] = start.x;
	m_positions[1] = start.y;
	m_positions[2] = end.x;
	m_positions[3] = end.y;

	m_vb.Bind();
	m_vb.AddData(2 * 2 * sizeof(float), m_positions);
}

void Line::ChangePositionsArray(const glm::vec2& vec)
{
	m_positions[0] = m_positions[0] + vec.x;
	m_positions[1] = m_positions[1] + vec.y;
	m_positions[2] = m_positions[2] + vec.x;
	m_positions[3] = m_positions[3] + vec.y;
}

void Line::SetColor(Shader& sh, const math::Color4<float>& c) const
{
	sh.SetUniform4f("u_Color", c);
}

