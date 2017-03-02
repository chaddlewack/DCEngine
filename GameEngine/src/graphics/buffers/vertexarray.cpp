#include "vertexarray.h"

namespace DCEngine { namespace graphics {

	VertexArray::VertexArray(){
		glGenVertexArrays(1, &m_ArrayID);
	}

	VertexArray::~VertexArray(){
		m_Buffers.clear();
	}

	void VertexArray::addBuffer(Buffer * buffer, GLuint index){
		bind();
		buffer->bind();

		glEnableVertexAttribArray(index);
		glVertexAttribPointer(index, buffer->getComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);

		buffer->unbind();
		unbind();
	}

	void VertexArray::bind() const {
		glBindVertexArray(m_ArrayID);
	}

	void VertexArray::unbind() const {
		glBindVertexArray(0);
	}

}}