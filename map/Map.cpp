#include "Map.h"


Map::Map(int width, int height) : width_(width), height_(height) {
     pointsMap_ = vector<vector<Point>>(width_,vector<Point>(height_));

     int cx = width_ / 2;
     int cy = height_ / 2;

     int fx = rand() % width_;
     int fy = rand() % height_;
     for (int x = 0; x < width_; x++) {
         for (int y = 0; y < width_; y++) {
             double dist;
             dist = sqrt(double((x - cx) * (x - cx) + (y - cy) * (y - cy)));
             if (dist <= 1) {
                 pointsMap_[x][y].setType(pointType::HOME);
             }


         }
     }

     for (int i = 0; i < 10; i++) {
         int fx = rand() % width_;
         int fy = rand() % height_;
         for (int x = 0; x < width_; x++) {
             for (int y = 0; y < width_; y++) {
                 double dist;
                 dist = sqrt(double((x - fx) * (x - fx) + (y - fy) * (y - fy)));
                 if (dist <= 10.) {
                     pointsMap_[x][y].setType(pointType::FOOD);
                 }

             }
         }
     }
     food.clear();
     fer.clear();
}

pointType Map::getPointType(int x, int y) {
    if (x < 0 || y < 0 || x >= width_ || y >= height_) return pointType::EMPTY;
    return pointsMap_[x][y].getType();
}

int Map::getWidth() {
    return width_;
}
int Map::getHeight() {
    return height_;
}

void Map::deleteFood(int x, int y) {
    if (x < 0 || y < 0 || x >= width_ || y >= height_) return;
    if (pointsMap_[x][y].getType() == pointType::FOOD) {
        pointsMap_[x][y].setType(pointType::EMPTY);
    }
}
void Map::changePheromone(int x, int y, double a) {
    if (x < 0 || y < 0 || x >= width_ || y >= height_) return;
    pointsMap_[x][y].changePheromone(a);
}

double Map::getPheromone(int x, int y) {
    if (x < 0 || y < 0 || x >= width_ || y >= height_) return 0;
    return pointsMap_[x][y].getPheromone();
}