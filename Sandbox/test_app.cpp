#include <iostream>
#include <filesystem>
#include "../Benjen/src/Core/Application.h"
#include "../Benjen/src/Renderer/Shader.h"
#include <glad/glad.h>
/*
    Entry Point for Application
    This code will create a runtime for your game/application
    Pseudo Boilerplate:
        init systems
*/

class Sandbox : public BENJEN::Application
{
    void OnUpdate();
};

void Sandbox::OnUpdate()
{
    // this is where game logic would be updated, 
    // render stuff only here until i create the proper abstractions
    BENJEN::Shader basicShader;
    basicShader.CreateProgram("res/shaders/vertex.vert", "res/shaders/fragment.frag");
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

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    basicShader.Use();
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

int main(int argc, char **argv)
{
    std::cout << "Welcome to the North." << std::endl;
    Sandbox *sb = new Sandbox();
    std::cout << "Constructed" << std::endl;
    sb->Run();
    delete sb;
    return EXIT_SUCCESS;
}
