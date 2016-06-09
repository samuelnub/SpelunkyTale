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
#include "input.h"

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
    Input input;
    SDL_Event event;
    
    while(true)
    {
        input.beginNewFrame(); //reset press and release events
        
        if(SDL_PollEvent(&event) == true)
        {
            if(event.type == SDL_KEYDOWN)
            {
                if(event.key.repeat == 0)
                {
                    input.keyDownEvent(event);
                }
            }
            else if(event.type == SDL_KEYUP)
            {
                input.keyUpEvent(event);
            }
            else if(event.type == SDL_QUIT)
            {
                return;
            }
        }
        
        if(input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true)
        {
            return;
        }
        
        
    }
}

void Game::draw(Graphics &graphics)
{
    
}

void Game::update(float elapsedTime)
{
    
}