//
//  Swarm.h
//  SDLProject
//
//  Created by Juan Carlos Albahaca on 2017-12-20.
//  Copyright © 2017 Juan Carlos Albahaca. All rights reserved.
//

#ifndef Swarm_h
#define Swarm_h
#include "Particle.h"

namespace jca {
    class Swarm {
    public:
        const static int NPARTICLES = 5000;
    private:
        Particle *m_pParticles;
    public:
        Swarm();
        virtual~Swarm();
        const Particle * const getParticles() { return m_pParticles;}
    };
    
    Swarm::Swarm() {
        m_pParticles = new Particle[NPARTICLES];
    }
    
    Swarm::~Swarm() {
        delete [] m_pParticles;
    }
}

#endif /* Swarm_h */
