//
//  graphics.cpp
//  SpelunkyTale
//
//  Created by Sam Yap on 09/06/2016.
//  Copyright © 2016 Sam Nub. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "graphics.h"
#include "globals.h"

Graphics::Graphics()
{
    SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, 0, &this->_window, &this->_renderer);
    SDL_SetWindowTitle(this->_window, "Spelunky Tale");
    std::cout << "Successfully made the SDL window!\n";
}

Graphics::~Graphics()
{
    SDL_DestroyWindow(this->_window);
}

SDL_Surface* Graphics::loadImage(const std::string &filePath)
{
    if(this->_spriteSheets.count(filePath) == 0) //if nothings loaded
    {
        this->_spriteSheets[filePath] = IMG_Load(filePath.c_str());
    }
    return this->_spriteSheets[filePath];
}

void Graphics::blitSurface(SDL_Texture *texture, SDL_Rect *sourceRectangle, SDL_Rect *destinationRectangle)
{
    SDL_RenderCopy(this->_renderer, texture, sourceRectangle, destinationRectangle);
}

void Graphics::flip()
{
    SDL_RenderPresent(this->_renderer);
}

void Graphics::clear()
{
    SDL_RenderClear(this->_renderer);
}

SDL_Renderer* Graphics::getRenderer() const
{
    return this->_renderer;
}