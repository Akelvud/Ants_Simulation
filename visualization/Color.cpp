#include "Color.h"


Color::Color(int r, int g, int b) : R_(r), G_(g), B_(b) {};

int Color::GetR() const {return R_;}
int Color::GetG() const {return G_;}
int Color::GetB() const {return B_;}


bool Color::operator!=(const Color & elem) {
    return (GetR() != elem.GetR()) ||
            (GetG() != elem.GetG()) ||
            (GetB() != elem.GetB());
}