#ifndef __TEXTURE2D_SDLBRIDGE__
#define __TEXTURE2D_SDLBRIDGE__
#include "Tech.h"

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include <iostream>

class Texture2D_SDL : public GTech2D::Texture2D {

    SDL_Texture* m_pTexture;
public:
    Texture2D_SDL(SDL_Texture* pTexture):m_pTexture(pTexture){
        std::cerr << "Texture2D_SDL ctor: THIS: 0x" << std::hex << this << std::dec << " : ";
        std::cerr << "Texture2D_SDL ctor: SDL_DestroyTexture 0x" << std::hex << m_pTexture << std::dec << "\n";

    }

    ~Texture2D_SDL() override {
        if (m_pTexture){
            SDL_DestroyTexture(m_pTexture);
            std::cerr << "Texture2D_SDL dtor: THIS: 0x" << std::hex << this << std::dec << " : ";
            std::cerr << "Texture2D_SDL dtor: SDL_DestroyTexture 0x" << std::hex << m_pTexture << std::dec << "\n";
            m_pTexture = nullptr;

        }
    }
    SDL_Texture* Get(){
        return m_pTexture;
    }

};
#endif /* __TEXTURE2D_SDLBRIDGE__ */