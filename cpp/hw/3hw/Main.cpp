#include <iostream>
using namespace std;

int main(int argc, char **argv){
    int i=0;

    while (argc){
        cout << "arg number " << i+1 << " is: " << *argv << endl;
        argv++;
        argc--;
        i++;
    }

    return 0;
}
