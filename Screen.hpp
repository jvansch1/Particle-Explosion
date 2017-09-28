//
//  Screen.hpp
//  Particle
//
//  Created by John VanSchultz on 9/27/17.
//  Copyright © 2017 John VanSchultz. All rights reserved.
//

#ifndef Screen_hpp
#define Screen_hpp
#include <SDL2/SDL.h>

#include <stdio.h>

namespace jvs {
    class Screen {
    public:
        const static int SCREEN_WIDTH = 800;
        const static int SCREEN_HEIGHT = 600;
    private:
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;
        SDL_Texture *m_texture;
        Uint32 *m_buffer;
    public:
        Screen();
        bool init();
        void close();
        bool processEvents();
    };
}



#endif /* Screen_hpp */
