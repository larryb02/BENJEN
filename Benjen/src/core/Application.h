#ifndef APPLICATION_H
#define APPLICATION_H

#include "Window.h"

namespace BENJEN
{
    class Application
    {
    private:
        bool m_running = true;
        Window *m_windowContext;
    public:
        Application();
        ~Application();

        void Run();
        void OnUpdate();
        void onDetach(); // onDetach or onExit
    };

}
#endif
