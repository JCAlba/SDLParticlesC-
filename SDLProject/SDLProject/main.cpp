//
//  main.cpp
//  SDLProject
//
//  Created by Juan Carlos Albahaca on 2017-12-20.
//  Copyright © 2017 Juan Carlos Albahaca. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include <math.h>
#include "Screen.h"
using namespace jca;

int main(int argc, const char * argv[]) {
    
    Screen screen;
    
    if(screen.init() == false) {
        std::cout << "\nError initialising SDL" << std::endl;
    }
    
    while(true){
        //Update particles
        //Draw Particles
        int elapsed = SDL_GetTicks();
        unsigned char red = (unsigned char)((1 + sin(elapsed*.0007)) * 128);
        unsigned char green = (unsigned char)((1 + sin(elapsed*.0008)) * 128);
        unsigned char blue = (unsigned char)((1 + sin(elapsed*.0009)) * 128);
        
        for(int y = 0; y<Screen::SCREEN_HEIGHT; y++){
            for(int x = 0; x<Screen::SCREEN_WIDTH; x++) {
                screen.setPixel(x, y, red, green, blue);
            }
        }
        screen.update();
        
        if(screen.processEvents()==false){
            break;
        }
        
    }
    
    screen.close();
    return 0;
}
