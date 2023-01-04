#ifndef ANTS_SIMULATION_COLOR_H
#define ANTS_SIMULATION_COLOR_H




class Color {
public:
    Color();
    Color(int, int, int);

    bool operator!=(const Color&);

    int GetR() const;
    int GetG() const;
    int GetB() const;
private:
    int r_;
    int g_;
    int b_;
};


#endif //ANTS_SIMULATION_COLOR_H
