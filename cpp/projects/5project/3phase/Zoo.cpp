#include "Zoo.h"

void Zoo::searchHerd(std::string term){
    iter = herd.find(term);
    if ( iter == herd.end() ){
        throw false;
    }
}

void Zoo::addToHerd(Animal a){
    try {
        searchHerd(a.getName());
        std::cout << "\nAn Animal by that name already exists!\n\n" << std::flush;
    } catch (...) {
        herd.insert(HerdType::value_type(
            a.getName(),
            new Animal(a.getName(),a.getFood(),a.getType(),a.getIntake(),a.getLastFedTime())));
    }
}

std::vector<std::string> Zoo::getKeys(){
    std::vector<std::string> v;
    HerdType::const_iterator end = herd.end();

    for (iter = herd.begin() ; iter != end ; ++iter){
        v.push_back(iter->first);
    }
    return v;
}

void Zoo::printHerd(){
    HerdType::const_iterator end = herd.end();

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
    for (iter = herd.begin(); iter != end ; iter++){
        std::cout << *(iter->second) << std::endl;
    }
}

Animal* Zoo::getAnimal(std::string name){
    iter = herd.find(name);
    if (iter != herd.end() ){
        return iter->second;
    } else {
        return NULL;
    }
}

void Zoo::printHerdToFile(std::string fileName){

    HerdType::const_iterator end = herd.end();

    std::ofstream outfile;
    outfile.open(fileName.c_str(),std::ios::out);

    if(outfile){

        for (iter = herd.begin(); iter != end ; iter++){
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
