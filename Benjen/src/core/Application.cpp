#include "Application.h"
#include <iostream>

namespace BENJEN
{
    Application::Application(Specification s)
        : m_windowContext(new Window(s.title, s.width, s.height))
    {
    }

    void Application::Init()
    {
        std::cout << "Initiating Window" << std::endl;
        m_windowContext->Init();
        std::cout << "Initiating Renderer" << std::endl;
        // Renderer->Init()
    }
    void Application::Run()
    {
        // init systems
        std::cout << "Initiating systems" << std::endl;
        Init();
        std::cout << "Systems initiated." << std::endl;
        // window
        // renderer
        // program loop
        while (m_windowContext->GetState()) // eventually 'application' shoild control execution, when time to shutdown app will notify window
        {
            // update game
            OnUpdate();
            // render
            // Update window
            m_windowContext->OnUpdate();
        }
    }

    void Application::OnUpdate() {}

}
