#pragma once

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "Triangle.h"

class Renderer
{
public:
	Renderer() {};
	~Renderer() {};

	void Draw(VertexArray& va, IndexBuffer& ib, Shader& shader) const;
	void Draw(Triangle& triangle, VertexArray& va) const;
	void Clear() const;
};

