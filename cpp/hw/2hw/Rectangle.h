

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"
class Rectangle: public Shape
{
 private: 
  double length,width; // length and width, respectively, of the Rectangle
 public:

  /**
   * default constructor
   */
  Rectangle();

  /**
   * builds a Rectangle with the specified length and width
   */
  Rectangle(double length,double width);

  /**
   * destructor; sets values to 0
   */
  virtual ~Rectangle();

  /**
   * returns the calculated area for the Rectangle
   */
  double calcArea();
};
#endif
