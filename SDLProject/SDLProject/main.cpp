//
//  main.cpp
//  SDLProject
//
//  Created by Juan Carlos Albahaca on 2017-12-20.
//  Copyright © 2017 Juan Carlos Albahaca. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include "Screen.h"

int main(int argc, const char * argv[]) {
    
    jca::Screen screen;
    
    if(screen.init() == false) {
        std::cout << "\nError initialising SDL" << std::endl;
    }

    while(true){
        
        screen.setPixel(400, 300, 255, 255, 255);
        screen.update();
        
        if(screen.processEvents()==false){
            break;
        }
        
    }
    
    screen.close();
    return 0;
}
