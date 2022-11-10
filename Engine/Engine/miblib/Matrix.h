#pragma once
#include "glm.hpp"

class Matrix
{
private:
	glm::mat4 m_MVP;
public:
	Matrix(float width, float heigth);
	~Matrix() {};

	inline glm::mat4 getMVP() const { return m_MVP; };
};


