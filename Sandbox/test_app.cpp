#include <iostream>
#include <filesystem>
#include "../Benjen/src/core/Application.h"
#include <chrono>
#include <thread>
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
    std::cout << "Updating!!" << std::endl;
    // sleep
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
}

int main(int argc, char **argv)
{
    Sandbox *sb = new Sandbox();
    sb->Run();
    delete sb;
    return EXIT_SUCCESS;
}
