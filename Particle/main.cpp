//
//  main.cpp
//  Particle
//
//  Created by John VanSchultz on 8/25/17.
//  Copyright © 2017 John VanSchultz. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>

int main() {
    int const SCREEN_WIDTH = 800;
    int const SCREEN_HEIGHT = 600;
    
    SDL_Init(SDL_INIT_VIDEO);
    
    SDL_Window *window = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    
    if (window == NULL) {
        std::cout << "Could not create window" << SDL_GetError() << std::endl;
        return 1;
    } else {
        std::cout << "Window created" << std::endl;
    }
    
    // -1 is index
    SDL_Renderer *m_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    SDL_Texture *m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
    
    if (m_renderer == NULL) {
        std::cout << "Could not create renderer" << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        
        return 1;
    }
    
    if (m_texture == NULL) {
        std::cout << "Could not create texture" << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    
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
    
    SDL_DestroyTexture(m_texture);
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}
