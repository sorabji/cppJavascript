#ifndef MENU_H
#define MENU_H

#include <stdlib.h>
#include <iostream>

#include "Helper.h"
#include "FoodItem.h"
#include "Warehouse.h"

#define WAREHOUSE_FILE "warehouse.data"
#define WAREHOUSE_BAK "warehouse.data.bak"
#define EXIT_PHRASE "Thank you for managing your zoo with us!\n"

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
