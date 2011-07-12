#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <fstream>

#include "FoodItem.h"

typedef std::map<std::string,FoodItem*> WarehouseType;

class Warehouse{
    private:
        WarehouseType inv;
        WarehouseType::iterator iter;
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

        /**
         * get food item
         */
        FoodItem* getFoodItem(std::string type);

        void printInv();

        void printInvToFile(std::string fileName);

};
#endif
