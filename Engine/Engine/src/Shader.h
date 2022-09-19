#pragma once

#include <iostream>
#include <fstream>
#include <string>

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
	unsigned int graphicsId;
	std::string vertexSource;
	std::string fragmentSource;
	unsigned int vertex;
	unsigned int fragment;

	ShaderType readShader(const std::string& filepath);
	unsigned int CompileShader(const std::string &source, unsigned int type);
	unsigned int CreateShader(const std::string& vs, std::string& fs);
public:
	Shader(const std::string& filepath);
	~Shader();
	void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);

	void Bind() const;
	void Unbind() const;
};

