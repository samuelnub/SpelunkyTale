//
//  level.cpp
//  SpelunkyTale
//
//  Created by Sam Yap on 13/06/2016.
//  Copyright © 2016 Sam Nub. All rights reserved.
//

#include "level.h"
#include "graphics.h"

Level::Level()
{
    
}

Level::Level(std::string mapName, Vector2 spawnPoint, Graphics &graphics) : _mapName(mapName), _spawnPoint(spawnPoint), _size(Vector2(0, 0))
{
    this->loadMap(mapName, graphics);
}

Level::~Level()
{
    
}

void Level::loadMap(std::string mapName, Graphics &graphics)
{
    //TODO: temp to just load background
    this->_backgroundTexture = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage("/assets/backgrounds/bkBlue.png"));
    this->_size = Vector2(1280, 960);
}

void Level::update(int elapsedTime)
{
    
}

void Level::draw(Graphics &graphics)
{
    //draw background
    SDL_Rect sourceRect = {0, 0, 64, 64};
    SDL_Rect destRect;
    
    //we need to loop and draw this in multiple spots
    for(int x = 0; x < this->_size.x / 64; x++)
    {
        for(int y = 0; y < this->_size.y / 64; y++)
        {
            destRect.x = x * 64;
            destRect.y = y * 64;
            destRect.w = 64;
            destRect.h = 64;
            graphics.blitSurface(this->_backgroundTexture, &sourceRect, &destRect);
        }
    }
}