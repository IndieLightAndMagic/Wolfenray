#include <iostream>
#ifdef __APPLE__
#include <OpenGL/gl3.h>
#include <OpenGL/glext.h>
#else 
#include <OpenGL/gl.h>
#endif /*__APPLE__*/

#include <SDLWrapper/sdlwrapper.h>
#include "timer.h"

using namespace GTech;

namespace GAME{
    void GameInitialization();
    void MainLoop();
}



int main(int argc, char **argv) {

    /* Init Game Technology */
    SDLInitialization();
    std::cout << "GL SHADING LANGUAGE VERSION: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << " " << glGetString(GL_VERSION) << std::endl; 


    /* Initialization of the game */
    GAME::GameInitialization();
    GAME::MainLoop();



    /* Finish all the tech system (SDL for this case) */
    SDLQuit();
    return 0;
}
