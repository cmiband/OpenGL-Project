#include "Keyboard.h"

bool Keyboard::keyPressed(Window& window, int keyCode)
{
	int state = glfwGetKey(window.getGLFWwindow(), keyCode);

	if (state == GLFW_PRESS) {
		return true;
	}

	return false;
}
