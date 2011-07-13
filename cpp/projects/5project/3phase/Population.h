#ifndef POPULATION_H
#define POPULATION_H

#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <fstream>
#include <vector>

#include "Animal.h"

typedef std::map<std::string,Animal*> PopulationType;

class Population{
    private:
        PopulationType population;
        PopulationType::iterator iter;
        std::string choice;
    public:

        
        /**
         * add Animal
         */
        void addAnimal(Animal *a);

        /**
         * get population
         */
        PopulationType* getPopulation();

        /**
         * get for Animal
         */
        Animal* getAnimal(std::string name);

        /**
         * kill an Animal
         */
        void killAnimal(std::string name);

        void printPopulation();

        void printPopulationToFile(std::string fileName);

};
#endif
