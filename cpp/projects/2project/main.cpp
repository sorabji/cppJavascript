#include "School.h"

/**
 * takes a vector of students and a name, checks if there's anything in the vector
 * ...if so, prints how many students are in the vector; otherwise informs that there
 * were no results found.
 */
void printResults(vector<Student*> v,std::string name){

    std::cout << "searching for students named '" << name << "'..." << std::endl;
    std::cout << "results:" << std::endl;

    if(v.size()!=0){

        std::cout << v.size() << " student(s) named '" << name << "' was(were) found!\n" << std::endl;
    }
    else{
        std::cout << "There were no students named " << name << " found!\n" << std::endl;
    }
}

int main(){

    School *school = new School();

    // the long way to add a student
    Student *student = new Student(1);
    student->setName("Larry");
    school->add(student);

    // faster, more awesome way
    school->add(new Student(3,"Joey"));
    school->add(new Student(2,"Bill"));
    school->add(new Student(4,"Bill"));
    school->add(new Student(5,"Bill"));
    school->add(new Student(6,"Bill"));

    // show that everything worked as expected
    school->printRoster();

    std::cout << std::endl;

    // test our search function w/ multiple, single, and no results
    std::vector<Student*> vS1 = school->getStudent("Bill");
    printResults(vS1,"Bill");

    std::vector<Student*> vS2 = school->getStudent("notFound");
    printResults(vS2,"notFound");

    std::vector<Student*> vS3 = school->getStudent("Larry");
    printResults(vS3,"Larry");

    delete school;

    return 0;
}
