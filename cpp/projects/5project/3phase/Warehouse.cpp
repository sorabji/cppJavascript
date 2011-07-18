#include "Warehouse.h"

Warehouse::Warehouse(){}

Warehouse::~Warehouse(){
    std::cout << "\tin Warehouse's destructor" << std::endl;
    iter = warehouse.begin();
    while (iter != warehouse.end()){
        std::cout << "\t\tdeleting " << iter->second->getType() << std::endl;
        warehouse.erase(iter);
        iter = warehouse.begin();
        if(iter == warehouse.end()) break;
    }
    //just to be certain...
    warehouse.clear();
}

FoodItem* Warehouse::getFoodItem(std::string name){
    iter = warehouse.find(name);
    if ( iter == warehouse.end() ){
        return NULL;
    } else {
        return iter->second;
    }
}

void Warehouse::addFoodItem(FoodItem *fi){
    FoodItem *fip = getFoodItem(fi->getType());
    if (NULL == fip){
        warehouse.insert(WarehouseType::value_type(fi->getType(),fi));
    } else {
        warehouse[fi->getType()]->setQuantity( (warehouse[fi->getType()]->getQuantity() ) +fi->getQuantity() );
    }
}

WarehouseType* Warehouse::getWarehouse(){
    return &warehouse;
}

void Warehouse::printWarehouse(){
    WarehouseType::const_iterator end = warehouse.end();

    std::cout << "Current Contents of the Food Warehouse\n" << std::endl;
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
    for (iter = warehouse.begin(); iter != end ; iter++){
        std::cout << *(iter->second) << std::endl;
    }
}

void Warehouse::printWarehouseToFile(std::string fileName){

    WarehouseType::const_iterator end = warehouse.end();

    std::ofstream outfile;
    outfile.open(fileName.c_str(),std::ios::out);

    if(outfile){


        for (iter = warehouse.begin(); iter != end ; iter++){
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
