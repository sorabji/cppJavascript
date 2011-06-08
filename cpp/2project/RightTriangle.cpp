#include "RightTriangle.h"

RightTriangle::RightTriangle()
{
  height = 0;
  width = 0;
}
RightTriangle::RightTriangle(double width,double height)
{
  this->height = height;
  this->width = width;
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
