/**
* (c) 2017 Pablo Luis Garc�a. All rights reserved.
* Released under GPL v2 license. Read LICENSE for more details.
*/

#include "Window.h"
#include <iostream>

namespace gfx
{

Window::Window() :
	m_window(NULL),
	m_isFullscreen(false),
	m_width(0),
	m_height(0)
{}

Window::~Window()
{
	if (m_window != NULL)
	{
		glfwTerminate();
	}
}

bool Window::init(const std::string &screenTitle, int window_width, int window_height, bool fullscreen)
{
	if (!glfwInit())
	{
		std::cout << "[CORE] Failed to initialize GLFW" << std::endl;
		return false;
	}

	// Create window
	m_window = glfwCreateWindow(window_width, window_height, screenTitle.c_str(), NULL, NULL);

	if (!m_window)
	{
		std::cout << "[CORE] Window could not be created!" << std::endl;
		glfwTerminate();
		return false;
	}

	std::cout << "[CORE] Window created" << std::endl;

	m_width = window_width;
	m_height = window_height;

	// Create renderer for window
	glfwMakeContextCurrent(m_window);
	// Setup callbacks
	glfwSetKeyCallback(m_window, input::onKeyChange);
	glfwSetMouseButtonCallback(m_window, input::onMouseChange);
	glfwSetCursorPosCallback(m_window, input::onMouseMove);
	glfwSetWindowSizeCallback(m_window, windowResize);

	std::cout << "[CORE] OpenGL context created" << std::endl;

	glewInit();

	std::cout << "[CORE] " << glGetString(GL_VERSION) << std::endl;

	glViewport(0, 0, m_width, m_height);

	glfwSetWindowUserPointer(m_window, this);

	return true;
}

void Window::clear() const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::update()
{
	glfwPollEvents();
	glfwSwapBuffers(m_window);
}

int Window::getWidth() const
{
	return m_width;
}

int Window::getHeight() const
{
	return m_height;
}

bool Window::isClosed() const
{
	return glfwWindowShouldClose(m_window) == 1;
}

void Window::setSize(int width, int height)
{
	m_width = width;
	m_height = height;
}

void Window::toggleFullscreen()
{
	
}

void windowResize(GLFWwindow *window, int width, int height)
{
	Window *windowClass = (Window*)glfwGetWindowUserPointer(window);
	windowClass->setSize(width, height);
	glViewport(0, 0, width, height);
}

} // namespace gfx
