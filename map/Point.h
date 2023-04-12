#ifndef ANTS_SIMULATION_POINT_H
#define ANTS_SIMULATION_POINT_H


enum pointType{EMPTY = 0, HOME = 1, FOOD = 2};

class Point {
public:
    Point();
    pointType getType();
    void setType(pointType);

    void changePheromone(double);
    double getPheromone();
private:
    pointType type_;
    double pheromone = 0;
};


#endif //ANTS_SIMULATION_POINT_H
