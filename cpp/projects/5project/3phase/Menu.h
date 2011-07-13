#ifndef MENU_H
#define MENU_H

#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

#include "Helper.h"

#include "FoodItem.h"
#include "Warehouse.h"

#include "Population.h"
#include "Animal.h"

#include "Zoo.h"

#define EXIT_PHRASE "Thank you for managing your zoo with us!\n"

class Menu{
    private:

        Zoo *z;

        std::string choice;
        int sel;

    public:

        /**
         * menu constructor...requires a pointer to a Warehouse object
         */
        Menu(Zoo *z);

        /**
         * the main menu of the program
         */
        void mainMenu();

        /**
         * specific menu for handling the food items
         */
        void foodInventoryMenu();

        /**
         * specific menu for handling the animals
         */
        void populationMenu();

        /**
         * function to feed an animal
         */
        void feedAnimal();

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
};
#endif
