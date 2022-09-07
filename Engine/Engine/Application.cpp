#include "Application.h"

Application::Application(int width, int height, const char* title) {
	if (startWindow(width, height, title) != 0) {
		std::cout << "Error occured during creation of Application constructor" << std::endl;
		glfwTerminate();
	}

	Run();
}

Application::~Application() {
	glfwTerminate();
};

int Application::startWindow(int w, int h, const char* t) {
	if (!glfwInit()) return -1;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(w, h, t, NULL, NULL);
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

	unsigned int buffer;
	GLCall(glGenBuffers(1, &buffer));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, buffer));
	GLCall(glBufferData(GL_ARRAY_BUFFER, 3 * 2 * sizeof(float), positions, GL_STATIC_DRAW));

	unsigned int vertexArray;
	GLCall(glGenVertexArrays(1, &vertexArray));
	GLCall(glBindVertexArray(vertexArray));
	GLCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (const void*)0));
	GLCall(glEnableVertexAttribArray(0));

	GLCall(glBindVertexArray(0));
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glBindVertexArray(vertexArray);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}
}
