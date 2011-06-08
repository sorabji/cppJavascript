#include <iostream>
#include "MyClass.h"

using namespace std;
int globalNumber;

void switcher(int &a,int &b){
  int temp = a;
  a = b;
  b = temp;
  
}

int main(int argc, char *argv[]){
  const int MAX_STUDENTS = 30;


  int x = 3,y =4;
  cout << "x: " << x << " y: " << y << endl;
  switcher(x,y);

  cout << "x: " << x << " y: " << y << endl;
  MyClass<int> myClassInt = MyClass<int>();

  int j = 3;

  myClassInt.setAttr(j);

  int i= myClassInt.getAttr();

  MyClass<double> myClassDouble = MyClass<double>();

  double d = myClassDouble.getAttr();
  
  TheOtherClass oc = MyClass<TheOtherClass>().getAttr();

  
}

