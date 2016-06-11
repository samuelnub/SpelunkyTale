//
//  game.cpp
//  SpelunkyTale
//
//  Created by Sam Yap on 09/06/2016.
//  Copyright © 2016 Sam Nub. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include "game.h"
#include "graphics.h"
#include "input.h"

namespace
{
    const int FPS = 50;
    const int MAX_FRAME_TIME = 5 * 1000 / FPS;
}



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
    
    this->_player = Player(graphics, 100, 100);
    
    
    int LAST_UPDATE_TIME = SDL_GetTicks();
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
        else if(input.isKeyHeld(SDL_SCANCODE_LEFT) == true)
        {
            _player.moveLeft();
        }
        else if(input.isKeyHeld(SDL_SCANCODE_RIGHT) == true)
        {
            _player.moveRight();
        }
        
        if(!input.isKeyHeld(SDL_SCANCODE_LEFT) && !input.isKeyHeld(SDL_SCANCODE_RIGHT))
        {
            this->_player.stopMoving();
        }
        
        
        //right before end of loop, log how long it took to push out this frame
        const int CURRENT_TIME_MS = SDL_GetTicks();
        int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
        this->update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
        LAST_UPDATE_TIME = CURRENT_TIME_MS;
        
        this->draw(graphics);
    }
    
    
    
}

void Game::draw(Graphics &graphics)
{
    graphics.clear();
    this->_player.draw(graphics);
    graphics.flip();
}

void Game::update(float elapsedTime)
{
    this->_player.update(elapsedTime);
}