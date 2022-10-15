#include "Renderer.h"

#include "Macros.h"

void Renderer::Draw(VertexArray& va, IndexBuffer& ib, Shader& shader) const{
	va.Bind();
	shader.Bind();

	GLCall(glDrawElements(GL_TRIANGLES, ib.getSize(), GL_UNSIGNED_INT, nullptr));
}

void Renderer::Clear() const {
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
}