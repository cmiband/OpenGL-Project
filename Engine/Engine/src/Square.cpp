#include "Square.h"

Square::Square(float posX, float posY, float size, const std::string& color, VertexArray& va) : m_color(color)
{
	float positions[8] = {
		posX, posY,
		posX + size,posY,
		posX + size,posY + size,
		posX, posY+size
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

void Square::SetColor(Shader& sh) const
{
	if (m_color == "red") {
		sh.SetUniform4f("u_Color", 1.0f, 0.0f, 0.0f, 1.0f);
	}
	else {
		std::cout << "Given color is not supported" << std::endl;
	}
}
