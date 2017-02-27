#include "src\graphics\window.h"
#include"src\maths\maths.h"
#include "src\graphics\shader.h"

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

	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");

	while (!window.closed())
	{
		window.clear();
		glDrawArrays(GL_ARRAY_BUFFER, 0, 0);
		window.update();
	}

	return 0;
}