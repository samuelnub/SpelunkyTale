//
//  level.hpp
//  SpelunkyTale
//
//  Created by Sam Yap on 13/06/2016.
//  Copyright © 2016 Sam Nub. All rights reserved.
//

#ifndef LEVEL_H
#define LEVEL_H

#include <SDL2/SDL.h>
#include <string>
#include "globals.h"

class Graphics;
struct SDL_Texture;

class Level
{
private:
    std::string _mapName;
    Vector2 _spawnPoint;
    
    Vector2 _size;
    
    SDL_Texture* _backgroundTexture;
    
    void loadMap(std::string mapName, Graphics &graphics); //private cause were gonna call it within the level class
    
public:
    Level();
    Level(std::string mapName, Vector2 spawnPoint, Graphics &graphics);
    ~Level();
    
    void update(int elapsedTime);
    void draw(Graphics &graphics);
};


#endif
