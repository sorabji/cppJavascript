#include <iostream>
#include <vector>

#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "RightTriangle.h"

using namespace std;

int main()
{
  double area = 0;
  int size = 3;
  vector<Shape*> shapes;
  shapes.reserve(size);
  shapes.push_back(new Circle(5));
  shapes.push_back(new Rectangle(5,10));
  shapes.push_back(new RightTriangle(5,10));

  vector<Shape*>::iterator it = shapes.begin();
  vector<Shape*>::iterator end = shapes.end();

  int i=0;
  while (it != end) 
    {
      cout << "area of shape #" << i+1 << " is: " << (*it)->calcArea() << endl;
      it++;
      i++;
    }
  return 0;
}
