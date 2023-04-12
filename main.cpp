#include "visualization/Visualizer.h"
#include "objects/Ant.h"
#include "map/Map.h"
#include <ctime>
#include <algorithm>

using namespace std;

const int antCount = 100;
const int width = 900;
const int height = 600;

int main(int32_t arhc, char ** argv) {
    srand(time(NULL));

    Visualizer::Init(width, height);
    Map* map = new Map(width, height);


    vector<Ant> ants;

    for (int i = 0; i < antCount; i++) {
        ants.push_back(Ant(width / 2, height / 2, map));
    }

    vector<vector<Color>> mc(width,vector<Color>(height));
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            mc[i][j] = Color(255, 255, 255);
        }
    }

    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            pointType type = map->getPointType(x,y);

            if (type == pointType::EMPTY) {
                mc[x][y] = Color(255, 255, 255);
            }

            int p = map->getPheromone(x, y);
            if (p != 0) {
                double nc = 255.0 / 10.0 * p;
                mc[x][y] = Color(255, 255 - int(nc) , 255 - int(nc));
            }
            if (type == pointType::HOME) {
                mc[x][y] = Color(0, 0, 255);
            }
            if (type == pointType::FOOD) {
                mc[x][y] = Color(0, 255, 0);
            }
        }
    }

    Visualizer::Render(mc);
    cout << 1 << endl;
    SDL_Event e;
    bool run = true;

    int tick = 0;
    while(run) {

        while (SDL_PollEvent(&e) != NULL) {
            if (e.type == SDL_QUIT) {
                run = false;
            }
        }
        if (1) {

            for (int i = 0; i < antCount; i++) {
                int x = ants[i].GetX();
                int y = ants[i].GetY();
                if (x >= 0 && y >= 0 && x < width && y < height
                && map->getPointType(x, y) == pointType::EMPTY) {
                    Visualizer::PixelDraw(x, y, {255, 255, 255});
                }
            }

            for (auto pos : map->food) {
                int x = pos.first;
                int y = pos.second;
                Visualizer::PixelDraw(x, y, {255,255,255});
            }
            map->food.clear();

            set<pair<int, int> > nFer;
            for (auto pos: map->fer) {
                int x = pos.first;
                int y = pos.second;

                map->changePheromone(x, y, -0.05);
                int p = map->getPheromone(x, y);
                if (p != 0) {
                    nFer.insert(pos);
                }

                double nc = 255.0 / 10.0 * p;
                Visualizer::PixelDraw(x, y, Color(255, 255 - int(nc) , 255 - int(nc)));
            }

            map->fer.clear();
            map->fer = nFer;

        }

        for (int i = 0; i < antCount; i++) {
            ants[i].Move();
        }

        for (int i = 0; i < antCount; i++) {
            int x = ants[i].GetX();
            int y = ants[i].GetY();
            if (x >= 0 && y >= 0 && x < width && y < height &&
            map->getPointType(x, y) == pointType::EMPTY)  {
                Visualizer::PixelDraw(x, y, {0, 0, 0});
            }
        }
        Visualizer::RenderPresent();

        tick++;
    }

    Visualizer::Quit();
    return 0;
}
