#include <sstream>
#include <stdlib.h>
#include <vector>
#include <cstring>

#include "School.h"

#define STUDENT_FILE "student.data"

/**
 * takes a vector of students and a name, checks if there's anything in the vector
 * ...if so, prints how many students are in the vector; otherwise informs that there
 * were no results found.
 */
void printResults(vector<Student*> v,std::string name){

    std::cout << "searching for students named '" << name << "'..." << std::endl;
    std::cout << "results:" << std::endl;

    if(v.size()!=0){

        if (v.size()>1){
            std::cout << "\t" << v.size() << " students named '" << name << "' were found!\n" << std::endl;
        }
        else{
            std::cout << "\t" << v.size() << " student named '" << name << "' was found!\n" << std::endl;
        }
    }
    else{
        std::cout << "\tThere were no students named '" << name << "' found!\n" << std::endl;
    }
}

void usage(){
    std::cout << "usage:\n\t-r to read from the file\n\t-c to create the file" << std::endl;
    exit(0);
}

int main(int argc, char **argv){

    int readFlag=0;
    int createFlag=0;

    // get the command line args right!
    if(2 != argc ) { usage(); }

    while(argc){
        if(!strcmp("-r",*argv)) readFlag=1;
        if(!strcmp("-c",*argv)) createFlag=1;
        argc--;
        argv++;
    }

    School *school = new School();

    if(readFlag){
        std::ifstream infile;
        infile.open(STUDENT_FILE, std::ios::in);
        int idNum;
        bool flag;
        std::string name;
        std::string line;

        while(true){
            std::getline(infile,line);
            if( infile.eof() ){ break;}
            std::istringstream iss(line);
            iss >> name;
            iss >> idNum;
            if(iss.bad()){
                std::cout << "error parsing records file." << std::endl;
                exit(1);
            }
            school->add(new Student(idNum,name));
        }

        infile.close();

        std::cout << "after reading the file in, the roster consists of:\n" << std::endl;
        school->printRoster();
    }

    if(createFlag){
        //clear the file
        std::ofstream killIt;
        killIt.open(STUDENT_FILE,std::ios::out | std::ios::trunc);
        killIt.close();
    }

    std::cout << std::endl;

    /**
     * create some students from the cli
     */
    std::string sentinel = "";

    int i = 0;
    std::vector<Student*> sV[3];
    while (sentinel.compare("quit")!=0){
        sV->push_back(new Student());
        std::cin >> (*sV->at(i));

        if( (*sV->at(i) ).getName().compare("")!=0){
            school->add( (sV->at(i) ) );
            std::cout << "student added!\n" << std::endl;
        }

        std::cout << "enter 'quit' to stop entering new students\n" 
                  << "(enter anything else to continue): " << std::flush;
        std::cin >> sentinel;
        sV->pop_back();
        std::cout << std::endl;
    }
    sV->clear();

    std::cout << std::endl;

    // show that the students were added correctly
    school->printRoster();

    // write it out to a file for persistence
    std::cout << "writing to file..." << std::endl;
    school->printRosterToFile(STUDENT_FILE);

    //delete everything!
    std::cout << "releasing memory..." << std::endl;
    delete school;

    std::cout << "exiting..." << std::endl;
    return 0;
}
