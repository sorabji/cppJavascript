

#ifndef RIGHTTRIANGLE_H
#define RIGHTTRIANGLE_H
#include "Shape.h"
class RightTriangle: public Shape
{
 private:
  double width,height; // the width and height of the triangle
 public:
  
  /**
   * default constructor
   */
  RightTriangle();

  /**
   * builds a triangle with the specified width and height
   */
  RightTriangle(double width, double height);

  /**
   * destructor; sets values to 0
   */
  virtual ~RightTriangle();

  /**
   * returns the calculated area for the triangle
   */
  double calcArea();
};
#endif
