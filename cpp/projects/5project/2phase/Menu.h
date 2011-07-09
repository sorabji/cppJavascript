#ifndef MENU_H
#define MENU_H

#include <stdlib.h>
#include <iostream>

#include "Helper.h"
#include "FoodItem.h"
#include "Warehouse.h"
#include "Animal.h"
#include "Zoo.h"

#define WAREHOUSE_FILE "warehouse.data"
#define WAREHOUSE_BAK "warehouse.data.bak"

#define ZOO_FILE "zoo.data"
#define ZOO_BAK "zoo.data.bak"

#define EXIT_PHRASE "Thank you for managing your zoo with us!\n"

class Menu{
    private:
        int sel;
        bool flag;
        Warehouse *wh;
        Zoo *z;
    public:

        /**
         * menu constructor...requires a pointer to a Warehouse object
         */
        Menu(Warehouse *wh, Zoo *z);

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
        void herdMenu();
};
#endif
