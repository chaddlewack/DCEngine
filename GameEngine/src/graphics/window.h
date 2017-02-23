#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW\glfw3.h>

namespace DCEngine { namespace graphics {

#define MAX_KEYS 1024
#define MAX_BUTTONS 32


	class Window {
	private:
		friend struct GLFWwindow;
		int m_Width, m_Height;
		const char *m_Title;
		GLFWwindow *m_Window;
		bool m_Closed;

		bool m_Keys[MAX_KEYS];
		bool m_MouseButtons[MAX_BUTTONS];
		double m_MouseX, m_mouseY;
	public:
		Window(const char *title, int width, int height);
		~Window();
		void clear() const;
		void update();
		bool closed() const;

		inline int getWidth() const { return m_Width;  };
		inline int getHeight() const { return m_Height; };

		bool isKeyPressed(unsigned int keyCode);
		bool isMouseButtonPressed(unsigned int button);
		void getMousePosition(double& x, double& y);
	private:
		bool init();
		friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		friend static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		friend static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
	};
	
} }