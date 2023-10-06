#ifndef __prog_Image_hpp__
#define __prog_Image_hpp__
#include "Color.hpp"

namespace prog
{
  class Image
  {
  private:
    int m_width;
    int m_height;
    Color* m_pixels;

  public:
    // Constructors
    Image(int w, int h, const Color &fill = {255, 255, 255});
    // Destructor
    ~Image();
    // Accessors
    int width() const;
    int height() const;
    // Member Functions
    Color &at(int x, int y);
    const Color &at(int x, int y) const;
  };
}
#endif