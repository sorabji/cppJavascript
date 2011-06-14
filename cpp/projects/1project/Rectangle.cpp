#include "Rectangle.h"

Rectangle::Rectangle()
{
}
 
Rectangle::Rectangle(double l, double w)
{
  length = l;
  width = w;
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
