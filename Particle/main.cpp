//
//  main.cpp
//  Particle
//
//  Created by John VanSchultz on 8/25/17.
//  Copyright © 2017 John VanSchultz. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include "Screen.hpp"

int main() {
    jvs::Screen screen = jvs::Screen();
    screen.init();

    
    bool quit = false;
    SDL_Event event;
    
    
    // main game loop. Will keep going until quit = true
    while(!quit) {
        // Update position or state of particles
        // Draw particles
        // check for messages/events
        
        // inside loop will look at all events
        // if loop is QUIT(pressing x on window) set quit to true
        while (SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                quit = true;
            }
        }
    }
    screen.close();
    return 0;
}
