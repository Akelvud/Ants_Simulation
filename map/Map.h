#ifndef ANTS_SIMULATION_MAP_H
#define ANTS_SIMULATION_MAP_H

#include <iostream>
#include <vector>
#include "Point.h"
#include <set>
using namespace std;

class Map {
public:
    Map(int, int);
    pointType getPointType(int, int);
    int getWidth();
    int getHeight();

    void deleteFood(int, int);
    void changePheromone(int, int, double);
    double getPheromone(int, int);

    set<pair<int, int> > food;
    set<pair<int, int> > fer;
private:
    int width_;
    int height_;
    vector<vector<Point>> pointsMap_;

};


#endif //ANTS_SIMULATION_MAP_H
