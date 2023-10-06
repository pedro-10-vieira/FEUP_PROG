#ifndef COLOR_H
#define COLOR_H

class Color {
    private:
        unsigned char vermelho, verde, azul;
    
    public:
        //constructors
        Color(unsigned char red, unsigned char green, unsigned char blue);
        Color(const Color& c);
        //accessors
        unsigned char red() const;
        unsigned char green() const;
        unsigned char blue() const;
        //static constants
        static const Color RED, GREEN, BLUE, BLACK, WHITE;
        //member functions
        bool equal_to(const Color& other) const;
        void invert();
};

#endif