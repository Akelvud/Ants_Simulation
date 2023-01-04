#include "visualization/Visualizer.h"
#include "objects/Ant.h"
#include <ctime>

using namespace std;

const int antCount = 5000;
const int width = 900;
const int height = 600;

int main(int32_t arhc, char ** argv) {
    srand(time(NULL));

    Visualizer::Init(width, height);

    vector<Ant> ants;

    for (int i = 0; i < antCount; i++) {
        ants.push_back(Ant(width / 2, height / 2));
    }

    vector<vector<Color>> mc(width,vector<Color>(height));
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            mc[i][j] = Color(255, 255, 255);
        }
    }
    Visualizer::Render(mc);



    SDL_Event e;
    bool run = true;

    int tick = 0;
    while(run) {

        while (SDL_PollEvent(&e) != NULL) {
            if (e.type == SDL_QUIT) {
                run = false;
            }
        }

        vector<vector<Color>> mc(width,vector<Color>(height));
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                mc[i][j] = Color(255, 255, 255);
            }
        }


        for (int i = 0; i < antCount; i++) {
            int x = ants[i].GetX();
            int y = ants[i].GetY();
            if (x >= 0 && y >= 0 && x < width && y < height) {
                mc[x][y] = Color(0, 0, 0);
            }

            ants[i].Move();
        }

        Visualizer::Render(mc);
        //SDL_Delay(100);
        tick++;
    }

    Visualizer::Quit();
    return 0;
}
