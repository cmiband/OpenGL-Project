#include "Triangle.h"

Triangle::Triangle(float posX, float posY, float size, const std::string& color, VertexArray& va) : m_color(color)
{
	float positions[] = {
		posX, posY,
		posX + size, posY,
		posX + (size / 2), posY + size
	};

	unsigned int indices[] = {
		0,1,2
	};

	m_vb.AddData(3*2*sizeof(float), &positions);

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

void Triangle::SetColor(Shader& sh) const{
	if (m_color == "red") {
		sh.SetUniform4f("u_Color", 1.0f, 0.0f, 0.0f, 1.0f);
	}
	else {
		std::cout << "Given color is not supported" << std::endl;
	}
}

