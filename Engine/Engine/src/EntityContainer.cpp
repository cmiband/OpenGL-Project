#include "EntityContainer.h"

EntityContainer::EntityContainer()
{
}

void EntityContainer::Add(VertexArray& va)
{
	m_entities.push_back(va);
}

