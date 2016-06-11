//
//  globals.h
//  SpelunkyTale
//
//  Created by Sam Yap on 09/06/2016.
//  Copyright © 2016 Sam Nub. All rights reserved.
//

#pragma once
#ifndef GLOBALS_H
#define GLOBALS_H

namespace globals
{
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    
    const int SPRITE_SCALE = 2;
}

enum Direction
{
    LEFT,
    RIGHT,
    UP,
    DOWN
};

struct Vector2
{
    int x;
    int y;
    Vector2() : x(0), y(0)
    {
        
    }
    
    Vector2(int x, int y) : x(x), y(y)
    {
        
    }
    
    Vector2 zero()
    {
        return Vector2(0, 0);
    }
};


#endif
