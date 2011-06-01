#include "Dog.h"
#include "BigDog.h"

using namespace std;

Dog* makeSpeak()
{
  Dog *dog = new Dog();
  dog->speak();
  return dog;
}

int main()
{
  
  Dog *dog = makeSpeak();

  delete dog;

  BigDog bigDog = BigDog();
  bigDog.speak();
  return 0;
}
