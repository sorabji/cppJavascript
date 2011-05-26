#include <iostream>

using namespace std;
int main()
{
  int largest,tmp;

  cout << "enter as many integers (within reasonable bounds) " << endl
       << "as you please...this amazing program will figure out " << endl
       << "(and print) which is the largest!" << endl 
       << "when you're done just enter something other than an integer " << endl
       << "(or a number too large or too small to fit within an integer " << endl
       << "as defined by 'limits.h' in the standard library for c++)\n"
       << endl << "$  " << flush;
  cin >> largest;
  while (cin >> tmp){
    if (tmp > largest) largest = tmp;
  }

  cout << "the largest entered was: "
       << largest << endl << "yay applause wonderment." << endl << flush;
}
