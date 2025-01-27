#include <SDL2/SDL.h>
#include <glad/glad.h>
#include <iostream>
#include "../Renderer/Shader.h"
#include "Window.h"

int main(int argc, char **argv)
{
    BENJEN::Window test_window("App;Save;Me",1280, 720);
    BENJEN::Shader basicShader;
    basicShader.CreateProgram("res/shaders/vertex.glsl","res/shaders/fragment.glsl");
    float vertices[] = {-0.5f, -0.5f, 0.0f,
                        0.5f, -0.5f, 0.0f,
                        0.0f, 0.5f, 0.0f};

    u_int vao, vbo;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    while (test_window.GetState())
    {
        // while (SDL_PollEvent(&ev))
        // {
        //     switch (ev.type)
        //     {
        //     case SDL_QUIT:
        //         flag = false;
        //     }
        // }
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        basicShader.Use();
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        test_window.OnUpdate();
        // SDL_GL_SwapWindow(test_window);
        // SDL_Delay(16);
    }
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    // glDeleteProgram(shader);

    // SDL_GL_DeleteContext(context);
    // SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}