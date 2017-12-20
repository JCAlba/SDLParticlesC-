//
//  Particle.h
//  SDLProject
//
//  Created by Juan Carlos Albahaca on 2017-12-20.
//  Copyright © 2017 Juan Carlos Albahaca. All rights reserved.
//

#ifndef Particle_h
#define Particle_h

#include <stdlib.h>

namespace jca {
    struct Particle {
        double m_x;
        double m_y;
    public:
        Particle();
        virtual~Particle();
    };
    Particle::Particle() {
        m_x = ((2.0*rand())/RAND_MAX) -1;
        m_y = ((2.0*rand())/RAND_MAX) -1;
    }
    Particle::~Particle() {
        
    }
}


#endif /* Particle_h */
