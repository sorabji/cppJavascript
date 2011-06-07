#include "Shape.h"

#ifndef CIRCLE_H
#define CIRCLE_H
#define _USE_MATH_DEFINES
#include <cmath>

class Circle: public Shape
{
 private:
  double radius; // the radius of the Circle

 public:
  /**
   * default constructor
   */
  Circle();

  /**
   * builds a Circle with the specified radius
   */
  Circle(double r);

  /**
   * destructor; sets values to 0
   */
  virtual ~Circle();

  /**
   * returns the calculated area for the Circle
   */
  double calcArea();
};
#endif
