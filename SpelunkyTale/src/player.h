//
//  player.hpp
//  SpelunkyTale
//
//  Created by Sam Yap on 11/06/2016.
//  Copyright © 2016 Sam Nub. All rights reserved.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "animatedsprite.h"

class Graphics;

class Player : public AnimatedSprite
{
private:
    float _dx;//delta x, aka change in x
    float _dy;
    
    Direction _facing;
    
public:
    Player();
    Player(Graphics &graphics, float x, float y);
    void draw(Graphics &graphics);
    void update(float elapsedTime);
    
    virtual void animationDone(std::string currentAnimation);
    virtual void setupAnimation();
    
    void moveLeft(); //moves player by -dx
    void moveRight(); //moves player by dx
    void stopMoving(); //stops moving player and plays idle anim
};


#endif
