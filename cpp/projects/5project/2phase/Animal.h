#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <fstream>
#include <iostream>
#include <time.h>
#include <iomanip>

#include "Helper.h"

class Animal{
    private:

        std::string name;
        std::string food;
        std::string prettyTime;
        double intake;
        time_t lastFedTime;

    public:

        /**
         * default constructor
         */
        Animal();

        /**
         * verbose constructor
         */
        Animal(std::string name,std::string food,double intake, time_t lastFedTime);

        /**
         * default destructor
         */
        virtual ~Animal();

        /**
         * overload the ostream operator to provide sane results
         */
        friend std::ostream& operator<<(std::ostream& os,const Animal& fi);

        /**
         * overload the istream operator to provide sane results
         */
        friend std::istream& operator>>(std::istream& is,Animal& fi);

        /**
         * get name
         */
        std::string getName();

        /**
         * get food
         */
        std::string getFood();

        /**
         * get intake
         */
        double getIntake();

        /**
         * get pretty time
         */
        std::string getPrettyTime();

        /**
         * get lastFedTime
         */
        time_t getLastFedTime();

        /**
         * set lastFedTime
         */
        void updateLastFedTime();

};
#endif
