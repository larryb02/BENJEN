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
    uint32_t Shader::CreateShader(const char *filepath)
    {
        const std::string shaderCode = std::string(ReadFile(filepath));
        const char *shaderCodePtr = shaderCode.c_str();

        uint32_t shader;
        shader = glCreateShader(GL_VERTEX_SHADER); //need to get proper type from shader code
        int success;
        char infoLog[512];
        glShaderSource(shader, 1, &shaderCodePtr, NULL);
        glCompileShader(shader);
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::" << "Shader Type" << "::COMPILATION_FAILED\n" // WRITE TO LOG
                      << infoLog << std::endl;
        };

        return shader;
    }
    /*
        Attaches shaders and creates a shader program
    */
    void Shader::CreateProgram(std::string vertexPath, std::string fragmentPath)
    {
        // LOG
        // read files
        const std::string vertexFile = ReadFile(vertexPath.c_str());
        const std::string fragmentFile = ReadFile(fragmentPath.c_str());

        const char *vertexFilePtr = vertexFile.c_str();
        const char *fragmentFilePtr = fragmentFile.c_str();
        // compile shaders
        unsigned int vertex, fragment;
        int success;
        char infoLog[512];
        
        // redundant block
        vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex, 1, &vertexFilePtr, NULL);
        glCompileShader(vertex);
        glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(vertex, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" // WRITE TO LOG
                      << infoLog << std::endl;
        };
        // vertex = CreateShader(vertexPath.c_str());

        fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment, 1, &fragmentFilePtr, NULL);
        glCompileShader(fragment);
        glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(fragment, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" // LOG
                      << infoLog << std::endl;
        };
        //
        m_shaderProgram = glCreateProgram();
        // attach to shader
        glAttachShader(m_shaderProgram, vertex);
        glAttachShader(m_shaderProgram, fragment);
        glLinkProgram(m_shaderProgram);
    }

    const std::string Shader::ReadFile(const char *filepath)
    {
        // LOG
        std::string contents;
        std::ifstream fileStream;
        fileStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try
        {
            fileStream.open(filepath);
            if (!fileStream)
            {
                std::cerr << "file not found" << std::endl;
                return nullptr;
            }
            std::stringstream ss;
            ss << fileStream.rdbuf();
            fileStream.close();
            contents = ss.str();
        }
        catch (const std::ifstream::failure e)
        {
            // error shader file not successfully read message
            std::cerr << e.what() << '\n';
            return nullptr;
        }
        return contents;
    }

    void Shader::Use()
    {
        glUseProgram(m_shaderProgram);
    }
}
