#include "Application.h"

#include "MEngine.h"

Application::Application(int width, int height, std::string title) {
	if (startWindow(width, height, title) != 0) {
		std::cout << "Error occured during creation of Application constructor" << std::endl;
		glfwTerminate();
	}

	Run();
}

Application::~Application() {
	glfwTerminate();
};

int Application::startWindow(int w, int h, std::string t) {
	if (!glfwInit()) return -1;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(w, h, t.c_str(), NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (GLEW_OK != glewInit()) {
		std::cout << "error" << std::endl;
		return -1;
	}

	return 0;
}

void Application::Run() {
	float positions[] = {
		-0.5f, -0.5f,
		0.5f, -0.5f,
		0.0f, 0.5f
	};

	VertexBuffer buffer(3 * 2 * sizeof(float), positions);

	unsigned int vertexArray;
	GLCall(glGenVertexArrays(1, &vertexArray));
	GLCall(glBindVertexArray(vertexArray));
	GLCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (const void*)0));
	GLCall(glEnableVertexAttribArray(0));

	Shader shader("Shaders/Basic.shader");
	shader.Bind();
	shader.SetUniform4f("u_Color", 1.0f, 0.0f, 0.0f, 1.0f);

	GLCall(glBindVertexArray(0));
	buffer.Unbind();
	shader.Unbind();
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		shader.Bind();

		glBindVertexArray(vertexArray);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}
}
