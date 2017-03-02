#pragma once

namespace DCEngine { namespace graphics {


	class Renderer {
	private:

	public:
		Renderer();
		~Renderer();

	public:
		void submit();
		void flush();
	};

}}