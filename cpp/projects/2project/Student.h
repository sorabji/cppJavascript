#ifndef STUDENT_H
#define STUDENT_H
#include <string>

class Student{

    private:

        int idNumber;
        std::string name;

    public:

        /**
         * constructs a student w/ the given idNumber
         */
        Student(int i):idNumber(i){}

        /**
         * constucts a student w/ the given idNumber and name
         */
        Student(int i,std::string s):idNumber(i),name(s){}


        virtual ~Student(){
            idNumber = NULL;
            name.erase(0,name.length());
        }

        int getIdNumber(){
            return idNumber;
        }

        void setIdNumber(int i){
            idNumber = i;
        }

        std::string getName(){
            return name;
        }

        void setName(std::string s){
            name = s;
        }
};
#endif
