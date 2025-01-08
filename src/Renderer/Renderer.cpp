#include "Renderer.hpp"
#include "../Scene/Scene.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>

void Renderer::ClearBuffer(glm::vec3 color) //FIX
{
    glClearColor(color.x, color.y, color.z, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
}

GLenum Renderer::CheckError_(const char *file, int line)
{
    GLenum errorCode;
    while ((errorCode = glGetError()) != GL_NO_ERROR)
    {
        std::string error;
        switch (errorCode)
        {
        case GL_INVALID_ENUM:
            error = "INVALID_ENUM";
            break;
        case GL_INVALID_VALUE:
            error = "INVALID_VALUE";
            break;
        case GL_INVALID_OPERATION:
            error = "INVALID_OPERATION";
            break;
        case GL_STACK_OVERFLOW:
            error = "STACK_OVERFLOW";
            break;
        case GL_STACK_UNDERFLOW:
            error = "STACK_UNDERFLOW";
            break;
        case GL_OUT_OF_MEMORY:
            error = "OUT_OF_MEMORY";
            break;
        case GL_INVALID_FRAMEBUFFER_OPERATION:
            error = "INVALID_FRAMEBUFFER_OPERATION";
            break;
        }
        std::cout << error << " | " << file << " (" << line << ")" << std::endl;
    }
    return errorCode;
}

void Renderer::Render(Shader &shader, Scene* scene)
{   
    std::vector<RenderData> rd = scene->createRenderData();
    
    
    for (int i = 0; i < rd.size(); i++)
    {
        // model = glm::mat4(1.0f);
        // model = glm::scale(model, glm::vec3(100.0f, 100.0f, 0.0f));
        // model = glm::translate(model, glm::vec3(0.3f, -0.3f, 0.0f));
        
        shader.Use();
        shader.setMat4("projection", scene->getProjectionMatrix());
        shader.setMat4("view", scene->getCamera().getView());
        shader.setMat4("model", rd[i].getModel());
        
        glBindVertexArray(rd[i].getVAO());
        glDrawArrays(GL_TRIANGLES, 0, rd[i].getVertexCount());
        glBindVertexArray(0);
        CheckError();
    }
}
