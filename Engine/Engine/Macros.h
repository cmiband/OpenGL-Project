#pragma once

#include <GL/glew.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#define ASSERT(x) if(!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))

#define COLOR_RED 1;

void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);
