#include "Shader.h"
#include <fstream>
#include <sstream>
namespace BENJEN
{
    Shader::Shader()
    {
    }

    Shader::~Shader()
    {
    }
    /*
        Creates and compiles shaders based on type
    */
    uint32_t Shader::CreateShader(const std::string filepath)
    {
        const std::string shaderCode = ReadFile(filepath);
        const char *shaderCodePtr = shaderCode.c_str();
        const std::string shaderType = GetShaderType(filepath);

        uint32_t shader;
        if (shaderType == "vert")
        {
            shader = glCreateShader(GL_VERTEX_SHADER); // need to get proper type from shader code
            int success;
            char infoLog[512];
            glShaderSource(shader, 1, &shaderCodePtr, NULL);
            glCompileShader(shader);
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(shader, 512, NULL, infoLog);
                std::cout << "ERROR::SHADER::" << "VERTEX" << "::COMPILATION_FAILED\n" // WRITE TO LOG
                          << infoLog << std::endl;
            };
        }
        else
        {                                              // assume its a fragment shader for now
            shader = glCreateShader(GL_FRAGMENT_SHADER); // need to get proper type from shader code
            int success;
            char infoLog[512];
            glShaderSource(shader, 1, &shaderCodePtr, NULL);
            glCompileShader(shader);
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(shader, 512, NULL, infoLog);
                std::cout << "ERROR::SHADER::" << "FRAGMENT" << "::COMPILATION_FAILED\n" // WRITE TO LOG
                          << infoLog << std::endl;
            };
        }

        return shader;
    }
    /*
        Attaches shaders and creates a shader program
    */
    void Shader::CreateProgram(std::string vertexPath, std::string fragmentPath)
    {
        // LOG
        std::cout << "Creating Program with args: " << vertexPath << " " << fragmentPath << std::endl;
        std::cout << "Back to CreateProgram()" << std::endl;
        // compile shaders
        unsigned int vertex, fragment;
        std::cout << "Creating vertex shader" << std::endl;
        vertex = CreateShader(vertexPath);
        fragment = CreateShader(fragmentPath);
        std::cout << "Creating shader program" << std::endl;
        m_shaderProgram = glCreateProgram();
        // attach to shader
        glAttachShader(m_shaderProgram, vertex);
        glAttachShader(m_shaderProgram, fragment);
        glLinkProgram(m_shaderProgram);
    }

    const std::string Shader::ReadFile(const std::string filepath)
    {
        // LOG
        std::string contents;
        std::ifstream fileStream;
        fileStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try
        {
            std::cout << "Opening file " << filepath << std::endl;
            fileStream.open(filepath);
            if (!fileStream)
            {
                std::cerr << "file not found" << std::endl;
                return nullptr;
            }
            std::cout << filepath << " opened" << std::endl;
            std::stringstream ss;
            std::cout << "Reading " << filepath << " into buffer" << std::endl;
            ss << fileStream.rdbuf();
            fileStream.close();
            contents = ss.str();
            std::cout << filepath << " succesfully read" << std::endl;
        }
        catch (const std::ifstream::failure e)
        {
            // error shader file not successfully read message
            std::cerr << e.what() << '\n';
            return nullptr;
        }
        // std::cout << filepath << ": " << std::endl << contents << std::endl;
        return contents;
    }

    const std::string Shader::GetShaderType(const std::string filepath)
    {
        const std::string delim = ".";
        std::size_t pos = filepath.find(delim);
        std::string type = filepath.substr((pos + 1), filepath.size());
        return type;
    }

    void Shader::Use()
    {
        glUseProgram(m_shaderProgram);
    }
}
