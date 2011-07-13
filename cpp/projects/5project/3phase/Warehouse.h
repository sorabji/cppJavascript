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
        WarehouseType warehouse;
        WarehouseType::iterator iter;
    public:

        Warehouse();

        ~Warehouse();

        /**
         * add food item
         */
        void addFoodItem(FoodItem *fi);

        /**
         * get food item
         */
        FoodItem* getFoodItem(std::string name);

        /**
         * get warehouse
         */
        WarehouseType* getWarehouse();

        void printWarehouse();

        void printWarehouseToFile(std::string fileName);

};
#endif
