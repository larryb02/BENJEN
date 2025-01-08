#include "SceneManager.hpp"
/*#include <memory>*/


namespace SceneManager
{
    std::unordered_map<std::string, Scene&> m_sceneMap;
    Scene* m_currentScene(nullptr);

    void addScene(Scene &scene)
    {
        m_sceneMap.insert({scene.getSceneName(), scene});
    }

    void loadScene(std::string sceneName)
    {
        if(m_sceneMap.find(sceneName) == m_sceneMap.end())
        {
            std::cout << "Scene: " << sceneName << " not found." << std::endl;
            return;
        }
        std::cout << "Loading Scene: " << sceneName << std::endl;
        m_currentScene = &m_sceneMap.at(sceneName);
    }

    Scene* getCurrentScene()
    {
        /*std::cout << "Current Scene: " << m_currentScene->getSceneName() << std::endl;*/
        return m_currentScene;
    }

    void getAllScenes()
    {
        std::cout << "Scenes: " << std::endl;
        for (auto item : m_sceneMap)
        {
            std::cout << item.first << std::endl;
        }
    }
}
