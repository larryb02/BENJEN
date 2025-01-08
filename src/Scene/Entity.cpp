#include "Entity.hpp"

Entity::Entity(std::string name, std::vector<Vertex> vertices)
{
    m_entityName = name;
    m_model = glm::mat4(1.0f);
    m_vertices = vertices;
    std::cout << "Entity: " << m_entityName << "Has Been Created" << std::endl;
}

const std::string &Entity::getEntityName() const
{
    return m_entityName;
}

const glm::mat4 &Entity::getModelMatrix() const
{
	return m_model;
}

const std::vector<Vertex> &Entity::getVertices() const
{
    return m_vertices;
}

const std::vector<uint32_t> &Entity::getIndices() const
{
    return m_indices;
}

void Entity::updatePosition(float x, float y)
{
    m_model = glm::translate(m_model, glm::vec3(x, y, 0.0f));
}
