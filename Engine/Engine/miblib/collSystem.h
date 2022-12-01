#pragma once
#include <glm.hpp>
#include <vector>

class collSystem
{
public:
	static bool containsOnYAxis(std::vector<glm::vec2> objectOneCorners, std::vector<glm::vec2> objectTwoCorners);
	static bool containsOnXAxis(std::vector<glm::vec2> objectOneCorners, std::vector<glm::vec2> objectTwoCorners);
};

