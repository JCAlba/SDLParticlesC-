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
        int lastTime;
    public:
        Swarm();
        virtual~Swarm();
        const Particle * const getParticles() { return m_pParticles;}
        void update(int elapsed);
    };
    
    Swarm::Swarm(): lastTime(0) {
        m_pParticles = new Particle[NPARTICLES];
    }
    
    Swarm::~Swarm() {
        delete [] m_pParticles;
    }
    
    void Swarm::update(int elapsed) {
        
        int interval = elapsed - lastTime;
        
        for(int i = 0; i<Swarm::NPARTICLES; i++){
            m_pParticles[i].update(interval);
        }
        
        lastTime = elapsed;
    }
}

#endif /* Swarm_h */
