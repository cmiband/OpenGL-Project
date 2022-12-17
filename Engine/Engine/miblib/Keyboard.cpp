#include "Keyboard.h"

bool Keyboard::KeyPressed(Window& window, int keyCode)
{
	int state = glfwGetKey(window.getGLFWwindow(), keyCode);

	if (state == GLFW_PRESS) {
		return true;
	}

	return false;
}
