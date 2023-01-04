#include "Ant.h"

Ant::Ant() {
    x_ = 0;
    y_ = 0;
}

Ant::Ant(int sx, int sy) : x_(sx), y_(sy) {}

int Ant::GetX() {return x_;}
int Ant::GetY() {return y_;}

void Ant::Move() {
    vector<pair<int, int> > availPos;
    for (int x = x_ - 1; x <= x_ + 1; x++) {
        for (int y = y_ - 1; y <= y_ + 1; y++) {
            if (x != lastX_ || y != lastY_) {
                availPos.push_back({x, y});
            }
        }
    }

    int randI = rand() % availPos.size();

    lastX_ = x_;
    lastY_ = y_;

    x_ = availPos[randI].first;
    y_ = availPos[randI].second;
}
