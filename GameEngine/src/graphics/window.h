#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW\glfw3.h>

namespace DCEngine { namespace graphics {

	class Window {

	private:
		int m_Width, m_Height;
		const char *m_Title;
		GLFWwindow *m_Window;
		bool m_Closed;
	public:
		Window(const char *title, int width, int height);
		~Window();
		void clear() const;
		void update();
		bool closed() const;

		inline int getWidth() const { return m_Width;  };
		inline int getHeight() const { return m_Height; };
	private:
		bool init();
	};
	
} }