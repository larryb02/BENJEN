#include "Window.h"
#include <glad/glad.h>
#include <iostream>


namespace BENJEN
{
    Window::Window(const std::string title, const uint32_t width, const uint32_t height)
    : m_title(title), m_width(width), m_height(height)
    {
    }

    Window::~Window()
    {
        SDL_GL_DeleteContext(m_context);
        SDL_DestroyWindow(m_window);
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

        m_window = SDL_CreateWindow(m_title.c_str(),
                                    SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED,
                                    m_width,
                                    m_height,
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
        glViewport(0, 0, m_width, m_height);
    }

    void Window::OnUpdate()
    {
        while (SDL_PollEvent(&m_event))
        {
            switch (m_event.type) // change to just m_event and use union members for cases
            {
            case SDL_QUIT:
                m_state = false;
            case SDL_WINDOWEVENT:
            }
        }
        SDL_GL_SwapWindow(m_window);
        SDL_Delay(16);
    }

    bool Window::GetState()
    {
        return m_state;
    }

}
