#include "Warehouse.h"

bool Warehouse::searchInv(std::string term){
    iter = inv.find(term);
    if ( iter != inv.end() ){
        return true;
    } else {
        return false;
    }
}

void Warehouse::addToInv(FoodItem fi){
    flag = searchInv(fi.getType());
    if (flag){
        inv[fi.getType()]->setQuantity( (inv[fi.getType()]->getQuantity() ) +fi.getQuantity() );
    } else {
        inv.insert(MapType::value_type(fi.getType(),new FoodItem(fi.getType(),fi.getUnits(),fi.getQuantity()) ) );
    }
}

void Warehouse::printInv(){
    MapType::const_iterator end = inv.end();

    std::cout << "Current Contents of the Food Inventory\n" << std::endl;
    std::cout << "[Type]\t\t[Units]\t\t[Quantity]\n\n" << std::flush;
    for (iter = inv.begin(); iter != end ; iter++){
        std::cout << *(iter->second) << std::endl;
    }
}

void Warehouse::printInvToFile(std::string fileName){

    MapType::const_iterator end = inv.end();

    std::ofstream outfile;
    outfile.open(fileName.c_str(),std::ios::app);

    if(outfile){


        for (iter = inv.begin(); iter != end ; iter++){
            outfile 
                << (iter->second)->getType()
                << " "
                << (iter->second)->getUnits()
                << " "
                << (iter->second)->getQuantity() << std::endl;
        }
    }

    outfile.close();
}
