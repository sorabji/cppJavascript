#ifndef BIGDOG_H
#define BIGDOG_H
#include "Dog.h"

class BigDog : public Dog
{
 public:
  BigDog();
  virtual ~BigDog();
  virtual void speak();
};

#endif
