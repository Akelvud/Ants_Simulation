#include "visualization/Visualizer.h"

using namespace std;


int main(int32_t arhc, char ** argv) {


    Visualizer::Init(900, 600);

    vector<vector<Color>> mc(900,vector<Color>(600));

    for (int i = 0; i < 900; i++)
        for (int j = 0; j < 600; j++) {
            mc[i][j] = Color((i * j) % 255, i % 255, j % 255);
        }

    Visualizer::Render(mc);
    SDL_Delay(5000);

    Visualizer::Quit();
    return 0;
}
