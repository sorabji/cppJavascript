#include <fstream>
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node{
    private:
        T data;
    
    public:
        friend ostream& operator<<(ostream& os, const Node node){
            os << node.data;
            return os;
        }

        void setData(const T data){
            this->data = data;
        }
};

class Command{
    public:
        static string getCommand(){
            string command;
            cout << "Enter command: " << flush;
            cin >> command;
            return command;
        }
};

int main(){
    while (1){
        string command = Command::getCommand()
            //unfinished!!
    }
}

