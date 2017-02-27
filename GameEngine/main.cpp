#include "src\graphics\window.h"
#include"src\maths\maths.h"
#include "src/utils/fileutils.h"

// This is a standard 2d/3d game engine with a primary focus on mobile application developments
// Created by Dave Chadwick Feb 2017

int main() {

	using namespace DCEngine;
	using namespace graphics;
	using namespace maths;

	Window window("DC Engine!", 960, 540);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	vec2 vector(1.0f, 2.0f);

	mat4 position = mat4::translation(vec3(2, 3, 4));
	position *= mat4::identity();
	while (!window.closed())
	{
		window.clear();

		vec4 column = position.columns[3];
		std::cout << column << std::endl;
#if 1
		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f,  0.5f);
		glVertex2f( 0.5f,  0.5f);
		glVertex2f( 0.5f, -0.5f);
		glEnd();
#else
		glDrawArrays(GL_ARRAY_BUFFER, 0, 0);
#endif
		
		window.update();
	}

	return 0;
}