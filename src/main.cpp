#include "entity.h"

#include "Tech.h"
#include "Tech_SDLBridge.h"


#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>


const int WIN_WIDTH = 640;
const int WIN_HEIGHT = 480;
const std::string TAG = "VoidSample";






SDL_Surface * LoadSurface (std::string ResourceName) {
    std::string localPath = std::string(RES_DIR) + ResourceName;
    SDL_Surface* pImageSurface = IMG_Load(localPath.c_str());
    return pImageSurface;
}

struct TextureComponent : public  Component {
    SDL_Surface* m_pSurface;
    TextureComponent(std::string textureFileName):
            m_pSurface(LoadSurface(textureFileName)){
        SDL_assert(m_pSurface!=nullptr);
    }

};
class PlayerEntity : public Entity {

public:
    PlayerEntity(std::string textureFileName){

    }
};

int main(int argc, char **argv) {
    
    /* System Start */
    GTech2D::Tech2D *ptech = GTech2D::Tech2DFactory::StartTechInstance();
    ptech->Init();

    GTech2D::WindowConfiguration windowConfiguration{
            "Rendering to a texture!",
            {
                    {WIN_WIDTH, WIN_HEIGHT},
                    {SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED}
            }
    };

    ptech->CreateWindow(windowConfiguration, 0);
    ptech->CreateRenderer();
    ptech->Assert(static_cast<Tech_SDLBridge*>(ptech)->InitImageLoading() == true);
    
    /* Load Assets */
    std::unique_ptr<GTech2D::Texture2D>spHeroTexture = ptech->LoadTexture("hero.png"); //LoadSurface("hero.png");
    GTech2D::Texture2D* pHeroTexture = spHeroTexture.get();

    SDL_Renderer*   renderer = static_cast<Tech_SDLBridge*>(ptech)->GetRenderer();
    SDL_Texture*    pngTex = static_cast<Texture2D_SDL*>(pHeroTexture)->Get();

    //Make a target texture to render too
    Uint32 pixelFormat;
    int access;
    SDL_Rect textureRect;
    {
        auto zero = SDL_QueryTexture(pngTex,&pixelFormat,&access,&textureRect.w, &textureRect.h);
        SDL_assert(zero == 0);
        textureRect.x = 0;
        textureRect.y = 0;

    }

    GTech2D::Texture2DSize textureSize{WIN_WIDTH, WIN_HEIGHT};
    std::unique_ptr<GTech2D::Texture2D> pATexture = ptech->CreateTexture(textureSize);
    SDL_Texture *texTarget = static_cast<Texture2D_SDL*>(pATexture.get())->Get();

    SDL_Rect texRect;
    {
        auto zero = SDL_QueryTexture(texTarget, &pixelFormat, &access, &texRect.w, &texRect.h);
        SDL_assert(zero == 0);
        textureRect.x = (texRect.w - textureRect.w) >> 1;
        textureRect.y = (texRect.h - textureRect.h) >> 1;
    }
    //Now render to the texture
    SDL_SetRenderTarget(renderer, texTarget);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, pngTex, NULL, NULL);
    //Detach the texture
    SDL_SetRenderTarget(renderer, NULL);

    //Now render the texture target to our screen, but upside down
    SDL_RenderClear(renderer);

    //Render in the Center.

    SDL_RenderCopyEx(renderer, texTarget, nullptr, &textureRect, 0, NULL, SDL_FLIP_NONE);
    SDL_RenderPresent(renderer);

    SDL_Delay(3000);
    ptech->DestroyTexture(pATexture);
    SDL_DestroyTexture(pngTex);
    ptech->Finish();
    return 0;
}
