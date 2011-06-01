#include "Shape.h"

#ifndef RECTANGLE_H
#define RECTANGLE_H
class Rectangle: public Shape
{
 private: 
  double length,width;
 public:
  Rectangle();
  Rectangle(double l,double w);
  virtual ~Rectangle();
  double calcArea();
};
#endif
