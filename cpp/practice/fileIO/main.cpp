#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, const char *argv[]){

    ofstream outfile;
    outfile.open("mydata.out");
    outfile << 12 << " " << "this is some data";
    outfile.close();

    ifstream infile;
    infile.open("mydata.out");


    int i;
    infile >> i;
    if (infile.fail()){
        cout << "failed to convert" << endl;
    }else{
        cout << "value of i: " << i << endl;
    }

    string str;
    while(infile.good()){
        infile >> str;
        cout << "string: " << str << endl;
    }
    infile.close();

    return 0;
}
