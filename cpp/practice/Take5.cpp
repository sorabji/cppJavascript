#include <iostream>
#include <stdlib.h>
using namespace std;

int *addOne(int i)
{
  int *j = (int *)malloc(sizeof(int));
  *j = i+1;
  return j;
}

int main()
{
  int i=6;

  int *j = addOne(i);

  cout << "j = " << j << endl << flush;

  return 0;
}



