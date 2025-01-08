#include "Input.hpp"

namespace Input
{
    int numKeys;
    const Uint8 *keyState = SDL_GetKeyboardState(&numKeys);

    bool keyPressed(SDL_Scancode sc)
    {
        return keyState[sc] == 1;
    }

}