#include "Ant.h"

Ant::Ant() {
    x_ = 0;
    y_ = 0;
}

Ant::Ant(int sx, int sy) : x_(sx), y_(sy) {

    dx_ = rand() % 10000;
    if (dx_ != 0) dx_ /= 9999;
    dy_ = sqrt(1.0 - dx_ * dx_);

    if (rand() % 2) dx_ *= -1;
    if (rand() % 2) dy_ *= -1;

}

int Ant::GetX() {return (int)x_;}
int Ant::GetY() {return (int)y_;}

void Ant::Move() {
    x_ = x_ + dx_;
    y_ = y_ + dy_;
}



