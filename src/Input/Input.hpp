#ifndef INPUT_HPP
#define INPUT_HPP

//keyboard
#define W_KEY SDL_SCANCODE_W
#define A_KEY SDL_SCANCODE_A 
#define S_KEY SDL_SCANCODE_S
#define D_KEY SDL_SCANCODE_D
//gamepaD

//mouse

#include <SDL2/SDL.h>

/*
    Goals:
    1. for now focus on keyboard input, controller input in future
    2. interface for interacting with keystate array
*/
namespace Input
{
    bool keyPressed(SDL_Scancode sc);
    void Update(); //update keyboard state every frame
}
#endif