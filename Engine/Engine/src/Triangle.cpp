#include "Triangle.h"

Triangle::Triangle(const math::Vector2<float>& position, float size, const std::string& color, VertexArray& va) : m_color(color)
{
	positions = new float[6] {
		position.x, position.y,
		position.x + size, position.y,
		position.x + (size / 2), position.y + size
	};

	unsigned int indices[] = {
		0,1,2
	};

	m_vb.AddData(3*2*sizeof(float), positions);

	va.AddBuffer(2, false, 2 * sizeof(float));

	m_ib.AddData(3 * sizeof(unsigned int), &indices);
	m_shader.CreatePostInitialization("res/shaders/Basic.shader");
	SetColor(m_shader);
}

void Triangle::Draw(Renderer& r, VertexArray& va)
{
	va.Bind();
	m_ib.Bind();
	m_shader.Bind();

	r.Draw(va, m_ib, m_shader);
}

void Triangle::UnbindPropeties() const
{
	m_vb.Unbind();
	m_ib.Unbind();
	m_shader.Unbind();
}

void Triangle::Move(const math::Vector2<float>& vector)
{
	ChangePositionsArray(vector);
	m_vb.Bind();
	m_vb.AddData(3 * 2 * sizeof(float), positions);
}

void Triangle::ChangePositionsArray(const math::Vector2<float>& vec)
{
	positions[0] = positions[0] + vec.x;
	positions[1] = positions[1] + vec.y;
	positions[2] = positions[2] + vec.x;
	positions[3] = positions[3] + vec.y;
	positions[4] = positions[4] + vec.x;
	positions[5] = positions[5] + vec.y;
}

void Triangle::SetColor(Shader& sh) const{
	if (m_color == "red") {
		sh.SetUniform4f("u_Color", 1.0f, 0.0f, 0.0f, 1.0f);
	}
	else {
		std::cout << "Given color is not supported" << std::endl;
	}
}


