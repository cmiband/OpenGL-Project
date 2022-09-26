#include "Renderer.h"

#include "Macros.h"

void Renderer::Draw(VertexArray& va, IndexBuffer& ib, Shader& shader) const{
	va.Bind();
	ib.Bind();
	shader.Bind();

	GLCall(glDrawElements(GL_TRIANGLES, ib.getSize(), GL_UNSIGNED_INT, nullptr));
}

void Renderer::Draw(Triangle& triangle, VertexArray& va) const
{
	va.Bind();
	triangle.getVB().Bind();
	triangle.getShader().Bind();
	triangle.getIB().Bind();
	
	GLCall(glDrawElements(GL_TRIANGLES, triangle.getIB().getSize(), GL_UNSIGNED_INT, nullptr));
}

void Renderer::Clear() const {
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
}