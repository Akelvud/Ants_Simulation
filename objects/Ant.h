#ifndef ANTS_SIMULATION_ANT_H
#define ANTS_SIMULATION_ANT_H

#include <vector>
#include <iostream>
#include "../map/Map.h"
#include <cmath>

using namespace std;

class Ant {
public:
    Ant();
    Ant(int, int, Map*);
    int GetX();
    int GetY();

    void Move();

private:
    Map* map_;
    double x_;
    double y_;
    double dAngle_ = 0;
    bool search_ = 1;
    bool out_ = 0;
    bool fHome_ = 0;
    bool fSl = 0;
    double fer_ = 1.;
    double minFer_ = 1.;
    double maxFer_ = 2.;
    double sFer_ = 0.02;
    vector<pair<double, double> > way_;

    void genAngle();
    void changeAngle();
};


#endif //ANTS_SIMULATION_ANT_H
