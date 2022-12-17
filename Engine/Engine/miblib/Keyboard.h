#pragma once

#include "Macros.h"
#include "Window.h"

class Keyboard
{
public:
	Keyboard(){};
	~Keyboard(){};

	static bool KeyPressed(Window& window, int keyCode);
};

