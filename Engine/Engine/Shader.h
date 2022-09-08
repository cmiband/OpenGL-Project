#pragma once
#include <GL/glew.h>

#include <iostream>
#include <fstream>
#include <string>

#include "Macros.h"

struct ShaderType {
	std::string Vertex;
	std::string Fragment;
};

enum class readType {
	VERTEXREAD,
	FRAGMENTREAD
};

class Shader
{
private:
	unsigned int rendererId;
	std::string vertexSource;
	std::string fragmentSource;
	unsigned int vertex;
	unsigned int fragment;

	ShaderType readShader(const std::string& filepath);
	unsigned int CompileShader(std::string &source, unsigned int type);
	unsigned int CreateShader(std::string& vs, std::string& fs);
public:
	Shader(const std::string& filepath);
	~Shader();

	void Bind() const;
	void Unbind() const;
};

