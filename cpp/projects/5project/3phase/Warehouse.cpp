#include "Warehouse.h"

FoodItem* Warehouse::getFoodItem(std::string name){
    iter = inv.find(name);
    if ( iter == inv.end() ){
        return NULL;
    } else {
        return iter->second;
    }
}

void Warehouse::addToInv(FoodItem *fi){
    FoodItem *fip = getFoodItem(fi.getType());
    if (NULL == fip){
        inv.insert(WarehouseType::value_type(fi->getType(),fi));
    } else {
        inv[fi->getType()]->setQuantity( (inv[fi->getType()]->getQuantity() ) +fi->getQuantity() );
    }
}

FoodItem* Warehouse::getFoodItem(std::string type){
    iter = inv.find(type);
    if ( iter != inv.end() ){
        return iter->second;
    } else {
        return NULL;
    }
}

WarehouseType* getInventory(){
    return &inv;
}

void Warehouse::printInv(){
    WarehouseType::const_iterator end = inv.end();

    std::cout << "Current Contents of the Food Inventory\n" << std::endl;
    std::cout 
        << std::setw(20)
        << std::left
        << "[Type]"
        << std::setw(20)
        << std::left
        << "[Units]"
        << std::setw(20)
        << std::left
        << "[Quantity]"
        << "\n"
        << std::endl;
    for (iter = inv.begin(); iter != end ; iter++){
        std::cout << *(iter->second) << std::endl;
    }
}

void Warehouse::printInvToFile(std::string fileName){

    WarehouseType::const_iterator end = inv.end();

    std::ofstream outfile;
    outfile.open(fileName.c_str(),std::ios::out);

    if(outfile){


        for (iter = inv.begin(); iter != end ; iter++){
            outfile 
                << (iter->second)->getType()
                << "|"
                << (iter->second)->getUnits()
                << "|"
                << (iter->second)->getQuantity() << "\n" << std::flush;
        }
    }

    outfile.close();
}
