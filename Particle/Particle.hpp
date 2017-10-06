//
//  Particle.hpp
//  Particle
//
//  Created by John VanSchultz on 10/5/17.
//  Copyright © 2017 John VanSchultz. All rights reserved.
//

#ifndef Particle_hpp
#define Particle_hpp

#include <stdio.h>

// struct is the same thing as class but
// variables and functions not specified as public
// or private default to private

namespace jvs {
    struct Particle {
    private:


    public:
        // double because want to be able to change value
        // gradually and round to nearest position
        double m_x;
        double m_y;
        Particle();
    };
};

#endif /* Particle_hpp */
