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
    
    if (screen.init() == false) {
        std::cout << "Error initializing SDL";
    }

    bool quit = false;
    SDL_Event event;
    
    
    // main game loop. Will keep going until quit = true
    while(true) {
        // Update position or state of particles
        // Draw particles
        // check for messages/events
        
        for(int y = 0; y < jvs::Screen::SCREEN_HEIGHT; y++) {
            for (int x = 0; x < jvs::Screen::SCREEN_WIDTH; x++) {
                if(x % 2 == 0) {
                    screen.setPixel(x, y, 128, 0, 255);
                }
                
            }
        }
        
        // inside loop will look at all events
        // if loop is QUIT(pressing x on window) set quit to true
        

        screen.update();
        
        if (!screen.processEvents()) {
            break;
        }
    }
    screen.close();
    return 0;
}
