#include <iostream>
#include <vector>

#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "RightTriangle.h"

using namespace std;

int main(){

  int size = 3;
  vector<Shape*> shapes[size];

  shapes->push_back(new Circle(7));
  shapes->push_back(new Rectangle(5,10));
  shapes->push_back(new RightTriangle(5,10));

  vector<Shape*>::iterator it = shapes->begin();
  vector<Shape*>::iterator end = shapes->end();

  size.
  while (it != end){
  
      cout << "The area of the shape is: " << (*it)->calcArea() << endl;

      delete (*it);
      it++;
  }

  shapes->clear();


  return 0;
}
