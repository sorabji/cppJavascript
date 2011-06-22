#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Anything{
    friend ostream& operator<<(ostream& os, const Anything any);
    friend istream& operator>>(istream& is, Anything& any);

    private:
        int id;

    public:
};

ostream& operator<<(ostream& os, const Anything any){
    os << "Id: " << any.id << endl;
    return os;
}

istream& operator>>(istream& is, Anything& any){
    cout << "Enter ID: " << flush;
    is >> any.id;
    cout << endl;
    return is;
}

int main(){
    Anything any = Anything();
    cin >> any;
    cout << any;
}

