//
//  Particle.cpp
//  Particle
//
//  Created by John VanSchultz on 10/5/17.
//  Copyright © 2017 John VanSchultz. All rights reserved.
//

#include "Particle.hpp"
#include <stdlib.h>

namespace jvs {
    Particle::Particle() {
        // random number between 0 and 1
        m_x = (2.0 * rand()/RAND_MAX) - 1;
        m_y = (2.0 * rand()/RAND_MAX) - 1;
    }
}
