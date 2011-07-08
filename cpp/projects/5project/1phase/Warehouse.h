#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <iostream>
#include <map>
#include <string>
#include <fstream>

#include "FoodItem.h"

#define WAREHOUSE_FILE "warehouse.data"
#define WAREHOUSE_BAK "warehouse.data.bak"

typedef std::map<std::string,FoodItem*> MapType;

class Warehouse{
    private:
        MapType inv;
        MapType::iterator iter;
        bool flag;
    public:

        /**
         * search for FoodItem
         */
        bool searchInv(std::string term);

        /**
         * add food item
         */
        void addToInv(FoodItem fi);

        void printInv();

        void printInvToFile(std::string fileName);

};
#endif
