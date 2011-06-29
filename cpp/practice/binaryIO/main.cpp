#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

#define STORED_DATA_FILENAME "myData.dat"
#define MAX_BUFSIZE 255

using namespace std;

struct Person{
    string firstName;
    string lastName;
}person;

int main(){

    char *buf = new char[MAX_BUFSIZE];
    time_t currentTime,returnedTime;

    person.firstName = string("Robert Paul");
    person.lastName = string("Rapant");

    time(&currentTime);

    ofstream outfile;
    outfile.open(STORED_DATA_FILENAME,ios::binary | ios::trunc); 
    outfile.write((char *)&currentTime, sizeof(time_t));

    outfile.write(person.firstName.c_str(), person.firstName.size()+1);
    outfile.write(person.lastName.c_str(), person.lastName.size()+1);

    outfile.close();

    ifstream infile(STORED_DATA_FILENAME,ios::binary);
    infile.read((char *)&returnedTime, sizeof(time_t));
    cout << "Returned time: " << returnedTime << endl;

    // getline(buffer stream, max length to read, char to stop reading at)
    while(infile.getline(buf,MAX_BUFSIZE,'\0') && !infile.fail()){
        cout << "string is: " << buf << " ";
    }
    cout << endl;

    return 0;
}
