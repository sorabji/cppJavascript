#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <iostream>
#include <map>
#include <string>
#include <utility>

#include "FoodItem.h"

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
        void addToInv(std::string type, std::string units, double quantity);

        void printInv();

};
#endif
