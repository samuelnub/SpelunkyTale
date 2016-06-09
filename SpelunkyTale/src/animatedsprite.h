//
//  animatedsprite.hpp
//  SpelunkyTale
//
//  Created by Sam Yap on 09/06/2016.
//  Copyright © 2016 Sam Nub. All rights reserved.
//

#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include <map>
#include <string>
#include <vector>
#include "sprite.h"
#include "globals.h"

class Graphics;

class AnimatedSprite : public Sprite
{
private:
    std::map<std::string, std::vector<SDL_Rect>> _animations; //the vector holds each frame of the anim in the spritesheet
    std::map<std::string, Vector2> _offsets;
    
    int _frameIndex;
    double _timeElapsed;
    bool _visible;
    
public:
    AnimatedSprite();
    AnimatedSprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height, float posX, float posY, float timeToUpdate);
    
    void playAnimation(std::string animation, bool once = false);

    //updates animated sprite with timer
    void update(int elapsedTime);
    
    void draw(Graphics &graphics, int x, int y);
    
    //required function (thats why its virtual) that sets up all anims for a sprite
    virtual void setupAnimation();
    
protected:
    double _timeToUpdate;
    bool _currentAnimationOnce;
    std::string _currentAnimation;
    
    //adds anim to the map
    void addAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offset);
    
    //resets all anims related to this sprite
    void resetAnimation();
    
    void stopAnimation();
    
    void setVisible(bool visible);
    
    //stuff that happens when anim finishes
    virtual void animationDone(std::string currentAnimation);
};

#endif
