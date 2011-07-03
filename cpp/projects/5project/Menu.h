#ifndef MENU_H
#define MENU_H

#include <stdlib.h>
#include <iostream>
#include <limits>

class Menu{
    private:
        int sel;
        bool flag;
    public:

        /**
         * reads a value from cin into an integer, returns a boolean based on success/failure
         */
        bool validateInt(int *i);

        /**
         * the main menu of the program
         */
        void mainMenu();

        /**
         * specific menu for handling the food items
         */
        void foodInventoryMenu();
};
#endif
