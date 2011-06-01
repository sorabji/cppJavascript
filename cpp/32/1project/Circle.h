#include "Shape.h"

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle: public Shape
{
 private:
  double radius;
 public:
  Circle();
  Circle(double r);
  virtual ~Circle();
  double calcArea();
};
#endif
