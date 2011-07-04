#include "FoodItem.h"
#include "Helper.h"

FoodItem::FoodItem(){
    type = "";
    units = "";
    quantity = 0;
}

FoodItem::FoodItem(std::string type,std::string units,double quantity){
    this->type = type;
    this->units = units;
    this->quantity = quantity;
}

FoodItem::~FoodItem(){
    type = "";
    units = "";
    quantity = 0;
}

std::ostream& operator<<(std::ostream &os,const FoodItem& fi){
    std::cout << fi.type << "\t\t" << fi.units << "\t\t" << fi.quantity << std::endl;
    return os;
}

std::istream& operator>>(std::istream &is, FoodItem &fi){
    std::cout << "enter the food item name\n\n" << "$  " << std::flush;
    std::cin >> fi.type;
    std::cout << "\n\nenter the units\n\n" << "$  " << std::flush;
    std::cin >> fi.units;
    while (true){
        std::cout << "\n\nenter the quantity\n\n" << "$  " << std::flush;
        bool flag = validateInput<double>(&fi.quantity);

        if (flag){
            return is;
        } else {
            std::cout << "please enter a valid number for the quantity\n\n" << std::flush;
            continue;
        }
    }
}

std::string FoodItem::getType(){
    return type;
}

std::string FoodItem::getUnits(){
    return units;
}

double FoodItem::getQuantity(){
    return quantity;
}

void FoodItem::setQuantity(double quantity){
    this->quantity = quantity;
}
