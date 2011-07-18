#include "Population.h"

Population::Population(){};

Population::~Population(){
    std::cout << "\tin Populations' destructor" << std::endl;
    iter = population.begin();
    while (iter != population.end()){
        std::cout << "\t\tdeleting " << iter->second->getName() << std::endl;
        population.erase(iter);
        iter = population.begin();
        if (iter == population.end()) break;
    }
}

void Population::addAnimal(Animal *a){
    Animal *ap = getAnimal(a->getName());
    if (NULL == ap){
        population.insert(PopulationType::value_type(a->getName(),a));
    } else {
        std::cout << "\nAn Animal by that name already exists!\n\n" << std::flush;
        delete a;
    }
}

void Population::killAnimal(std::string name){
    iter = population.find(name);
    population.erase(iter);
}

Animal* Population::getAnimal(std::string name){
    iter = population.find(name);
    if ( iter == population.end() ){
        return NULL;
    } else {
        return iter->second;
    }
}

PopulationType* Population::getPopulation(){
    return &population;
}

void Population::printPopulation(){
    std::cout << "Current Contents of the population\n\n" << std::flush;
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
    for (iter = population.begin(); iter != population.end() ; iter++){
        std::cout << *(iter->second) << std::endl;
    }
}

void Population::printPopulationToFile(std::string fileName){


    std::ofstream outfile;
    outfile.open(fileName.c_str(),std::ios::out);

    if(outfile){

        for (iter = population.begin(); iter != population.end() ; iter++){
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

