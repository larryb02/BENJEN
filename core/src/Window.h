#ifndef WINDOW_H
#define WINDOW_H
#include <SDL2/SDL.h>
#include <string>

namespace BENJEN
{
    class Window
    {
    private:
        SDL_Window *m_window;
        SDL_Event m_event;
        SDL_GLContext m_context;
        std::string m_title;
        uint32_t m_width, m_height;
    public:
        Window(const uint32_t width, const uint32_t height);
        ~Window();

        void Init();
        void OnUpdate();
    };

}

#endif