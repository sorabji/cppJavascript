#include <iostream>
#include <vector>

using namespace std;

int main()
{
  vector<int> vInt;
  vInt.reserve(80);
  cout << "Max size: " << vInt.capacity() << endl;
  for (unsigned int i=0; i < vInt.capacity(); i++)
    {
      // vInt[i] = i;
      vInt.push_back(i);
    }

  cout << "The front is: " << vInt.front() << endl;
  vInt.erase(vInt.begin());
  vector<int>::reverse_iterator it = vInt.rbegin();
  vector<int>::reverse_iterator end = vInt.rend();

  while (it != end) 
    {
      cout << *it << endl;
      it++;
    }
}
