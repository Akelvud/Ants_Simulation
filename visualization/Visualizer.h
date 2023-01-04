#ifndef ANTS_SIMULATION_VISUALIZER_H
#define ANTS_SIMULATION_VISUALIZER_H

#include <iostream>
#include <vector>
#include <SDL.h>

#include "Color.h"

using namespace std;

class Visualizer {
public:
    static bool Init(int, int);
    static void Quit();

    static void Render(vector<vector<Color> >&);
private:
    static int SCREEN_WIDTH_;
    static int SCREEN_HEIGHT_;

    static SDL_Window *win_;
    static SDL_Renderer *ren_;

    static vector<vector<Color> > lastColorMap_;
};


#endif //ANTS_SIMULATION_VISUALIZER_H
