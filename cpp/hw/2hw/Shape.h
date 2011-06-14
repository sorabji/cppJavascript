#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
 public:

  /**
   * default constructor
   */
  Shape();

  /**
   * default destructor
   */
  virtual ~Shape();

  /**
   * returns a the area of the Shape
   */
  virtual double calcArea();
};
#endif
