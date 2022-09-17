#include "Shader.h"
#include "Macros.h"

Shader::Shader(const std::string& filepath) {
	ShaderType type = readShader(filepath);

	vertexSource = type.Vertex;
	fragmentSource = type.Fragment;
	graphicsId = CreateShader(vertexSource, fragmentSource);
}

Shader::~Shader() {
	GLCall(glDeleteProgram(graphicsId));
}

ShaderType Shader::readShader(const std::string& filepath) {
	std::ifstream file;
	file.open(filepath);
	readType currentType = readType::VERTEXREAD;
	std::string vertexShader;
	std::string fragmentShader;

	std::string line;
	while (std::getline(file, line)) {
		if (line == "#shader vertex") {
			currentType = readType::VERTEXREAD;
			continue;
		}
		if (line == "#shader fragment") {
			currentType = readType::FRAGMENTREAD;
			continue;
		}
		if (currentType == readType::VERTEXREAD) {
			vertexShader += line;
			vertexShader += '\n';
		}
		if (currentType == readType::FRAGMENTREAD) {
			fragmentShader += line;
			fragmentShader += '\n';
		}
	}

	return { vertexShader,fragmentShader };
}

unsigned int Shader::CompileShader(const std::string &source, unsigned int type)
{
	const char* src = source.c_str();
	unsigned int id = glCreateShader(type);
	GLCall(glShaderSource(id, 1, &src, nullptr));
	GLCall(glCompileShader(id));

	int result;
	GLCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result));
	if (result == GL_FALSE) {
		int length;
		GLCall(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));
		char* message = (char*)alloca(length * sizeof(char));
		GLCall(glGetShaderInfoLog(id, length, &length, message));
		std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << "shader!" << std::endl;
		std::cout << message << std::endl;
		GLCall(glDeleteShader(id));
		return 0;
	}

	return id;
}

unsigned int Shader::CreateShader(const std::string& vs, std::string& fs)
{
	unsigned int program = glCreateProgram();
	unsigned int vertexS = CompileShader(vs, GL_VERTEX_SHADER);
	unsigned int fragmentS = CompileShader(fs, GL_FRAGMENT_SHADER);

	GLCall(glAttachShader(program, vertexS));
	GLCall(glAttachShader(program, fragmentS));
	GLCall(glLinkProgram(program));
	GLCall(glValidateProgram(program));

	GLCall(glDeleteShader(vertexS));
	GLCall(glDeleteShader(fragmentS));

	return program;
}

void Shader::Bind() const{
	glUseProgram(graphicsId);
}

void Shader::Unbind() const {
	glUseProgram(0);
}

void Shader::SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3)
{
	int uniLocation = glGetUniformLocation(graphicsId, name.c_str());

	GLCall(glUniform4f(uniLocation, v0, v1, v2, v3));
}


