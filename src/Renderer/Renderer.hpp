
#ifndef RENDERER_HPP
#define RENDERER_HPP

// #include <glm/glm.hpp>
/*#include <vector>*/
// #include "Texture.hpp"
#include "./Types/RenderTypes.hpp"
#include "../Scene/Scene.hpp"
/*#include <memory>*/
// #include <glad/glad.h>

//Render Pipeline:
// list of data to draw per frame gets pushed to a list, (from respected sources)
// every frame a render call is made, 
// renderer creates the RenderData then renders the items
namespace Renderer
{
    enum RenderMode { DEBUG };
    
    void Render(Shader &shader,Scene* scene);
    void ClearBuffer(glm::vec3 color);
    GLenum CheckError_(const char *file, int line);
    
    #define CheckError() CheckError_(__FILE__, __LINE__)
}


#endif
