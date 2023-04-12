#include "Ant.h"
#include "algorithm"

#define PI 3.14159265

double getAngle(double vx, double vy) {
    double cAngle;
    if (vx == 0 && vy == 0) return 0.;
    cAngle = atan2(vy,vx) * 180. / PI;
    return cAngle;
}

Ant::Ant() {
    x_ = 0;
    y_ = 0;
}

void Ant::genAngle() {
    fSl = 0;
    double rd = (rand() % 1000);
    if (rd != 0) rd /= 1000;
    dAngle_ = 360.0 * rd;
    double  vx = 2 * cos(dAngle_ * PI / 180.0);
    double vy = 2 * sin(dAngle_ * PI / 180.0);

    for (int dx = -20; dx <= 20; dx++) {
        for (int dy = -20; dy <= 20; dy++) {
            if (dx == 0 && dy == 0) continue;
            int x = int(x_) + dx;
            int y = int(y_) + dy;

            double op = 0.;
            if (map_->getPointType(x, y) == pointType::FOOD) op = 100;
            double p = map_->getPheromone(x, y);
            double r = sqrt(double(dx * dx) + double(dy * dy));
            double tvx = dx / r * double(p + op);
            double tvy = dy / r * double(p + op);


            vx += tvx;
            vy += tvy;
        }
    }

    if (vx == 0 && vy == 0) {
        double rd = (rand() % 1000);
        if (rd != 0) rd /= 1000;
        dAngle_ = 360.0 * rd;
    } else {
        dAngle_ = getAngle(vx, vy);
    }


    fHome_ = 0;
}



void Ant::changeAngle() {
     double vx = 0;
     double vy = 0;

     double nx = cos(dAngle_ * PI / 180.0);
     double ny = sin(dAngle_ * PI / 180.0);
     double oAngle = getAngle(nx,ny);

     double dist = 100;
     bool fFood = 0;

     for (int dx = -20; dx <= 20; dx++) {
         for (int dy = -20; dy <= 20; dy++) {
             if (dx == 0 && dy == 0) continue;
             int x = int(x_) + dx;
             int y = int(y_) + dy;

             double r = sqrt(double(dx * dx) + double(dy * dy));

             if (map_->getPointType(x, y) == pointType::FOOD) {
                if (dist > r) {
                    dist = r;
                    vx = dx;
                    vy = dy;
                }
                fFood = 1;
             }
             if (fFood) continue;
             double p = map_->getPheromone(x, y);
             double tvx = dx / r * double(p);
             double tvy = dy / r * double(p);

             double tAngle = getAngle(dx, dy);

             double o1 = min(oAngle, tAngle);
             double o2 = max(oAngle, tAngle);

             double  o = min(o2 - o1, o1 + 360. - o2);

             if (o > 60) continue;

             vx += tvx;
             vy += tvy;
         }
     }
    if (vx == 0 && vy == 0) {
        if (fSl == 1) {
            double rd = (rand() % 1000);
            if (rd != 0) rd /= 1000;
            if (rand() % 2) rd *= -1;
            dAngle_ += 45.0 * rd;
            fSl = 0;
        }
        return;
    }

    fSl = 1;
    dAngle_ = getAngle(vx, vy);

    double rd = (rand() % 1000);
    if (rd != 0) rd /= 1000;
    if (rand() % 2) rd *= -1;
    dAngle_ += 10. * rd;


}
Ant::Ant(int sx, int sy, Map* map) : x_(sx), y_(sy), map_(map) {
    genAngle();
}

int Ant::GetX() {return (int)x_;}
int Ant::GetY() {return (int)y_;}

void Ant::Move() {

    if (way_.empty()) {
        search_ = true;
    }
    if (search_) {
        changeAngle();

        double newAngle = dAngle_;

        double rd = (rand() % 1000);
        if (rd != 0) rd /= 1000;
        if (rand() % 2) rd *= -1;

        newAngle += 30.0 * rd;

        if (newAngle >= 360.0) {
            newAngle -= 360.;
        }
        if (newAngle < 0) {
            newAngle += 360;
        }


        x_ = x_ + cos(newAngle * PI / 180.0);
        y_ = y_ + sin(newAngle * PI / 180.0);

        if (x_ < 0 || x_ >= map_->getWidth()) {
            dAngle_ += 180;
            if (dAngle_ >= 360) {
                dAngle_ -= 360;
            }
        }
        if (y_ < 0 || y_ >= map_->getHeight()) {
            dAngle_ += 180;
            if (dAngle_ >= 360) {
                dAngle_ -= 360;
            }
        }

        way_.push_back({x_, y_});

        if (map_->getPointType(int(x_), int(y_)) == pointType::FOOD) {
            map_->deleteFood(int(x_), int(y_));
            map_->food.insert({int(x_), int(y_)});
            search_ = false;
            fer_ = maxFer_;
        } else
        if (map_->getPointType(int(x_), int(y_)) == pointType::HOME) {
            way_.clear();
            if (out_ == 1) {
                genAngle();
                fHome_ = 0;
            }
        } else {
            out_ = 1;
        }
    } else {

        double nx = 0;
        double ny = 0;

        double vx = 0;
        double vy = 0;
        bool fHome = 0;
        double dist = 1000;

        for (int dx = -20; dx <= 20; dx++) {
            for (int dy = -20; dy <= 20; dy++) {
                if (dx == 0 && dy == 0) continue;
                int x = int(x_) + dx;
                int y = int(y_) + dy;

                double r = sqrt(double(dx * dx) + double(dy * dy));

                if (map_->getPointType(x, y) == pointType::HOME) {
                    if (dist > r) {
                        vx = dx;
                        vy = dy;
                    }
                    fHome = 1;
                    fHome_ = 1;
                }
            }
        }

        if (fHome_) {
            double  newAngle = getAngle(vx, vy);
            nx = x_ + cos(newAngle * PI / 180.0);
            ny = y_ + sin(newAngle * PI / 180.0);

        } else {
            nx = way_.back().first;
            ny = way_.back().second;
            way_.pop_back();
        }

        if (int(nx) != x_ || int(ny) != y_) {
            map_->changePheromone(int(nx), int(ny), fer_);
            map_->fer.insert({int(nx), int(ny)});
            fer_ -= sFer_;
            fer_ = std::max(fer_, minFer_);
            x_ = nx;
            y_ = ny;
        }


        if (map_->getPointType(int(x_), int(y_)) == pointType::HOME) {
            search_ = true;
            way_.clear();
            out_ = 0;
            fHome_ = 0;
            genAngle();
        } else {
            out_ = 1;
        }
    }
}



