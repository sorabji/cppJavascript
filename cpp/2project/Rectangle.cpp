#include "Rectangle.h"

Rectangle::Rectangle()
{
}
 
Rectangle::Rectangle(double length, double width)
{
  this->length = length;
  this->width = width;
}
Rectangle::~Rectangle()
{
  length = 0;
  width = 0;
}
double Rectangle::calcArea()
{
  return length*width;
}
