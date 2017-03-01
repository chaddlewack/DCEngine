#include "shader.h"

namespace DCEngine { namespace graphics {

	Shader::Shader(const char* vertexPath, const char* fragPath) : m_VertPath(vertexPath), m_FragPath(fragPath) {
		m_ShaderId = load();
	}

	Shader::~Shader() {
		glDeleteProgram(m_ShaderId);
	}

	GLuint Shader::load() {
		GLuint program = glCreateProgram();
		GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
		GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

		std::string vertSourceString = FileUtil::read_file(m_VertPath);
		std::string fragSourceString = FileUtil::read_file(m_FragPath);

		const char* vertSource = vertSourceString.c_str();
		const char* fragSource = fragSourceString.c_str();

		glShaderSource(vertex, 1, &vertSource, NULL);
		glCompileShader(vertex);
		
		GLint vertexResult;
		glGetShaderiv(vertex, GL_COMPILE_STATUS, &vertexResult);
		if (vertexResult == GL_FALSE) {
			GLint length;
			glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> error(length);
			glGetShaderInfoLog(vertex, length, &length, &error[0]);
			std::cout << "Failed to compile vertex shader: " << std::endl << &error[0] << std::endl;
			glDeleteShader(vertex);
			return 0;
		}

		glShaderSource(fragment, 1, &fragSource, NULL);
		glCompileShader(fragment);

		GLint fragResult;
		glGetShaderiv(fragment, GL_COMPILE_STATUS, &fragResult);
		if (fragResult == GL_FALSE) {
			GLint length;
			glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> error(length);
			glGetShaderInfoLog(fragment, length, &length, &error[0]);
			std::cout << "Failed to compile fragment shader: " << std::endl << &error[0] << std::endl;
			glDeleteShader(fragment);
			return 0;
		}

		glAttachShader(program, vertex);
		glAttachShader(program, fragment);

		glDeleteShader(vertex);
		glDeleteShader(fragment);

		return program;
	}

	GLint Shader::getUniformLocation(const GLchar* name) {
		return glGetUniformLocation(m_ShaderId, name);
	}

	void Shader::setUniformi(const GLchar * name, int value){
		glUniform1i(getUniformLocation(name), value);
	}

	void Shader::setUniform1f(const GLchar * name, float value) {
		glUniform1f(getUniformLocation(name), value);
	}

	void Shader::setUniform2f(const GLchar * name, const maths::vec2& vector){
		glUniform2f(getUniformLocation(name), vector.x, vector.y);
	}

	void Shader::setUniform3f(const GLchar * name, const maths::vec3& vector){
		glUniform3f(getUniformLocation(name), vector.x, vector.y, vector.z);
	}

	void Shader::setUniform4f(const GLchar * name, const maths::vec4& vector){
		glUniform4f(getUniformLocation(name), vector.x, vector.y, vector.z, vector.w);
	}

	void Shader::setUniformMat4(const GLchar * name, const maths::mat4& matrix){
		glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, matrix.elements);
	}

	void Shader::enable() const {
		glUseProgram(m_ShaderId);
	}

	void Shader::disable() const {
		glUseProgram(0);
	}

}}
