#include "Engine.hpp"
#include <memory>
#include <iostream>
#include "../Sandbox/Game.hpp"

namespace Engine
{
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> m_window(nullptr, SDL_DestroyWindow);
    SDL_GLContext m_context;
    SDL_Event m_ev;
    unsigned int m_screenHeight, m_screenWidth;
    State m_engineState;

    void Init(uint32_t height, uint32_t width, std::string title)
    {

        /*m_window = nullptr;*/
        m_screenHeight = 768;
        m_screenWidth = 1366;
        m_engineState = Engine::RUNNING;

        std::cout << "Initializing Window..." << std::endl;
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

        m_window.reset(SDL_CreateWindow("VIDEO_GAME",
                                         SDL_WINDOWPOS_CENTERED,
                                         SDL_WINDOWPOS_CENTERED,
                                         m_screenWidth,
                                         m_screenHeight,
                                         SDL_WINDOW_OPENGL));
        if (!m_window)
        {
            std::cerr << "Failed to init SDL Window" << SDL_GetError()
                      << std::endl;
            SDL_Quit();
        }

        m_context = SDL_GL_CreateContext(m_window.get());

        if (!gladLoadGLLoader(SDL_GL_GetProcAddress))
        {
            std::cerr << "Failed to init GLAD" << std::endl;
            exit(EXIT_FAILURE);
        }
        glEnable(GL_DEPTH_TEST);
        glViewport(0, 0, m_screenWidth, m_screenHeight);
    }

    void Update()
    {
        SDL_GL_SwapWindow(m_window.get());
        SDL_Delay(16);
    }

    void Quit()
    {
        std::cout << "Closing..." << std::endl;
        SDL_GL_DeleteContext(m_context);
        SDL_DestroyWindow(m_window.get());
        SDL_Quit();
    }
    bool isRunning()
    {
        return Engine::m_engineState == Engine::RUNNING;
    }
    void Run()
    {
        Engine::Init(0, 0, "");

        while (Engine::isRunning())
        {
            Engine::processInput();
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | 
                    GL_DEPTH_BUFFER_BIT);
            // Game::run();
            Engine::Update();
        }

    }

    State getState()
    {
        return m_engineState;
    }

    unsigned int getScreenWidth()
    {
        return m_screenWidth;
    }

    unsigned int getScreenHeight()
    {
        return m_screenHeight;
    }

    void processInput()
    {
        // for now just handle closing window
        while (SDL_PollEvent(&m_ev))
        {
            switch (m_ev.type)
            {
            case SDL_QUIT:
                m_engineState = QUIT;
                break;
            case SDL_WINDOWEVENT:
                break;
            default:
                break;
            }
        }
    }

    /*SDL_Keycode getKeyDown()*/
    /*{*/
    /*    return keydown;*/
    /*}*/
    /**/
    /*SDL_Keycode getKeyUp()*/
    /*{*/
    /*    return keyup;*/
    /*}*/

}
