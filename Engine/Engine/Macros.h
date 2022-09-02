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

struct ShaderProgramSource {
    std::string VertexSource;
    std::string FragmentSource;
};

void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);

static ShaderProgramSource ParseShader(const std::string& filepath);
static unsigned int CompileShader(unsigned int type, const std::string& source);