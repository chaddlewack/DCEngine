#include "src\graphics\window.h"

// This is a standard 2d/3d game engine with a primary focus on mobile application developments
// Created by Dave Chadwick 2017

int main() {

	using namespace DCEngine;
	using namespace graphics;
	Window window("Dave!", 800, 600);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	while (!window.closed())
	{
		window.clear();

#if 0

		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f,  0.5f);
		glVertex2f( 0.5f,  0.5f);
		glVertex2f( 0.5f, -0.5f);
		glEnd();
#endif
		glDrawArrays(GL_ARRAY_BUFFER, 0, 0);
		window.update();
	}

	return 0;
}