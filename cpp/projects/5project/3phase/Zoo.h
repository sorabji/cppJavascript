#ifndef ZOO_H
#define ZOO_H

#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <fstream>
#include <vector>

#include "Animal.h"

typedef std::map<std::string,Animal*> HerdType;

class Zoo{
    private:
        HerdType herd;
        HerdType::iterator iter;
        bool flag;
        std::string choice;
    public:

        /**
         * search for Animal
         */
        bool searchHerd(std::string term);

        /**
         * add Animal
         */
        void addToHerd(Animal a);

        /**
         * get an animal
         */
        Animal* getAnimal(std::string name);

        /**
         * get all 'keys' in the zoo
         */
        std::vector<std::string> getKeys();

        void printHerd();

        void printHerdToFile(std::string fileName);

};
#endif
