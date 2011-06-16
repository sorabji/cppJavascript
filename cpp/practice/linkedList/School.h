#ifndef SCHOOL_H
#define SCHOOL_H

#include "Student.h"
#include "LinkedList.h"

class School{
    private:
        /**
         * internal implementation of the roster list
         */
        LinkedList<Student*> roster;
    public:
        
        /**
        * default constuctor
        */
        School();

        /**
        * default destructor
        */
        virtual ~School();
    
        /**
        * adds a student
        * @param student is a pointer to a Student
        */
        void add(Student *student);

        /**
        * prints the contents of the roster to stdout in a friendly format
        */
        void printRoster();

        /**
        * searches the roster for a student name, returns a pointer to the first match on that name
        * @param String name: string representation of the name to be searched for
        * @return *Student: pointer to the first match...NULL pointer if name not found
        */
        Student* getStudent(std::string name);
};
#endif
