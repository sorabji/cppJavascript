#ifndef MENU_H
#define MENU_H

#include <stdlib.h>
#include <iostream>

#include "Warehouse.h"

class Menu{
    private:
        int sel;
        bool flag;
        Warehouse *wh;
    public:

        /**
         * menu constructor...requires a pointer to a Warehouse object
         */
        Menu(Warehouse *wh);

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
