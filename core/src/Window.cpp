#include "Window.h"
#include <iostream>
#include "glad/glad.h"

namespace BENJEN
{
    Window::Window(const uint32_t width, const uint32_t height)
    {
        Window::Init();
    }
    
    Window::~Window()
    {
    }

    void Window::Init()
    {
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        {
            std::cerr << "Failed to init SDL...\n"
                      << std::endl;
            SDL_Quit();
        }

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

        m_window = SDL_CreateWindow("VIDYA GAME",
                                    SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED,
                                    800,
                                    600,
                                    SDL_WINDOW_OPENGL);
        if (!m_window)
        {
            std::cerr << "SDL_CreateWindow(): " << SDL_GetError() << std::endl;
            SDL_Quit();
        }

        m_context = SDL_GL_CreateContext(m_window);

        if (!gladLoadGLLoader(SDL_GL_GetProcAddress))
        {
            std::cerr << "Failed to init GLAD" << std::endl;
            exit(EXIT_FAILURE);
        }
        glEnable(GL_DEPTH_TEST);
        glViewport(0, 0, 800, 600);
    }

    void Window::OnUpdate()
    {
        while (SDL_PollEvent(&m_event))
        {
            switch (m_event.type)
            {
            case SDL_QUIT:
                false;
            }
        }
        SDL_GL_SwapWindow(m_window);
        SDL_Delay(16);
    }

}
