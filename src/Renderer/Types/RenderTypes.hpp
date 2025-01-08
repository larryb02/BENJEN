#ifndef RENDERDATA_HPP
#define RENDERDATA_HPP

#include <glad/glad.h>
#include "../Shader.hpp"
#include "../../Camera.hpp"
#include <vector>

// i want this to contain all potential buffers, textures, and shaders needed to render an item so i can just pass a list of these to renderer
// the user should understand the format of their data or have a file with the data, so all they have to do is pass that, then renderer handles rest :)

// create multiple constructors

// wrap in a namespace? probly just wrap in renderer namespace if i were to do so

// concerns:
typedef struct Vertex
{
    Vertex(float x, float y, float z);
    Vertex(float x, float y, float z, float r, float g, float b);
    glm::vec3 m_pos;
    glm::vec3 m_rgb;
} Vertex;

class RenderData
{
public:
    // constructors
    RenderData(std::vector<float> &vertices, glm::mat4 &model); 
    RenderData(const std::vector<Vertex> &vertices, const glm::mat4 &model);
 
//     RenderData(std::vector<float> &vertices, glm::mat4 &model); 
//     RenderData(std::vector<Vertex> &vertices, glm::mat4 &model);
    
    // accessors
    unsigned int getVAO() const;
    unsigned int getVertexCount() const;
    const glm::mat4 &getModel() const; //nor does this
    glm::mat4 getProjection() const; //doesn't belong here
    /*const Camera *getCamera() const;*/

private:
    unsigned int m_vao, m_vbo, m_vertexCount;
    glm::mat4 m_model;
    /*Camera *m_cameraData;*/
    
};

#endif
