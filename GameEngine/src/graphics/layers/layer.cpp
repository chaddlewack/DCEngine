#include "layer.h"

namespace DCEngine { namespace graphics {

	Layer::Layer(Renderer2D* renderer, Shader* shader, maths::mat4 projectionMatrix)
	: m_Renderer(renderer), m_Shader(shader), m_ProjectionMatrix(projectionMatrix) {
		m_Shader->enable();
		m_Shader->setUniformMat4("pr_matrix", m_ProjectionMatrix);
		m_Shader->disable();
	}

	Layer::~Layer() {
		//delete m_Shader;
		delete m_Renderer;
		for (int i = 0; i < m_Rendereables.size(); i++)
			delete m_Rendereables[i];
		
	}

	void Layer::add(Renderable2D* renderable) {
		m_Rendereables.push_back(renderable);
	}

	void Layer::render() {
		m_Shader->enable();
		m_Renderer->begin();
		for each (const Renderable2D* renderable in m_Rendereables)
			m_Renderer->submit(renderable);

		m_Renderer->end();
		m_Renderer->flush();
	}
}}