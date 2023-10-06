#ifndef POINT_H
#define POINT_H

class Point {
    private:
        int x;
        int y;
    public:
        //constructors
        Point();
        Point(int abs, int ord);
        //accessors
        int get_x() const;
        int get_y() const;
        //member functions
        void show() const;
        double distance_(Point b) const;
};

#endif