#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/gtc/matrix_transform.hpp>
/*
   Required Camera Features:
   - Update Position
   - glm matrix operations (translate, rotate, etc as needed)
   */

class Camera
{
    public:
        Camera(glm::mat4 view, glm::vec3 initPosition);
        const glm::mat4 &getView() const;
        const glm::vec3 &getCameraPosition() const;

        //matrix operations
        //rotate
        //translate?
        void UpdatePosition(glm::vec3 translation);

    private:
        glm::mat4 m_view;
        glm::vec3 m_cameraPos;
};

#endif
