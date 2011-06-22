#include <iostream>
using namespace std;
class Pear{
    int val;

    public:
        Pear(int i):val(i){}
        Pear(const Pear &pear){
            val = pear.val;
        }

        virtual ~Pear(){}

        void sevVal(int i){
            val = i;
        }

        bool operator==(const Pear &rhs)const;

        Pear& operator=(const Pear &rhs);
};

bool Pear::operator==(const Pear &rhs) const{
    if (val == rhs.val){
        return true;
    }
    return false;
}

Pear& Pear::operator=(const Pear &rhs){
    val = rhs.val;
    return *this;
}

int main (int argc, char * const argv[]){
    Pear lPear(4), rPear(5); 
    std::cout << "The pears are " << ((lPear == rPear) ? "" : "not ") << "equal.\n";
    lPear = rPear;
    std::cout << "The pears are " << ((lPear == rPear) ? "" : "not ") << "equal.\n";
    return 0;
}
