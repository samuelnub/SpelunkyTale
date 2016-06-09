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

#include <map>
#include <string>

struct SDL_Window;
struct SDL_Renderer;

class Graphics
{
private:
    SDL_Window* _window;
    SDL_Renderer* _renderer;
    
    std::map<std::string, SDL_Surface*> _spriteSheets;
    
public:
    Graphics();
    ~Graphics();
    
    //load image into spritesheet map if it doesnt already exist, image will only be loaded once, saves loads of processing time
    SDL_Surface* loadImage(const std::string &filePath);

    //draws texture coords to destination area of screen
    void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);
    
    //renders everything in renderer to screen
    void flip();
    
    //clears the screen, nimbo
    void clear();
    
    //return renderer so we can use it elsewhere
    SDL_Renderer* getRenderer() const;
};

#endif