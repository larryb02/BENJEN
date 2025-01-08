#ifndef SCENE_MANAGER_HPP
#define SCENE_MANAGER_HPP

#include "Scene.hpp"
/*#include <memory>*/
#include <string>

namespace SceneManager
{
    /*std::unordered_map<std::string sceneName, Scene*> m_SceneMap;*/
    void addScene(Scene &scene);
    void loadScene(std::string sceneName);
    Scene* getCurrentScene();
    void getAllScenes();

}

#endif
