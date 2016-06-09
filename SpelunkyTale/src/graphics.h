//
//  graphics.h
//  SpelunkyTale
//
//  Created by Sam Yap on 09/06/2016.
//  Copyright © 2016 Sam Nub. All rights reserved.
//

#pragma once
#ifndef GRAPHICS_H
#define GRAPHICS_H

struct SDL_Window;
struct SDL_Renderer;

class Graphics
{
private:
    SDL_Window* _window;
    SDL_Renderer* _renderer;
    
public:
    Graphics();
    ~Graphics();
    
};

#endif