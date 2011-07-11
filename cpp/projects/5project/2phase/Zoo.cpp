#include "Zoo.h"

bool Zoo::searchHerd(std::string term){
    iter = herd.find(term);
    if ( iter != herd.end() ){
        return true;
    } else {
        return false;
    }
}

void Zoo::addToHerd(Animal a){
    flag = searchHerd(a.getName());
    if (flag){
        std::cout << "\nAn Animal by that name already exists!\n\n" << std::flush;
    } else {
        herd.insert(HerdType::value_type(
                    a.getName(),
                    new Animal(a.getName(),a.getFood(),a.getIntake(),a.getLastFedTime())));
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

    std::cout << "Current Contents of the herd\n" << std::endl;
    std::cout << "[Name]\t\t[Food]\t\t[Intake]\t[Last Fed]\n\n" << std::flush;
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
                << " "
                << (iter->second)->getFood()
                << " "
                << (iter->second)->getIntake() 
                << " " 
                << (iter->second)->getLastFedTime() << std::endl;
        }
    } else{
        std::cout << "'" << fileName << "' cannot be opened for writing" << std::endl;
    }

    outfile.close();
}
