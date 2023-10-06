#include "Color.hpp"

namespace prog {
    Color::Color() {
      m_red = 0;
      m_green = 0;
      m_blue = 0;
    }

    Color::Color(const Color& other) {
      m_red = other.m_red;
      m_green = other.m_green;
      m_blue = other.m_blue;
    }

    Color::Color(rgb_value red, rgb_value green, rgb_value blue) {
      m_red = red;
      m_green = green;
      m_blue = blue;
    }

    rgb_value Color::red() const {
        return m_red;
    }

    rgb_value Color::green() const {
        return m_green;
    }

    rgb_value Color::blue() const {
        return m_blue;
    }

    rgb_value& Color::red()  {
        return m_red;
    }

    rgb_value& Color::green()  {
        return m_green;
    }

    rgb_value& Color::blue()  {
        return m_blue;
    }

    bool Color::operator==(const Color& c) {
        return m_red == c.red() && m_green == c.green() && m_blue == c.blue();
    }   
}