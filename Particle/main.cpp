//
//  main.cpp
//  Particle
//
//  Created by John VanSchultz on 8/25/17.
//  Copyright © 2017 John VanSchultz. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <math.h>
#include <time.h>
#include "Screen.hpp"
#include "Swarm.hpp"
#include "Particle.hpp"

int main() {
    
    srand(std::time(NULL));
    
    jvs::Screen screen = jvs::Screen();
    
    if (screen.init() == false) {
        std::cout << "Error initializing SDL";
    }

    bool quit = false;
    SDL_Event event;
    
    int max = 0;
    jvs::Swarm swarm;
    // main game loop. Will keep going until quit = true
    while(true) {
        // Update position or state of particles
        // Draw particles
        // check for messages/events
        
        
        
        
        int elapsed = SDL_GetTicks();
        unsigned char green =  128 * (1 + sin(elapsed * 0.0001));
        unsigned char red =  128 * (1 + sin(elapsed * 0.0002));
        unsigned char blue =  128 * (1 + sin(elapsed * 0.0003));
//
// 
//        std::cout << green << std::endl;
//        
//        if (green > max) {
//            max = green;
//        }
//        
//        for(int y = 0; y < jvs::Screen::SCREEN_HEIGHT; y++) {
//            for (int x = 0; x < jvs::Screen::SCREEN_WIDTH; x++) {
//                screen.setPixel(x, y, red, green, blue);
//            }
//        }
        const jvs::Particle * const pParticles = swarm.getParticles();
        for(int i = 0; i < swarm.NPARTICLES; i++) {
            jvs::Particle particle = pParticles[i];
            int x = (particle.m_x + 1) * (screen.SCREEN_WIDTH / 2);
            int y = (particle.m_y + 1) * (screen.SCREEN_HEIGHT / 2);
            screen.setPixel(x, y, red, green, blue);
        }
        
        
        // inside loop will look at all events
        // if loop is QUIT(pressing x on window) set quit to true
        
        screen.update();
        
        if (!screen.processEvents()) {
            break;
        }
    }
    
    std::cout << "Max" << max << std::endl;
    screen.close();
    return 0;
}
