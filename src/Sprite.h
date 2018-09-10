#ifndef __SHIP__
#define __SHIP__

#include <sdlwrapper.h>

#include <set>
#include <SDL2_image/SDL_image.h>

#include <ECS/Component/entityinformationcomponent.h>
#include <ECS/Component/texturecomponent.h>
#include <ECS/Component/componentmanager.h>

#include <ECS/Entity/entitymanager.h>

namespace GTech{


    class Sprite {

    public:

        static unsigned int CreateSprite(std::string path);
        static void SetPosition(unsigned int shipId, glm::vec3 position);
        static void SetAnchorPoint(unsigned int shipId, glm::vec3 anchor);
        static void SetScale(unsigned int shipId, float scale);
        static void SetLifeSpan(unsigned int shipId, float milliseconds);

    };
}


#endif /* __SHIP__ */