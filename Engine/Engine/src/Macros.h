#pragma once

#include <GL/glew.h>

#define ASSERT(x) if(!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))

#define SCREEN_WIDTH 640.0f
#define SCREEN_HEIGTH 640.0f

void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);
