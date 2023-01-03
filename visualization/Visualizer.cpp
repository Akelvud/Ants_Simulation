#include "Visualizer.h"

int Visualizer::SCREEN_WIDTH_ = 900;
int Visualizer::SCREEN_HEIGHT_ = 600;

SDL_Window *Visualizer::win_ = NULL;
SDL_Renderer *Visualizer::ren_ = NULL;


bool Visualizer::Init() {
    bool ok = true;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        cout << "Can't init SDL: " << SDL_GetError() << endl;
    }

    win_ = SDL_CreateWindow("Ants Simulation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH_, SCREEN_HEIGHT_, SDL_WINDOW_SHOWN);
    if (win_ == NULL) {
        cout << "Can't create window: " << SDL_GetError() << endl;
        ok = false;
    }

    ren_ = SDL_CreateRenderer(win_, -1, SDL_RENDERER_ACCELERATED);
    if (ren_ == NULL) {
        cout << "Can't create renderer: " << SDL_GetError() << endl;
        ok = false;
    }
    return ok;
}

void Visualizer::Quit() {
    SDL_DestroyWindow(win_);
    win_ = NULL;

    SDL_DestroyRenderer(ren_);
    ren_ = NULL;

    SDL_Quit();
}
