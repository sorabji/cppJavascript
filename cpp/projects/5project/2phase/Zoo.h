#ifndef ZOO_H
#define ZOO_H

#include <iostream>
#include <map>
#include <string>
#include <fstream>

#include "Animal.h"

typedef std::map<std::string,Animal*> HerdType;

class Zoo{
    private:
        HerdType herd;
        HerdType::iterator iter;
        bool flag;
    public:

        /**
         * search for Animal
         */
        bool searchHerd(std::string term);

        /**
         * add Animal
         */
        void addToHerd(Animal a);

        void printHerd();

        void printHerdToFile(std::string fileName);

};
#endif
