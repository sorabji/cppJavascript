#include "School.h"

/**
 * default constuctor
 */
School::School(){
    roster = LinkedList<Student*>();
}

/**
 * default destructor
 */
School::~School(){
    //todo cleanup collection
}

/**
 * adds a student
 * @param student is a pointer to a Student
 */
void School::add(Student* student){
    Node<Student*> *node = new Node<Student*>();
    node->data = student;
    roster.addAtEnd(node);
}

/**
 * prints the contents of the roster to stdout in a friendly format
 */
void School::printRoster(){
    Node<Student*> *n = roster.head;
    while(n){
        std::cout << n->data->getName()<< " has an idNumber of: " << n->data->getIdNumber() << std::endl;
        if(!n->next) break;
        n = n->next;
    }
}

/**
 * searches the roster for a student name, returns a pointer to the first match on that name
 * @param String name: string representation of the name to be searched for
 * @return *Student: pointer to the first match...NULL pointer if name not found
 */
Student* School::getStudent(std::string name){
    Node<Student*> *n = roster.head;
    while(n){
        if(n->data->getName().compare(name)==0){
            return n->data;
        }
        if(!n->next){
            Student *notfound = NULL;
            return notfound;
        }
        n = n->next;
    }

}


