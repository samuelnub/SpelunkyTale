//
//  graphics.cpp
//  SpelunkyTale
//
//  Created by Sam Yap on 09/06/2016.
//  Copyright © 2016 Sam Nub. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include "graphics.h"

Graphics::Graphics()
{
    SDL_CreateWindowAndRenderer(640, 480, 0, &this->_window, &this->_renderer);
    SDL_SetWindowTitle(this->_window, "Spelunky Tale");
    std::cout << "Successfully made the SDL window!\n";
}

Graphics::~Graphics()
{
    SDL_DestroyWindow(this->_window);
}