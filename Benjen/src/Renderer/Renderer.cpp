#include "Renderer.h"
#include <glad/glad.h>
namespace BENJEN
{
    Renderer::Renderer(/* args */)
    {
    }
    
    Renderer::~Renderer()
    {
    }
    void Renderer::SetColor(float r, float g, float b, float a)
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
}