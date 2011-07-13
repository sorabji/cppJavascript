#ifndef ZOO_H
#define ZOO_H

#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

#include "Helper.h"

#include "FoodItem.h"
#include "Warehouse.h"

#include "Animal.h"
#include "Population.h"

#define WAREHOUSE_FILE "warehouse.data"
#define WAREHOUSE_BAK "warehouse.data.bak"

#define POPULATION_FILE "population.data"
#define POPULATION_BAK "population.data.bak"


class Zoo{
    private:

        Warehouse *warehouse;
        Population *population;

        Animal *ap;
        FoodItem *fip;

        std::string choice;
        int sel;

    public:

        /**
         * default Zoo constructor
         */
        Zoo();

        /**
         * Zoo constructor, pointer to warehouse and population
         */
        Zoo(Warehouse *warehouse, Population *population);

        /**
         * Zoo destructor
         */
        ~Zoo();

        /**
         * adds food item to the warehouse
         */
        void addFoodItem(FoodItem *fi);

        /**
         * adds an animal to the population
         */
        void addAnimal(Animal *a);

        /**
         * function to feed an animal
         */
        void feedAnimal(std::string animalName);

        /**
         * feed all animals in the zoo
         */
        void feedAllAnimals();

        /**
         * get animal name from user
         */
        void getAnimalNameFromUser();

        /**
         * checks status of all animals feeding...if an animal needs feeding, it tries to feed it
         */
        void checkAllAnimalFoodStatus();

        /**
         * prints Warehouse to stdout
         */
        void printWarehouse();

        /**
         * prints population to stdout
         */
        void printPopulation();

        /**
         * print population to file
         */
        void printPopulationToFile();

        /**
         * print warehouse to file
         */
        void printWarehouseToFile();

        /**
         * print population and warehouse to file
         */
        void printZooToFile();
};
#endif
