#ifndef ANTS_SIMULATION_COLOR_H
#define ANTS_SIMULATION_COLOR_H


class Color {
public:
    Color() = default;
    Color(int, int, int);

    int GetR();
    int GetG();
    int GetB();
private:
    int R_;
    int G_;
    int B_;
};


#endif //ANTS_SIMULATION_COLOR_H
