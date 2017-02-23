#include "window.h"

namespace DCEngine { namespace graphics {

	bool Window::m_Keys[MAX_KEYS];
	bool Window::m_MouseButtons[MAX_BUTTONS];
	double Window::m_MouseX;
	double Window::m_mouseY;

	void window_resize(GLFWwindow *window, int width, int height);

	Window::Window(const char *title, int width, int height) {
		m_Title = title;
		m_Width = width;
		m_Height = height;
		if (!init())
			glfwTerminate();

		for (int i = 0; i < MAX_KEYS; i++)
		{
			m_Keys[i] = false;
		}

		for (int i = 0; i < MAX_BUTTONS; i++)
		{
			m_MouseButtons[i] = false;
		}

	}

	Window::~Window() {
		glfwTerminate();
	}

	bool Window::init() {
		if (!glfwInit()) {
			std::cout << "Failed to initialize GLFW" << std::endl;
			return false;
		}
		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
		if (!m_Window) {
			std::cout << "Failed to create GLFW window!" << std::endl;
			return false;
		}
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, this);
		glfwSetWindowSizeCallback(m_Window, window_resize);
		glfwSetKeyCallback(m_Window, key_callback);
		glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
		glfwSetCursorPosCallback(m_Window, cursor_position_callback);

		// Glew needs to be checed after the context has been initiated
		if (glewInit() != GLEW_OK) {
			std::cout << "Could not initialize Glew!" << std::endl;
			return false;
		}

		std::cout << "OpenGL: " << glGetString(GL_VERSION) << std::endl;

		return true;
	}

	bool Window::isKeyPressed(unsigned int keyCode) {
		if (keyCode >= MAX_KEYS) {
			//TODO: Add logging
			return false;
		}
		return m_Keys[keyCode];
	 }

	bool Window::isMouseButtonPressed(unsigned int button) {
		if (button >= MAX_BUTTONS) {
			//TODO: Add logging
			return false;
		}
		return m_MouseButtons[button];
	}

	void Window::getMousePosition(double& x, double& y) {
		x = m_MouseX;
		y = m_mouseY;
	}

	void Window::clear() const {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::update() {
		glfwPollEvents();
		glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
		glfwSwapBuffers(m_Window);
	}

	bool Window::closed() const {
		return glfwWindowShouldClose(m_Window) == 1;
	}

	void window_resize(GLFWwindow *window, int width, int height) {
		glViewport(0, 0, width, height);
	}

	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
		Window* win =  (Window*) glfwGetWindowUserPointer(window);
		win->m_Keys[key] = action != GLFW_RELEASE;
	}

	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->m_MouseButtons[button] = action != GLFW_RELEASE;
	}

	void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->m_MouseX = xpos;
		win->m_mouseY = ypos;
	}
} }

