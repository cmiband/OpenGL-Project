#include "Application.h"

#include "MEngine.h"

Application::Application(int width, int height, const std::string& title) {
	if (startWindow(width, height, title) != 0) {
		std::cout << "Error occured during creation of Application constructor" << std::endl;
		glfwTerminate();
	}

	Run();
}

Application::~Application() {
	glfwTerminate();
};

int Application::startWindow(int w, int h, const std::string &t) {
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
	VertexArray va;
	Triangle triangle(math::Vector2<float>{0.6f, 0.6f}, 0.4f, math::Vector4<float>{0.0f, 0.0f, 1.0f, 0.0f}, va);

	Renderer render;

	va.Unbind();
	triangle.UnbindPropeties();

	float test = -0.001f;
	while (!glfwWindowShouldClose(window))
	{
		render.Clear();

		triangle.Move(math::Vector2<float>{test, test});

		triangle.Draw(render, va);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}
}
