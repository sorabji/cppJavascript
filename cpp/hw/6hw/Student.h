#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>
#include <ostream>
#include <limits>
using namespace std;

class Student{

    private:

        int idNumber;
        std::string name;

    public:

        /**
         * constructs a blank student;
         */
        Student():idNumber(0),name(""){}
        /**
         * constructs a student w/ the given idNumber
         */
        Student(int i):idNumber(i){}

        /**
         * constucts a student w/ the given idNumber and name
         */
        Student(int i,std::string s):idNumber(i),name(s){}


        /**
         * destructor
         */
        virtual ~Student(){
            //std::cout << "\t\t\tdeleted Student: " << name << std::endl;
        }

        /**
         * overloads the == operator to provide sane results when used on Student objects
         */
        bool operator==(const Student &rhs)const{
            if (idNumber==rhs.idNumber && name.compare(rhs.name)==0){
               return true; 
            }
            return false;
        }

        /**
         * overloads the = operator to provide sane results when used on Student objects
         */
        Student& operator=(const Student &rhs){
            idNumber = rhs.idNumber;
            name = rhs.name;
            return *this;
        }

        /**
         * overloads the << operator to provide sane results when used on Student objects
         */
        friend ostream& operator<<(ostream& os, const Student &student){
            os << "student's name: " << student.name << std::endl;
            os << "student's id number: " << student.idNumber << std::endl;
            return os;
        }

        /**
         * overloads the >> operator to provide sane results when used on Student objects
         */
        friend istream& operator>>(istream& is, Student& student){
            std::cout << "enter the new student's id number: " << std::flush;
            if (! (std::cin >> student.idNumber) ){
                //wow, screw everything about cin
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout << "invalid input! aborting...\n" << std::endl;
                return is;
            }
            std::cout << "enter the new student's first name: " << std::flush;
            std::cin >> student.name;
            //std::cout << "successfully added a new student!\n" << std::endl;

            return is;
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
