#include <iostream>
#include <filesystem>
#include "../Benjen/src/Core/Application.h"
#include "../Benjen/src/Renderer/Shader.h"
#include "../Benjen/src/Renderer/Renderer.h"
#include <glad/glad.h>
/*
    Entry Point for Application
    This code will create a runtime for your game/application
    Pseudo Boilerplate:
        init systems
*/

class Sandbox : public BENJEN::Application
{
public:
    Sandbox(BENJEN::Specification spec)
        : BENJEN::Application(spec)
    {
    }
    void OnUpdate();
};
void Sandbox::OnUpdate()
{
    // this is where game logic would be updated,
    // render stuff only here until i create the proper abstractions
    // BENJEN::Shader basicShader;
    // u_int vao, vbo;
    // {
        
    //     basicShader.CreateProgram("res/shaders/vertex.vert", "res/shaders/fragment.frag");
    //     float vertices[] = {-0.5f, -0.5f, 0.0f,
    //                         0.5f, -0.5f, 0.0f,
    //                         0.0f, 0.5f, 0.0f};

        
    //     glGenVertexArrays(1, &vao);
    //     glGenBuffers(1, &vbo);
    //     glBindVertexArray(vao);
    //     glBindBuffer(GL_ARRAY_BUFFER, vbo);
    //     glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    //     glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    //     glEnableVertexAttribArray(0);

    //     glBindBuffer(GL_ARRAY_BUFFER, 0);
    //     glBindVertexArray(0);
    // }
    // glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // basicShader.Use();
    // glBindVertexArray(vao);
    // glDrawArrays(GL_TRIANGLES, 0, 3);
    BENJEN::Renderer::SetColor(0.2f, 0.3f, 0.3f, 1.0f);
}

int main(int argc, char **argv)
{
    std::cout << "Welcome to the North." << std::endl;
    BENJEN::Specification spec("Test App", 1280, 720);
    BENJEN::Application *sb = new Sandbox(spec);
    sb->Run();
    delete sb;
    return EXIT_SUCCESS;
}
