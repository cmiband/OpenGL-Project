#include "Square.h"

Square::Square(const math::Vector2<float>& position, float size, const std::string& color, VertexArray& va) : m_color(color), m_size(size)
{
	positions = new float[8] {
		position.x, position.y,
		position.x+size, position.y,
		position.x + size,position.y + size,
		position.x, position.y+size
	};

	unsigned int indices[6] = {
		0,1,2,
		2,3,0
	};

	m_vb.AddData(4 * 2 * sizeof(float), positions);
	
	va.AddBuffer(2, false, 2 * sizeof(float));

	m_ib.AddData(6 * sizeof(unsigned int), indices);
	m_shader.CreatePostInitialization("res/shaders/Basic.shader");
	SetColor(m_shader);
}

void Square::Draw(Renderer& r, VertexArray& va)
{
	va.Bind();
	m_ib.Bind();
	m_shader.Bind();

	r.Draw(va, m_ib, m_shader);
}

void Square::UnbindPropeties() const
{
	m_vb.Unbind();
	m_ib.Unbind();
	m_shader.Unbind();
}

void Square::Move(const math::Vector2<float>& vector)
{
	ChangePositionsArray(vector);
	m_vb.Bind();
	m_vb.AddData(4 * 2 * sizeof(float), positions);
}

void Square::ChangePositionsArray(const math::Vector2<float>& vec)
{
	positions[0] = positions[0] + vec.x;
	positions[1] = positions[1] + vec.y;
	positions[2] = positions[2] + vec.x;
	positions[3] = positions[3] + vec.y;
	positions[4] = positions[4] + vec.x;
	positions[5] = positions[5] + vec.y;
	positions[6] = positions[6] + vec.x;
	positions[7] = positions[7] + vec.y;
}

void Square::SetColor(Shader& sh) const
{
	if (m_color == "red") {
		sh.SetUniform4f("u_Color", 1.0f, 0.0f, 0.0f, 1.0f);
	}
	else if (m_color == "green") {
		sh.SetUniform4f("u_Color", 0.0f, 1.0f, 0.0f, 1.0f);
	}
	else {
		std::cout << "Given color is not supported" << std::endl;
	}
}
