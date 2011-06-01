#include "Calling.h"
#include <iostream>
#include <stdlib.h>

int something()
{
  int *c, d=5;

  c = &d;
  addOne(d);

  std::cout << "d = " << d << std::endl;

  return 0;
}

