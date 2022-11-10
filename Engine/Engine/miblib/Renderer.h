#pragma once

#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "Window.h"

class Renderer
{
public:
	Renderer() {};
	~Renderer() {};

	void Draw(VertexArray& va, IndexBuffer& ib, Shader& shader) const;
	void DrawLine(VertexArray& va, IndexBuffer& ib, Shader& shader) const;
	void Swap(GLFWwindow* w);
	void Swap(Window& w);
	void Clear() const;
};

