#include <iostream>
#include <cmath>
using namespace std;

class Fraction {
    public:
        //constructors
        Fraction() {
            numerator_ = 0;
            denominator_ = 1;
        };
        Fraction(int numerator_, int denominator_) {
            int div_com = gcd(numerator_, denominator_);
            this-> numerator_ = numerator_ / div_com;
            this-> numerator_ = numerator_ / div_com;
            this-> numerator_ = numerator_;
            this-> denominator_ = denominator_;
        };
        //acessors
        int numerator() const {
            return numerator_;
        };
        int denominator() const {
            return denominator_;
        };
        //operation functions
        Fraction sum(const Fraction& right) {
            Fraction res = {numerator_ * right.denominator() + denominator_ * right.numerator(), denominator_ * right.denominator()};
            res.normalise();
            return res;
        };
        Fraction sub(const Fraction& right) {
            Fraction res = {numerator_ * right.denominator() - denominator_ * right.numerator(), denominator_ * right.denominator()};
            res.normalise();
            return res;
        };
        Fraction mul(const Fraction& right) {
            Fraction res = {numerator_ * right.numerator(), denominator_ * right.denominator()};
            res.normalise();
            return res;
        };
        Fraction div(const Fraction& right) {
            Fraction res = {numerator_ * right.denominator(), denominator_ * right.numerator()};
            res.normalise();
            return res;
        };
        //auxiliary functions
        int gcd(int numerator_, int denominator_);
        void normalise();
        void write() const;
    private:
        int numerator_;
        int denominator_;
};

//! Compute the gcd of two numbers.
int Fraction::gcd(int a, int b) {
  while (b != 0) {
    int tmp = a;
    a = b;
    b = tmp % b;
  }
  return a;
}

//! Normalize a fraction.
void Fraction::normalise() {
  int g = gcd(numerator_, denominator_);
  numerator_ /= g;
  denominator_ /= g;
  if (denominator_ < 0) {
    numerator_ = - numerator_;
    denominator_ = - denominator_;
  }
}

// shows fraction on the screen
void Fraction::write() const {
  cout << numerator_ << '/' << denominator_;
}

int main() {
    { Fraction().sum({2, 4}).write(); cout << ' ';
  Fraction(1,1).sum({2, 4}).write(); cout << ' ';
  Fraction(2,4).sum({3, 9}).write(); cout << ' ';
  Fraction(-2,4).sum({1, 2}).write(); cout << ' ';
  Fraction(3,27).sum({-27, 81}).write(); cout << '\n'; }
    return 0;
}