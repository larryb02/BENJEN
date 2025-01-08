#include "Camera.hpp"
#include <iostream>

#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(glm::mat4 view, glm::vec3 initPosition)
{
    m_view = view;
    m_cameraPos = glm::vec3(0.0f);
    UpdatePosition(initPosition);
}

const glm::mat4 &Camera::getView() const
{
    return m_view;
}

const glm::vec3 &Camera::getCameraPosition() const
{
    return m_cameraPos;
}

void Camera::UpdatePosition(glm::vec3 position)
{
    m_cameraPos += position;
    m_view = glm::translate(m_view, position);
}
