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
#include <stdlib.h>
#include <time.h>
#include "Screen.h"
#include "Swarm.h"
using namespace jca;

int main(int argc, const char * argv[]) {
    
    srand(static_cast<unsigned int>(time(NULL)));
    
    Screen screen;
    
    if(screen.init() == false) {
        std::cout << "\nError initialising SDL" << std::endl;
    }
    
    Swarm swarm;
    
    while(true){
        //Update particles
        //Draw Particles
        int elapsed = SDL_GetTicks();
        
        swarm.update(elapsed);
        
        unsigned char red = (unsigned char)((1 + sin(elapsed*.0007)) * 128);
        unsigned char green = (unsigned char)((1 + sin(elapsed*.0008)) * 128);
        unsigned char blue = (unsigned char)((1 + sin(elapsed*.0009)) * 128);
        
        const Particle * const pParticles = swarm.getParticles();
        for(int i = 0; i<Swarm::NPARTICLES; i++){
            Particle particle = pParticles[i];
            int x = (particle.m_x +1) * Screen::SCREEN_WIDTH/2;
            int y = particle.m_y * Screen::SCREEN_WIDTH/2 + Screen::SCREEN_HEIGHT/2;
            
            screen.setPixel(x, y, red, green, blue);
        }
        
        screen.boxBlur();
        screen.update();
        
        if(screen.processEvents()==false){
            break;
        }
        
    }
    
    screen.close();
    return 0;
}
