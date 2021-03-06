#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <fstream>
#include <iostream>
#include <time.h>
#include <iomanip>

#include "Helper.h"

// seconds in a day = 86400
#define CARNIVORE_FEEDING_TIME 30
#define HERBIVORE_FEEDING_TIME 30

class Animal{
    private:

        std::string name;
        std::string food;
        std::string type;
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
        Animal(std::string name,std::string food,std::string type,double intake, time_t lastFedTime);

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
         * get type
         */
        std::string getType();

        /**
         * set lastFedTime
         */
        void updateLastFedTime();

};
#endif
