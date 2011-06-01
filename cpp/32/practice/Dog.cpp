#include "Dog.h"
#include <iostream>
using namespace std;


Dog::Dog()
{
  cout << "Construct a dog" << endl;
}

Dog::~Dog()
{
  cout << "Destructor called" << endl;
}
void Dog::speak()
{
  cout << "Woof!" << endl;
}


