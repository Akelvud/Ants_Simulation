#ifndef ANTS_SIMULATION_VISUALIZER_H
#define ANTS_SIMULATION_VISUALIZER_H

#include <iostream>
#include <SDL.h>

using namespace std;

class Visualizer {
public:
    static bool Init();
    static void Quit();
private:
    static int SCREEN_WIDTH_;
    static int SCREEN_HEIGHT_;

    static SDL_Window *win_;
    static SDL_Renderer *ren_;
};


#endif //ANTS_SIMULATION_VISUALIZER_H
