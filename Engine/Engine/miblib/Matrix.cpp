#include "Matrix.h"
#include "glm/gtc/matrix_transform.hpp"

Matrix::Matrix(float width, float heigth)
{
	glm::mat4 proj = glm::ortho(0.0f, width, 0.0f, heigth, -1.0f, 1.0f);
	glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));

	m_MVP = proj * view;
}
