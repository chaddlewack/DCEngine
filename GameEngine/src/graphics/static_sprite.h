#pragma once

#include "renderer2d.h"
#include "renderable2d.h"

namespace DCEngine { namespace graphics {

	class StaticSprite : public Renderable2D {
	private:
		VertexArray* m_VertexArray;
		IndexBuffer* m_IndexBuffer;
		Shader& m_Shader;
	public:
		StaticSprite(float x, float y, float width, float height, maths::vec4& color, Shader& shader);
		~StaticSprite();

		inline const VertexArray* getVAO() const { return m_VertexArray;  }
		inline const IndexBuffer* getIBO() const { return m_IndexBuffer; }

		inline Shader& getShader() const { return m_Shader; }
	};

}}