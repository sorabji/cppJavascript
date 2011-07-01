#include "School.h"
#include <vector>

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


int main(){

    School *school = new School();

    std::cout << std::endl;

    /**
     * to test the overloaded stream operators
     */
    std::string sentinel = "";

    int i = 0;
    std::vector<Student*> sV[3];
    while (sentinel.compare("quit")!=0){
        sV->push_back(new Student());
        std::cin >> (*sV->at(i));
        std::cout << "enter 'quit' to stop entering new students\n" 
                  << "(enter anything else to continue): " << std::flush;
        std::cin >> sentinel;
        if( (*sV->at(i) ).getName().compare("")!=0){
            school->add( (sV->at(i) ) );
        }
        sV->pop_back();
        std::cout << std::endl;
    }
    sV->clear();

    std::cout << std::endl;

    // show that the students were added correctly
    school->printRoster();

    /**
     * to test searching for students from the command line
     */
    std::cout << std::endl;
    std::string name = "";
    while(true){

        std::cout << "enter 'quit' when you're done searching for students" << std::endl;
        std::cout << "enter the name of the student you want to search for: " << std::flush;
        std::cin >> name;

        if(name.compare("quit")==0) break;

        std::vector<Student*> vS2 = school->getStudent(name);
        printResults(vS2,name);
    }

    //delete everything!
    delete school;

    return 0;
}
