#include "Circle.h"

#include <corecrt_math_defines.h>
#include "Macros.h"

void Circle::SetColor(Shader& sh, const math::Color4<float>& c) const {
	sh.SetUniform4f("u_Color", c);
};

void Circle::GenerateVertices(float r, float x, float y, float sides)
{
	int numberOfVertices = sides + 2;
	m_numberOfVertices = numberOfVertices;
	float doublePi = 2.0f * M_PI;

	float* circleVerticesX = new float[numberOfVertices];
	float* circleVerticesY = new float[numberOfVertices];

	circleVerticesX[0] = x;
	circleVerticesY[0] = y;

	for (int i = 1; i < numberOfVertices; i++) {
		circleVerticesX[i] = x + (r * cos(i * doublePi / sides));
		circleVerticesY[i] = y + (r * sin(i * doublePi / sides));
	}

	m_positions = new float[numberOfVertices * 2];
	for (int i = 0; i < numberOfVertices; i++) {
		m_positions[i * 2] = circleVerticesX[i];
		m_positions[(i * 2) + 1] = circleVerticesY[i];
	}

	delete[] circleVerticesX;
	delete[] circleVerticesY;
}

void Circle::GenerateIndices(int numberOfVertices)
{
	m_indices = new unsigned int[3 * numberOfVertices];
	int c = 0;
	int i = 0;
	while (i < numberOfVertices * 3) {
		if (i % 3 == 0) {
			m_indices[i] = 0;
			c++;
			if (c > 360) {
				c = 1;
			}
		}
		else if (i % 3 == 1) {
			m_indices[i] = c;
			c++;
			if (c > 360) {
				c = 1;
			}
		}
		else {
			m_indices[i] = c;
			c--;
		}
		i++;
	}
}

Circle::Circle(const glm::vec2& position, float radius, const math::Color4<float>& color) : m_radius(radius), m_numberOfVertices(0)
{
	GenerateVertices(radius, position.x, position.y, 360);
	GenerateIndices(m_numberOfVertices);

	m_vb.AddData(m_numberOfVertices * 2 * sizeof(float), m_positions);

	m_va.AddBuffer(2, false, 2 * sizeof(float));

	m_ib.AddData(m_numberOfVertices * 3 * sizeof(unsigned int), m_indices);
	m_shader.CreatePostInitialization("res/shaders/Basic.shader");
	SetColor(m_shader, color);

	Matrix m(SCREEN_WIDTH, SCREEN_HEIGHT);
	m_shader.SetUniformMatf("u_MVP", m.getMVP());
}

void Circle::Draw(Renderer& r)
{
	r.Draw(m_va, m_ib, m_shader);
}

void Circle::UnbindPropeties() const
{
	m_vb.Unbind();
	m_va.Unbind();
	m_ib.Unbind();
	m_shader.Unbind();
}

void Circle::AddVectorToPositions(const glm::vec2& vec)
{
	for (int i = 0; i < m_numberOfVertices*2; i++) {
		if (i % 2 == 0) m_positions[i] += vec.x;
		else m_positions[i] += vec.y;
	}
}

void Circle::Move(const glm::vec2& vector)
{
	AddVectorToPositions(vector);
	m_vb.Bind();
	m_vb.RemoveData();
	m_vb.AddData(m_numberOfVertices * 2 * sizeof(float), m_positions);
}

void Circle::SetPosition(const glm::vec2& vector)
{
	GenerateVertices(m_radius, vector.x, vector.y, 360);

	m_vb.Bind();
	m_vb.RemoveData();
	m_vb.AddData(m_numberOfVertices * 2 * sizeof(float), m_positions);
}
