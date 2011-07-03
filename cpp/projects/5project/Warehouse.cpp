#include "Warehouse.h"

bool Warehouse::searchInv(std::string term){
    iter = inv.find(term);
    if ( iter != inv.end() ){
        return true;
    } else {
        return false;
    }
}

void Warehouse::addToInv(std::string type, std::string units, double quantity){
    flag = searchInv(type);
    if (flag){
        inv[type]->setQuantity(quantity);
    } else {
        inv.insert(MapType::value_type(type,new FoodItem(type,units,quantity) ) );
    }
}

void Warehouse::printInv(){
    MapType::const_iterator end = inv.end();

    std::cout << "Current Contents of the Food Inventory\n" << std::endl;
    std::cout << "[Type]\t\t[Units]\t\t[Quantity]\n\n" << std::flush;
    for (iter = inv.begin(); iter != end ; iter++){
        std::cout << iter->second << std::endl;
    }
}
