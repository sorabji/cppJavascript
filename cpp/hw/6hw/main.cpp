#include "School.h"
#include <stdlib.h>
#include <sstream>

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

int main(int argc, char **argv){

    int readFlag=0;
    int createFlag=0;
    while(argc){
        if(!strcmp("-r",*argv)) readFlag=1;
        if(!strcmp("-c",*argv)) createFlag=1;
        argc--;
        argv++;
    }

    if (readFlag==0 && createFlag ==0){
        std::cout << "usage:\n\t-r to read from the file\n\t-c to create the file" << std::endl;
        exit(0);
    }

    School *school = new School();

    if(createFlag){
        // the long way to add a student
        Student *student = new Student(1);
        student->setName("Larry");
        school->add(student);

        // faster, more awesome way
        school->add(new Student(3,"Joey"));
        school->add(new Student(2,"Bill"));
        school->add(new Student(4,"Bobby"));
        school->add(new Student(5,"Claude"));
        school->add(new Student(6,"Franz"));

        // show that everything worked as expected
        school->printRoster();


        // write to a file
        school->printRosterToFile("student.data");
    }


    if(readFlag){
        std::ifstream infile;
        infile.open("student.data", ios::in);
        int idNum;
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
        school->printRoster();
    }



    /**
     * to test the overloaded stream operators
    std::string name;
    int id;
    while (true){
        std::cout << "enter 'quit' when you're done entering new students" << std::endl;
        std::cout << "enter the new student's first name: " << std::flush;
        std::cin >> name;
        std::cout << "enter the new student's id number: " << std::flush;
        std::cin >> id;
        if (name.compare("quit")==0) break;

        Student *s2 = new Student(id,name);
        std::cout << *s2 << std::endl;
    }
     */

    /**
     * to test overloaded equality and assignment operators
    std::cout << "two new students to test equality and assignment operators\n" << std::endl;
    Student *s3 = new Student(57,"Bobby");
    Student *s4 = new Student(84,"Claude");
    std::cout << *s3 << "\n" << *s4 << std::endl;
    std::cout << "the students are" << ((*(s3)==*(s4))? " " : " not ") << "equal.\n";
    std::cout << "assigning student s4 to s3" << std::endl;
    *s3 = *s4;
    std::cout << "the students are" << ((*(s3)==*(s4))? " " : " not ") << "equal.\n";
    std::cout << std::endl;
     */

    // test our search function w/ multiple, single, and no results
    /*
    std::vector<Student*> vS1 = school->getStudent("Bill");
    printResults(vS1,"Bill");

    std::vector<Student*> vS3 = school->getStudent("Larry");
    printResults(vS3,"Larry");

    std::vector<Student*> vS2 = school->getStudent("notFound");
    printResults(vS2,"notFound");
     */

    //delete everything!
    delete school;

    return 0;
}
