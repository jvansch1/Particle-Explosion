//
//  Screen.cpp
//  Particle
//
//  Created by John VanSchultz on 9/27/17.
//  Copyright © 2017 John VanSchultz. All rights reserved.
//

#include "Screen.hpp"
#include <iostream>


namespace jvs {
    Screen::Screen(): m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL) {

    }
    
    bool Screen::init() {
        
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            return false;
        };
        
        m_window = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        
        if (m_window == NULL) {
            std::cout << "Could not create window" << SDL_GetError() << std::endl;
            return false;
        } else {
            std::cout << "Window created" << std::endl;
        }
        
        m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
        m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
        
        if (m_renderer == NULL) {
            std::cout << "Could not create renderer" << std::endl;
            SDL_DestroyWindow(m_window);
            SDL_Quit();
            
            return false;
        }
        
        if (m_texture == NULL) {
            std::cout << "Could not create texture" << std::endl;
            SDL_DestroyWindow(m_window);
            SDL_Quit();
            return false;
        }
        
        Uint32 *buffer = new Uint32 [SCREEN_HEIGHT * SCREEN_WIDTH];
        
        memset(buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
        
        //    each FF pair is setting a value
        buffer[30000] = 0xFFFFFFFF;
        
        for (int i = 0; i < SCREEN_HEIGHT * SCREEN_WIDTH; i++) {
            buffer[i] = 0x0080FFFF;
        }
        
        bool quit = false;
        SDL_Event event;
        
        SDL_UpdateTexture(m_texture, NULL, buffer, SCREEN_WIDTH  * sizeof(Uint32));
        SDL_RenderClear(m_renderer);
        SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
        SDL_RenderPresent(m_renderer);
        return true;
    }
    
    bool Screen::processEvents() {
        return false;
    }
    
    void Screen::close() {
        delete [] m_buffer;
        SDL_DestroyTexture(m_texture);
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
    }
    
    
}
