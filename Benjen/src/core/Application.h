#ifndef APPLICATION_H
#define APPLICATION_H

#include "Window.h"

namespace BENJEN
{
    struct Specification
    {
        std::string title;
        uint32_t width, height;

        Specification(std::string title, uint32_t width, uint32_t height)
            : title(title), width(width), height(height) {};
    };
    class Application
    {
    private:
        bool m_running = true;
        Window *m_windowContext;
        void Init();

    public:
        Application(Specification s);
        virtual ~Application() = default;

        void Run();
        virtual void OnUpdate();
        void onDetach(); // onDetach or onExit
    };

}
#endif
