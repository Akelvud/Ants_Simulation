#include "Visualizer.h"

int Visualizer::SCREEN_WIDTH_ = 0;
int Visualizer::SCREEN_HEIGHT_ = 0;

SDL_Window *Visualizer::win_ = NULL;
SDL_Renderer *Visualizer::ren_ = NULL;

vector<vector<Color> > Visualizer::lastColorMap_ = vector<vector<Color> > (0);

bool Visualizer::Init(int width, int height) {
    SCREEN_HEIGHT_ = height;
    SCREEN_WIDTH_ = width;

    lastColorMap_ = vector<vector<Color> > (width, (vector<Color>(height)));

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

    SDL_SetRenderDrawColor(ren_, 0xFF, 0xFF, 0xFF, 0x00);
    SDL_RenderClear(ren_);

    SDL_SetRenderDrawColor(ren_, 0, 0, 0, 0x00);

    return ok;
}

void Visualizer::Quit() {
    SDL_DestroyWindow(win_);
    win_ = NULL;

    SDL_DestroyRenderer(ren_);
    ren_ = NULL;

    SDL_Quit();
}

void Visualizer::Render(vector<vector<Color>>& ColorMap) {
    for (int i = 0; i < SCREEN_WIDTH_; i++) {
        for (int j = 0; j <  SCREEN_HEIGHT_; j++) {
            if (lastColorMap_[i][j] != ColorMap[i][j]) {
                lastColorMap_[i][j] = ColorMap[i][j];

                Color tc = lastColorMap_[i][j];
                SDL_SetRenderDrawColor(ren_, tc.GetR(), tc.GetG(), tc.GetB(), 0x00);
                SDL_RenderDrawPoint(ren_, i, j);
            }
        }
    }

    SDL_RenderPresent(ren_);
}