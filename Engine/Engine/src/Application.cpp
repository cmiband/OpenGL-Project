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

	unsigned int indices[] = {
		0, 1, 2
	};

	VertexBuffer vb(3 * 2 * sizeof(float), positions);

	VertexArray va;
	va.AddBuffer(2, false, 2 * sizeof(float));

	IndexBuffer ib(3 * sizeof(unsigned int), indices);
	
	Shader shader("res/shaders/Basic.shader");
	shader.SetUniform4f("u_Color", 1.0f, 0.0f, 0.0f, 1.0f);

	Renderer render;

	vb.Unbind();
	va.Unbind();
	shader.Unbind();
	ib.Unbind();
	while (!glfwWindowShouldClose(window))
	{
		render.Clear();

		render.Draw(va, ib, shader);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}
}
