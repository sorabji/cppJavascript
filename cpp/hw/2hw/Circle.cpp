#include "Circle.h"

using namespace std;

Circle::Circle()
{
  radius = 0;
}

Circle::Circle(double r)
{
  radius = r;
}
Circle::~Circle()
{
  radius = 0;
}

/**
 * M_PI is a constant for pi defined in cmath
 */
double Circle::calcArea()
{
  return (M_PI*radius*radius);
  
}









