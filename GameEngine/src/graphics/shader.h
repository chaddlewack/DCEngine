#pragma once

#include <iostream>
#include <vector>
#include <GL/glew.h>
#include "../utils/fileutils.h"


namespace DCEngine { namespace graphics {

	class Shader{
	private:
		GLuint m_ShaderId;
		const char* m_VertPath;
		const char* m_FragPath;
	public:
		Shader(const char* vertexPath, const char* fragPath);
		~Shader();

		void enable() const;
		void disable() const;
	private:
		GLuint load();
	};
}}