#ifndef SCHOOL_H
#define SCHOOL_H

#include <vector>
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
        * searches the roster for a student name, returns a vector of all matches, or an empty vector if not found
        * @param String name: string representation of the name to be searched for
        * @return Vector<Student*>: vector of pointers to all matches...empty vector if name not found
        */
        vector<Student*> getStudent(std::string name);
};
#endif
