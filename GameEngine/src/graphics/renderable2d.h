#pragma once

#include "buffers\buffer.h"
#include "buffers\indexbuffer.h"
#include "buffers\vertexarray.h"
#include "../maths/maths.h"
#include "shader.h"

namespace DCEngine { namespace graphics {

	struct VertexData {
		maths::vec3 vertex; // OpenGL location 0 
		maths::vec4 color; // OpenGL location 1
	};

	class Renderable2D {
	protected:
		maths::vec3 m_Position;
		maths::vec2 m_Size;
		maths::vec4 m_Color;
	public:
		Renderable2D(maths::vec3 position, maths::vec2 size, maths::vec4 color)
			: m_Position(position), m_Size(size), m_Color(color) { }

		virtual ~Renderable2D() { }

		inline const maths::vec3& getPosition() const { return m_Position; }
		inline const maths::vec2& getSize() const { return m_Size; }
		inline const maths::vec4& getColor() const { return m_Color; }

	};
}}