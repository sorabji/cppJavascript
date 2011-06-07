#include <iostream>

#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "RightTriangle.h"

using namespace std;

int main()
{
  double area = 0;
  int size = 3;
  Shape *shapes[size];
  shapes[0] = new Circle(7);
  shapes[1] = new Rectangle(5,10);
  shapes[2] = new RightTriangle(5,10);

  for (int i=0 ; i < size; i++)
    {
      area = shapes[i]->calcArea();
      cout << "The area of shape #" << i+1 << " is: "
	   << area << endl;

      delete shapes[i];
    }
  
  return 0;
}
