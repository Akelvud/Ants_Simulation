#ifndef ANTS_SIMULATION_ANT_H
#define ANTS_SIMULATION_ANT_H

#include <vector>
#include <iostream>

using namespace std;

class Ant {
public:
    Ant();
    Ant(int, int);
    int GetX();
    int GetY();

    void Move();

private:
    double x_;
    double  y_;
    double  dx_ = 0;
    double  dy_ = 0;
};


#endif //ANTS_SIMULATION_ANT_H
