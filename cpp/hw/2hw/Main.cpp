#include <iostream>
using namespace std;

int main(int argc, char **argv){
    int i=0;

    for(i; i<argc; i++){
        cout << "arg number " << i+1 << " is: " << argv[i] << endl;
    }

    return 0;
}
