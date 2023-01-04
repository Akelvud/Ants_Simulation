#include "Ant.h"


#define PI 3.14159265

Ant::Ant() {
    x_ = 0;
    y_ = 0;
}

Ant::Ant(int sx, int sy) : x_(sx), y_(sy) {

    double rd = (rand() % 1000);
    if (rd != 0) rd /= 1000;
    dAngle_ = 360.0 * rd;

}

int Ant::GetX() {return (int)x_;}
int Ant::GetY() {return (int)y_;}

void Ant::Move() {
    double newAngel = dAngle_;

    double rd = (rand() % 1000);
    if (rd != 0) rd /= 1000;
    if (rand() % 2) rd *= -1;

    newAngel += 20.0 * rd;

    x_ = x_ + cos(newAngel * PI / 180.0);
    y_ = y_ + sin(newAngel * PI / 180.0);
}



