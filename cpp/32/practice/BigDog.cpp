#include "BigDog.h"
#include <iostream>
using namespace std; 
BigDog::BigDog()
{
  cout << "Construct a dog" << endl;
}

BigDog::~BigDog()
{
  cout << "Destructor called" << endl;
}
void BigDog::speak()
{
  cout << "WOOF!" << endl;
}
