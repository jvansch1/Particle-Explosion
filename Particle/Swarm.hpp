//
//  Swarm.hpp
//  Particle
//
//  Created by John VanSchultz on 10/5/17.
//  Copyright © 2017 John VanSchultz. All rights reserved.
//

#ifndef Swarm_hpp
#define Swarm_hpp

#include <stdio.h>
#include "Particle.hpp"

namespace jvs {
    class Swarm {
    private:
        // Pointer to paticle;
        Particle *m_pParticles;
    public:
        const static int NPARTICLES = 5000;
        const Particle * const getParticles() { return m_pParticles; };
        ~Swarm();
        Swarm();
    };
}

#endif /* Swarm_hpp */
