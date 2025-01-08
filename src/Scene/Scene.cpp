#include "Scene.hpp"
#include "SceneManager.hpp"
// #include <memory>
/*#include <memory>*/


#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>

Scene::Scene(const char *name, float leftWidth, float rightWidth, float bottomHeight, float topHeight)
	: 	
	m_sceneName(name),
	m_sceneCamera(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -0.3f))
{
	m_sceneWidth = leftWidth;
	m_sceneHeight = topHeight;
	m_sceneProjection = glm::ortho(leftWidth, rightWidth, bottomHeight, topHeight, 0.1f, 100.0f);
	m_sceneItems = {};
    SceneManager::addScene(*this);
}

void Scene::addEntity(Entity* item)
{
	m_sceneItems.insert({item->getEntityName(), item});
}

void Scene::removeEntity(std::string entityName) //change arg to a key
{
    if (m_sceneItems.find(entityName) == m_sceneItems.end())
    {
            std::cout << entityName << " does not exist" << std::endl;
            return;
    }
    m_sceneItems.erase(entityName);	
}

const Entity* Scene::getEntity(const std::string key) const
{
	//add logic to check if key exists
	return m_sceneItems.find(key) != m_sceneItems.end() ? m_sceneItems.at(key) : nullptr;
}

//const Camera &Scene::getCamera() const
//{
//	return m_sceneCamera;
//}
//

Camera &Scene::getCamera()
{
	return m_sceneCamera;
}


void Scene::setCamera(glm::vec3 pos)
{
	m_sceneCamera.UpdatePosition(pos);
}

const glm::mat4 &Scene::getProjectionMatrix() const
{
    return m_sceneProjection;
}

const std::string &Scene::getSceneName() const
{
    return m_sceneName;
}

std::vector<RenderData> Scene::createRenderData()
{
    std::vector<RenderData> data = {};
    for (auto entity: m_sceneItems)
    {
        /*std::cout << entity.second->getEntityName() << " " << glm::to_string(entity.second->getModelMatrix()) << std::endl;*/
        data.emplace_back(entity.second->getVertices(), entity.second->getModelMatrix());
    }

    return data;
}

