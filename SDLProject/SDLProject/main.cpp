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
        return 1;
    }
    SDL_Window *window= SDL_CreateWindow("Particle explosions", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    
    if(window == NULL) {
        SDL_Quit();
        return 2;
    }
    
    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    SDL_Texture * texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC,  SCREEN_WIDTH, SCREEN_HEIGHT);
    
    bool quit = false;
    SDL_Event event;
    
    while(!quit){
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT){
                quit = true;
            }
        }
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
