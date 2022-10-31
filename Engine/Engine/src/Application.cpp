#include "Application.h"

#include "MEngine.h"
#include <math.h>
#include <corecrt_math_defines.h>

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

void DrawCircle(float x, float y, float r, int sides) {
	const int numberOfVertices = sides + 2;
	float doublePi = 2.0f * M_PI;

	float *circleVerticesX = new float[numberOfVertices];
	float *circleVerticesY = new float[numberOfVertices];

	circleVerticesX[0] = x;
	circleVerticesY[0] = y;

	for (int i = 1; i < numberOfVertices; i++) {
		circleVerticesX[1] = x + (r * cos(i * doublePi / sides));
		circleVerticesY[1] = y + (r * sin(i * doublePi / sides));
	}

	float *allCircleVertices = new float[numberOfVertices * 2];
	for (int i = 0; i < numberOfVertices; i++) {
		allCircleVertices[i * 2] = circleVerticesX[i];
		allCircleVertices[(i * 2)+1] = circleVerticesY[i];
	}
}

void Application::Run() {

	Renderer renderer;

	int sides = 360;
	float r = 0.5f;
	float x= 0.0f;
	float y = 0.0f;

	int numberOfVertices = sides + 2;
	float doublePi = 2.0f * M_PI;

	float* circleVerticesX = new float[numberOfVertices];
	float* circleVerticesY = new float[numberOfVertices];

	circleVerticesX[0] = x;
	circleVerticesY[0] = y;

	for (int i = 1; i < numberOfVertices; i++) {
		circleVerticesX[i] = x + (r * cos(i * doublePi / sides));
		circleVerticesY[i] = y + (r * sin(i * doublePi / sides));
	}

	float* allCircleVertices = new float[numberOfVertices * 2];
	for (int i = 0; i < numberOfVertices; i++) {
		allCircleVertices[i * 2] = circleVerticesX[i];
		allCircleVertices[(i * 2) + 1] = circleVerticesY[i];
	}
	for (int i = 0; i < numberOfVertices; i++) {
		std::cout << allCircleVertices[i * 2] << " " << allCircleVertices[(i * 2) + 1] << std::endl;
	}

	VertexBuffer vb(numberOfVertices * 2 * sizeof(float), allCircleVertices);

	VertexArray va;
	va.AddBuffer(2, false, 2 * sizeof(float));

	unsigned int *indices = new unsigned int[3 * numberOfVertices];
	int c = 0;
	int i = 0;
	while (i<numberOfVertices*3) {
		if (i % 3 == 0) {
			indices[i] = 0;
			c++;
		}
		else if (i % 3 == 1) {
			indices[i] = c;
			c++;
		}
		else {
			indices[i] = c;
			c--;
		}
		i++;
	}

	IndexBuffer ib(numberOfVertices * 3 * sizeof(unsigned int), indices);

	Shader shader("res/shaders/testShader.shader");

	shader.Unbind();
	vb.Unbind();
	va.Unbind();
	ib.Unbind();
	while (!glfwWindowShouldClose(window))
	{
		renderer.Clear();

		shader.Bind();
		ib.Bind();
		va.Bind();
		GLCall(glDrawElements(GL_TRIANGLE_FAN, ib.getSize(), GL_UNSIGNED_INT, nullptr));

		renderer.Swap(window);
	}
}
