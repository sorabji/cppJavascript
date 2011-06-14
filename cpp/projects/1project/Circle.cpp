#include "Circle.h"

#include <cmath>
using namespace std;

const double PI = 4.0*atan(1.0);

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
double Circle::calcArea()
{
  return (PI*radius*radius);
}
