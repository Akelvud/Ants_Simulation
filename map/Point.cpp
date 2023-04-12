#include "Point.h"


Point::Point() {
    type_ = pointType::EMPTY;
}
pointType Point::getType() {
    return type_;
}
void Point::setType(pointType type) {
    type_ = type;
}

void Point::changePheromone(double a) {
    pheromone += a;
    if (pheromone < 0) pheromone = 0;
    if (pheromone >= 10) pheromone = 10;
}

double Point::getPheromone() {
    return pheromone;
}