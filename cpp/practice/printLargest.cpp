#include <iostream>
using namespace std;

int main()
{
  int i,j,k,tmp(-1);

  cout << "enter three numbers please" << endl << flush;

  cin >> i >> j >> k;

  if (i > j && i > k){
    tmp = i;
  }
  else{
    if (j > i && j > k){
    tmp = j;
    }
    else{
      if (k > i && k > j){
	tmp = k;
      }
    }
  }
  if (tmp != -1){
    cout << "the largest number entered was: " << tmp << endl << flush;
  }
  else{
    cout << "error finding the largest number" << endl << flush;
  }

  return 0;
	
}
