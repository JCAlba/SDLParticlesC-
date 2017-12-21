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
#include <math.h>

namespace jca {
    struct Particle {
        double m_x;
        double m_y;
        
    private:
        double m_speed;
        double m_direction;
    private:
        void init();
    public:
        Particle();
        virtual~Particle();
        void update(int interval);
    };
    Particle::Particle(): m_x(0), m_y(0) {
        init();
    }
    
    void Particle::init() {
        m_x = 0;
        m_y = 0;
        m_direction = (2*M_PI*rand())/RAND_MAX;
        m_speed = (0.04 *rand())/RAND_MAX;
        m_speed *= m_speed;
    }
    Particle::~Particle() {
        
    }
    void Particle::update(int interval) {
        m_direction += interval* .0004;
        
        double xspeed = m_speed * cos(m_direction);
        double yspeed = m_speed * sin(m_direction);
        
        m_x += xspeed*interval;
        m_y += yspeed*interval;
        
        if(m_x <-1 || m_x > 1 || m_y < -1 || m_y > 1) {
            init();
        }
        if(rand() < RAND_MAX/100) {
            init();
        }
    }
}


#endif /* Particle_h */
