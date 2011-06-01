#include "Shape.h"

#ifndef RIGHTTRIANGLE_H
#define RIGHTTRIANGLE_H

class RightTriangle: public Shape
{
 private:
  double width,height;
 public:
  RightTriangle();
  RightTriangle(double w, double h);
  virtual ~RightTriangle();
  double calcArea();
};
#endif
