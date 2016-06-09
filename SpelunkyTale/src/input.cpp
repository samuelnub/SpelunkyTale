//
//  input.cpp
//  SpelunkyTale
//
//  Created by Sam Yap on 09/06/2016.
//  Copyright © 2016 Sam Nub. All rights reserved.
//

#include "input.h"

void Input::beginNewFrame()
{
    //resets key events every frame, keeps currently held ones though, until further notice
    this->_pressedKeys.clear();
    this->_releasedKeys.clear();
    
}

void Input::keyDownEvent(const SDL_Event& event)
{
    this->_pressedKeys[event.key.keysym.scancode] = true;
    this->_heldKeys[event.key.keysym.scancode] = true;
    
}

void Input::keyUpEvent(const SDL_Event &event)
{
    this->_releasedKeys[event.key.keysym.scancode] = true;
    this->_heldKeys[event.key.keysym.scancode] = false;
    
}

bool Input::wasKeyPressed(SDL_Scancode key)
{
    return this->_pressedKeys[key];
}

bool Input::wasKeyReleased(SDL_Scancode key)
{
    return this->_releasedKeys[key];
}

bool Input::isKeyHeld(SDL_Scancode key)
{
    return this->_heldKeys[key];
}