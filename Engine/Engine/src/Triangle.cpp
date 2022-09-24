#include "Triangle.h"

Triangle::Triangle(float posX, float posY, float size, const std::string& color, VertexArray& va) : m_color(color)
{
	float positions[] = {
		posX, posY,
		posX+size, posY,
		posX+(size/2), posY+size
	};

	unsigned int indices[] = {
		0,1,2
	};

	m_vb = new VertexBuffer(6, &positions);

	va.AddBuffer(2, false, 2 * sizeof(float));

	m_ib = new IndexBuffer(3 * sizeof(unsigned int), &indices);

	m_shader = new Shader("res/shaders/Basic.shader");
	SetColor();
}

Triangle::~Triangle()
{
	delete m_shader;
	delete m_ib;
	delete m_vb;
}

void Triangle::Draw(Renderer& r, VertexArray& va) const
{

}

inline IndexBuffer* Triangle::getIndexBuffer() const
{
	return m_ib;
}

inline Shader* Triangle::getShader() const
{
	return m_shader;
}

void Triangle::SetColor() const
{
	if (m_color == "red") {
		m_shader->SetUniform4f("u_Color", 1.0f, 0.0f, 0.0f, 1.0f);
	}
	else {
		std::cout << "Given color is not supported" << std::endl;
	}
}
