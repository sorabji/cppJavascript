#include "School.h"

void findStudent(School school,std::string name){

    Student *student = school.getStudent(name);
        if (student){
            std::cout << "we searched for a student named " << name << "...and found: " 
                << student->getName() << std::endl;
        }
        else {
            std::cout << "Student not found in the roster!!!11!1one1!" << std::endl;
        }
}

int main(){

    School school = School();
    Student *student = new Student(1);
    student->setName("Larry");
    school.add(student);
    school.add(new Student(2,"Bill"));
    school.add(new Student(3,"Joe"));
    school.printRoster();

    findStudent(school,"Bill");
    findStudent(school,"asdf;lkj");


    

    return 0;
}





//#include <iostream>
//#include "LinkedList.h"

//int main(){
    //LinkedList ll = LinkedList();

    //Node *n;
    //for (int i=0; i<10; i++){
        //n = new Node(i);
        //ll.addAtEnd(n);
    //}

    //ll.print(ll.head);
//}
