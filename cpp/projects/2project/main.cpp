#include "School.h"

void printVector(vector<Student*> v,std::string name){

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
    Student *student = new Student(1);
    student->setName("Larry");
    school->add(student);
    school->add(new Student(2,"Bill"));
    school->add(new Student(3,"Joey"));
    school->add(new Student(4,"Bill"));
    school->add(new Student(5,"Bill"));
    school->add(new Student(6,"Bill"));
    school->printRoster();

    std::vector<Student*> vS1 = school->getStudent("Bill");
    printVector(vS1,"Bill");

    std::vector<Student*> vS2 = school->getStudent("notFound");
    printVector(vS2,"notFound");

    std::vector<Student*> vS3 = school->getStudent("Larry");
    printVector(vS3,"Larry");

    delete school;

    return 0;
}
