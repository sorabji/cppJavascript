#include "Population.h"

Animal* Population::getAnimal(std::string name){
    iter = herd.find(term);
    if ( iter == herd.end() ){
        return NULL;
    } else {
        return iter->second;
    }
}

void Population::addAnimal(Animal *a){
        Animal *ap = getAnimal(a.getName());
        if (NULL == ap){
            herd.insert(PopulationType::value_type(a->getName(),a));
        } else {
            std::cout << "\nAn Animal by that name already exists!\n\n" << std::flush;
        }
    }
}

PopulationType* Population::getPopulation(){
    return &population;
}

void Population::killAnimal(std::string name){
    //figure this one out
    population.erase(name);
}

void Population::printPopulation(){
    std::cout << "Current Contents of the herd\n\n" << std::flush;
    std::cout
        << std::setw(20)
        << std::left
        << "[Name]"
        << std::setw(20)
        << std::left
        << "[Food]"
        << std::setw(20)
        << std::left
        << "[Type]"
        << std::setw(20)
        << std::left
        << "[Intake]"
        << std::setw(40)
        << std::left
        << "[Last Fed]"
        << "\n\n" << std::flush;
    for (iter = herd.begin(); iter != herd.end() ; iter++){
        std::cout << *(iter->second) << std::endl;
    }
}

void Population::printPopulationToFile(std::string fileName){


    std::ofstream outfile;
    outfile.open(fileName.c_str(),std::ios::out);

    if(outfile){

        for (iter = herd.begin(); iter != herd.end() ; iter++){
            outfile 
                << (iter->second)->getName()
                << "|"
                << (iter->second)->getFood()
                << "|"
                << (iter->second)->getType()
                << "|"
                << (iter->second)->getIntake() 
                << "|" 
                << (iter->second)->getLastFedTime() << "\n" << std::flush;

        }
    } else{
        std::cout << "'" << fileName << "' cannot be opened for writing" << std::endl;
    }

    outfile.close();
}

