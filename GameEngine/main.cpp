#include "src\graphics\window.h"
#include"src\maths\maths.h"
#include "src\graphics\shader.h"

#include "src\graphics\buffers\buffer.h"
#include "src\graphics\buffers\indexbuffer.h"
#include "src\graphics\buffers\vertexarray.h"

#include "src/graphics/renderer2d.h"
#include "src\graphics\simple2drenderer.h"

#define BUFFER_OFFSET(i) ((char *)NULL + (i))

// This is a standard 2d/3d game engine with a primary focus on mobile application developments
// Created by Dave Chadwick Feb 2017

int main() {

	using namespace DCEngine; 
	using namespace graphics;
	using namespace maths;

	Window window("DC Engine!", 960, 540);
	//glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);
	shader.setUniformMat4("ml_matrix", mat4::translation(vec3(4, 3, 0)));
	shader.setUniform2f("light_pos", vec2(8.0f, 4.5f));
	shader.setUniform4f("color", vec4(0.2f, 0.3f, 0.8f, 1.0f));
	shader.listUniforms();
	shader.listAttributes();

	Renderable2D sprite(maths::vec3(5, 5, 0), maths::vec2(4, 4), maths::vec4(1, 0, 1, 1), shader);
	Renderable2D sprite2(maths::vec3(7, 1, 0), maths::vec2(2, 3), maths::vec4(0.2f, 0, 1, 1), shader);
	Simple2DRenderer renderer;

	while (!window.closed()){
		window.clear();
		double x, y;
		window.getMousePosition(x, y);
		shader.setUniform2f("light_pos", vec2((float)(x * 16.0f / 960.0f), (float)(9.0f - y * 9.0f / 540.0f)));
		renderer.submit(&sprite);
		renderer.submit(&sprite2);
		renderer.flush();
		window.update();
	}

	return 0;
}