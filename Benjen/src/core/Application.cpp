#include "Application.h"

namespace BENJEN
{
    void Application::OnUpdate() {}
    void Application::Run()
    {
        //init systems

        //program loop
        while(m_windowContext->GetState()) // eventually 'application' shoild control execution, when time to shutdown app will notify window
        {
            //Update window
            m_windowContext->OnUpdate();
            //update game
            OnUpdate();
            //render
        }
    }
    
}
