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
    int x_;
    int y_;
    int lastX_;
    int lastY_;
};


#endif //ANTS_SIMULATION_ANT_H
