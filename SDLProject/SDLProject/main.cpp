//
//  main.cpp
//  SDLProject
//
//  Created by Juan Carlos Albahaca on 2017-12-20.
//  Copyright © 2017 Juan Carlos Albahaca. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>

int main(int argc, const char * argv[]) {
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "\nSDL failed" << std::endl;
    }
    SDL_Window *window= SDL_CreateWindow("Particle explosions", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Quit();
    return 0;
}
