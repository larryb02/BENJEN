#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <iostream>

namespace BENJEN
{
	class Shader
	{
	private:
		uint32_t m_shaderProgram;
		const std::string ReadFile(const char *filepath);
		uint32_t CreateShader(const char *filepath);

	public:
		Shader();
		~Shader();

		void CreateProgram(std::string vertexPath, std::string fragmentPath);
		void Use();
		void SetInt(const std::string &name, int value);
		void SetFloat(const std::string &name, float value);
		void SetFloat2(const std::string &name, const glm::vec2 &value);
		void SetFloat3(const std::string &name, const glm::vec3 &value);
		void SetFloat4(const std::string &name, const glm::vec4 &value);
		void SetMat4(const std::string &name, const glm::mat4 &value);
	};
}

#endif