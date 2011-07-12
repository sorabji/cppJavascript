#ifndef FOODITEM_H
#define FOODITEM_H

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

#include "Helper.h"

class FoodItem{
    private:
        std::string type;
        std::string units;
        double quantity;
    public:

        /**
         * default constructor
         */
        FoodItem();

        /**
         * verbose constructor
         */
        FoodItem(std::string type,std::string units,double quantity);

        /**
         * default destructor
         */
        virtual ~FoodItem();

        /**
         * overload the ostream operator to provide sane results
         */
        friend std::ostream& operator<<(std::ostream& os,const FoodItem& fi);

        /**
         * overload the istream operator to provide sane results
         */
        friend std::istream& operator>>(std::istream& is,FoodItem& fi);

        /**
         * get type
         */
        std::string getType();

        /**
         * get units
         */
        std::string getUnits();

        /**
         * get quantity
         */
        double getQuantity();

        /**
         * set quantity
         */
        void setQuantity(double quantity);

};
#endif
