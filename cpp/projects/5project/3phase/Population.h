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

        Population();

        ~Population();

        /**
         * add Animal
         */
        void addAnimal(Animal *a);

        /**
         * kill an animal
         */
        void killAnimal(std::string name);

        /**
         * get population
         */
        PopulationType* getPopulation();

        /**
         * get for Animal
         */
        Animal* getAnimal(std::string name);

        void printPopulation();

        void printPopulationToFile(std::string fileName);

};
#endif
