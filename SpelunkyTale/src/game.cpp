//
//  game.cpp
//  SpelunkyTale
//
//  Created by Sam Yap on 09/06/2016.
//  Copyright © 2016 Sam Nub. All rights reserved.
//

#include <SDL2/SDL.h>
#include "game.h"
#include "graphics.h"

Game::Game()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    this->gameLoop();
}

Game::~Game()
{
    
}

void Game::gameLoop()
{
    Graphics graphics;
    SDL_Event event;
    
    while(true)
    {
        if(SDL_PollEvent(&event) == true)
        {
            if(event.type == SDL_QUIT)
            {
                return;
            }
        }
    }
}

void Game::draw(Graphics &graphics)
{
    
}

void Game::update(float elapsedTime)
{
    
}