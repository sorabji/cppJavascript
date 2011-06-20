#include "School.h"

/**
 * default constuctor
 */
School::School(){}


/**
 * default destructor
 */
School::~School(){
    std::cout << "in school's destructor" << std::endl;

    std::cout << "deleted school" << std::endl;
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
        std::cout << n->data->getName()<< " has an idNumber of:\t" << n->data->getIdNumber() << std::endl;
        if(!n->next) break;
        n = n->next;
    }
}

/**
 * searches the roster for a student name, returns a vector of all matches, or a NULL vector if not found
 * @param String name: string representation of the name to be searched for
 * @return Vector<Student*>: vector of pointers to all matches...NULL vector if name not found
 */
std::vector<Student*> School::getStudent(std::string name){
    std::vector<Student*> group;
    Node<Student*> *n = roster.head;
    while(n){
        if(n->data->getName().compare(name)==0){
            group.push_back(n->data);
        }
        n = n->next;
    }
    if (group.size()==0){
        group.clear();
    }
    return group;
}


