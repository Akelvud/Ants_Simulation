#include "Color.h"

Color::Color() {
    r_ = 255;
    g_ = 255;
    b_ = 255;
}
Color::Color(int r, int g, int b) : r_(r), g_(g), b_(b) {};

int Color::GetR() const {return r_;}
int Color::GetG() const {return g_;}
int Color::GetB() const {return b_;}


bool Color::operator!=(const Color & elem) {
    return (GetR() != elem.GetR()) ||
            (GetG() != elem.GetG()) ||
            (GetB() != elem.GetB());
}