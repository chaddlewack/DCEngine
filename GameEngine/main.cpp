#include "src/graphics/window.h"
#include "src/maths/maths.h"
#include "src/graphics/shader.h"

#include "src/graphics/buffers/buffer.h"
#include "src/graphics/buffers/indexbuffer.h"
#include "src/graphics/buffers/vertexarray.h"

#include "src/graphics/renderer2d.h"
#include "src/graphics/simple2drenderer.h"
#include "src/graphics/batchRenderer2D.h"

#include "src/graphics/sprite.h"
#include "src/graphics/static_sprite.h"

#include "src\utils\timer.h"

#include <time.h>

#define BATCH_RENDERER 1

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

	std::vector<Renderable2D*> sprites;
	srand(time(NULL));
	for (float y = 0; y < 9.0f; y+=0.1)
	{
		for (float x = 0; x < 16.0f; x+=0.1)
		{
			sprites.push_back(new 
#if BATCH_RENDERER	
				Sprite
#else
				StaticSprite
#endif
				(x, y, 0.08f, 0.08f, maths::vec4(rand() % 1000 / 1000.0f, 0, 1, 1)
#if !BATCH_RENDERER
				,shader
#endif
			));
		}
	}

#if BATCH_RENDERER
	Sprite sprite(5, 5, 4, 4, maths::vec4(1, 0, 1, 1));
	Sprite sprite2(7, 1, 2, 3, maths::vec4(0.2f, 0, 1, 1));
	BatchRenderer2D renderer;
#else
	StaticSprite sprite(5, 5, 4, 4, maths::vec4(1, 0, 1, 1), shader);
	StaticSprite sprite2(7, 1, 2, 3, maths::vec4(0.2f, 0, 1, 1), shader);
	Simple2DRenderer renderer;
#endif

	shader.setUniform2f("light_pos", vec2(8.0f, 4.5f));
	shader.setUniform4f("color", vec4(0.2f, 0.3f, 0.8f, 1.0f));
	shader.listUniforms();
	shader.listAttributes();

	Timer time;
	float timer = 0;
	unsigned int frames = 0;
	while (!window.closed()){
		window.clear();
		double x, y;
		window.getMousePosition(x, y);
		shader.setUniform2f("light_pos", vec2((float)(x * 16.0f / 960.0f), (float)(9.0f - y * 9.0f / 540.0f)));
#if BATCH_RENDERER
		renderer.begin();
#endif
		for (int i = 0; i < sprites.size(); i++){
			renderer.submit(sprites[i]);
		}
#if BATCH_RENDERER
		renderer.end();
#endif
		renderer.flush();
		window.update();
		frames++;
		// Simple FPS check
		if (time.elapsed() - timer > 1.0f) {
			timer += 1.0f;
			printf("%d fps\n", frames);
			frames = 0;
		}
	}

	return 0;
}