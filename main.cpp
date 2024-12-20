#include <glad/glad.h>
#include <GLFW/glfw3.h> 
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);


int main()
{
	

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create Window
	GLFWwindow* window = glfwCreateWindow(800, 600, "Dan's First OpenGL project", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "GLFW WINDOW CREATION FAILED.\n";
		glfwTerminate();
		return -1;
	} glfwMakeContextCurrent(window);

	// INIT GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "GLAD INIT FAILED.\n";
		glfwDestroyWindow(window);
		glfwTerminate();
		return -1;
	}

	// VIEWPORT
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// RENDER LOOP
	while (!glfwWindowShouldClose(window))
	{
		// input
		processInput(window);

		//render
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// check, call, and swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// CLEANUP
	glfwTerminate();
	return 0;
}


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}


void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) glfwSetWindowShouldClose(window, true);
}