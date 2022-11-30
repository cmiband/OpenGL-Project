#pragma once
#include <utility>

class collSystem
{
public:
	bool containsOnYAxis(std::pair<float, float> object1, std::pair<float, float> object2);
	bool containsOnXAxis(std::pair<float, float> object1, std::pair<float, float> object2);
};

