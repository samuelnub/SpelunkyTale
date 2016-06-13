//
//  game.hpp
//  SpelunkyTale
//
//  Created by Sam Yap on 09/06/2016.
//  Copyright © 2016 Sam Nub. All rights reserved.
//

#pragma once
#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "level.h"

class Graphics;

class Game
{
private:
    void gameLoop();
    void draw(Graphics &graphics);
    void update(float elapsedTime);
    
    Player _player;
    Level _level;
    
public:
    Game();
    ~Game();

};

#endif
