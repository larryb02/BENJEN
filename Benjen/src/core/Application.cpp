#include "Application.h"
#include <iostream>

namespace BENJEN
{
    Application::Application()
    {
        m_windowContext = new Window("Test App", 1280, 720);
    }
    Application::~Application()
    {
        delete m_windowContext;
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
