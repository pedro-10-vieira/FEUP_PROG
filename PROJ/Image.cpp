#include "Image.hpp"

namespace prog
{
  Image::Image(int w, int h, const Color &fill)
  {
    m_width = w;
    m_height = h;
    m_pixels = new Color[w * h]; //allocate memory for the dynamic array of pixels

    //fill the array with the specified color
    for (int i = 0; i < w * h; i++) {
      m_pixels[i] = fill;
    }
  }

  Image::~Image()
  {
    delete[] m_pixels; //free the memory allocated for the dynamic array
  }

  int Image::width() const
  {
    return m_width;
  }

  int Image::height() const
  {
    return m_height;
  }

  Color& Image::at(int x, int y)
  {
    return m_pixels[y * m_width + x];
  }

  const Color& Image::at(int x, int y) const
  {
    return m_pixels[y * m_width + x];
  } 
}