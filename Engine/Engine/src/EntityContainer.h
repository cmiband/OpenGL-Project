#pragma once
#include "VertexArray.h"
#include <vector>

class EntityContainer
{
private:
	std::vector<VertexArray> m_entities;

public:
	EntityContainer();
	~EntityContainer() {};

	void Add(VertexArray& va);
};

