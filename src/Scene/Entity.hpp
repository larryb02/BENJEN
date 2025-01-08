#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <vector>
#include "../Renderer/Types/RenderTypes.hpp"

class Entity
{
    public:
        Entity(std::string name, std::vector<Vertex> vertices);
	    
        const std::string &getEntityName() const;
	    const glm::mat4 &getModelMatrix() const;
        const std::vector<Vertex> &getVertices() const;
        const std::vector<uint32_t> &getIndices() const;

        void updatePosition(float x, float y);

    private:
        std::string m_entityName; 
        std::vector<Vertex> m_vertices;
        std::vector<uint32_t> m_indices;
	    glm::mat4 m_model;
        //texture
};

#endif
