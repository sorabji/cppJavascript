#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>
#include <ostream>
using namespace std;

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
            std::cout << "\t\tdeleted Student: " << name << std::endl;
        }

        bool operator==(const Student &rhs)const{
            if (idNumber==rhs.idNumber && name.compare(rhs.name)==0){
               return true; 
            }
            return false;
        }

        Student& operator=(const Student &rhs){
            idNumber = rhs.idNumber;
            name = rhs.name;
            return *this;
        }

        friend ostream& operator<<(ostream& os, const Student &student){
            os << "student's name: " << student.name << std::endl;
            os << "student's id number: " << student.idNumber << std::endl;
            return os;
        }

        friend istream& operator>>(istream& is, Student& student){
            is >> student.idNumber >> student.name;
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
