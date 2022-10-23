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
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

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
	glm::vec2 x{ 0.0f,0.0f };
	
	Square square(x, 1.0f, math::Color4<float>{ 1.0f, 0.5f, 0.1f, 1.0f });

	Renderer renderer;
	
	square.UnbindPropeties();

	while (!glfwWindowShouldClose(window))
	{
		renderer.Clear();

		square.Draw(renderer);

		renderer.Swap(window);
	}
}
