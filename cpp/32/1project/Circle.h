#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
 private:
  double radius;
 public:
  Circle();
  virtual ~Circle();
  virtual double calcArea();
}
#endif
