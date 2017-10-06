//
//  Swarm.cpp
//  Particle
//
//  Created by John VanSchultz on 10/5/17.
//  Copyright © 2017 John VanSchultz. All rights reserved.
//

#include "Swarm.hpp"

namespace jvs {
    Swarm::Swarm() {
        m_pParticles = new Particle[NPARTICLES];
    }
    
    Swarm::~Swarm() {
        delete [] m_pParticles;
    }
    
    
}
