#include "RightTriangle.h"

RightTriangle::RightTriangle()
{
  height = 0;
  width = 0;
}
RightTriangle::RightTriangle(double w,double h)
{
  height = h;
  width = w;
}
RightTriangle::~RightTriangle()
{
  height = 0;
  width = 0;
}
double RightTriangle::calcArea()
{
  return ((height*width)/2);
}
