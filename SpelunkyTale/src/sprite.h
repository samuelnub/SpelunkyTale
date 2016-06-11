//
//  sprite.hpp
//  SpelunkyTale
//
//  Created by Sam Yap on 09/06/2016.
//  Copyright © 2016 Sam Nub. All rights reserved.
//

#pragma once
#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>
#include <string>

class Graphics;

class Sprite
{
private:

    
public:
    Sprite();
    Sprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height, float posX, float posY);
    virtual ~Sprite();
    virtual void update();
    void draw(Graphics &graphics, int x, int y);
    
protected:
    SDL_Rect _sourceRect;
    SDL_Texture* _spriteSheet;
    
    
    float _x;
    float _y;

};

#endif
