#include "Color.h"

Color::Color(unsigned char red, unsigned char green, unsigned char blue) {
    vermelho = red;
    verde = green;
    azul = blue;
}

Color::Color(const Color& c) {
    vermelho = c.red();
    verde = c.green();
    azul = c.blue();
}

unsigned char Color::red() const {
    return vermelho;
}
unsigned char Color::green() const {
    return verde;
}
unsigned char Color::blue() const {
    return azul;
}

const Color Color::RED = {255, 0, 0};
const Color Color::GREEN= {0, 255, 0};
const Color Color::BLUE = {0, 0, 255};
const Color Color::BLACK = {0, 0, 0};
const Color Color::WHITE = {255, 255, 255};

bool Color::equal_to(const Color& other) const{
    if (vermelho == other.red() && verde == other.green() && azul == other.blue()) {
        return true;
    }
    return false;
}

void Color::invert() {
    vermelho = 255 - vermelho;
    verde = 255 - verde;
    azul = 255 - azul;
}