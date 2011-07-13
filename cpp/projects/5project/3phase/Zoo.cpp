#include "Zoo.h"

Zoo::Zoo(){};

Zoo::Zoo(Warehouse *warehouse,Population *population){
    this->warehouse = warehouse;
    this->population = population;
}

Zoo::~Zoo(){
    std::cout << "in Zoo's destructor" << std::endl;
    delete warehouse;
    delete population;
}

void Zoo::addFoodItem(FoodItem *fi){
    warehouse->addFoodItem(fi);
}

void Zoo::addAnimal(Animal *a){
    population->addAnimal(a);
}

void Zoo::feedAnimal(std::string animalName){
    ap = population->getAnimal(animalName);
    if (NULL == ap){
        std::cout << "animal does not exist!\n" << std::endl;
        return;
    } else {
        fip = warehouse->getFoodItem(ap->getFood() );
        if (NULL == fip){
            std::cout 
                << "no suitable food exists in the inventory for '"
                << ap->getName() << "'\n"
                << "perhaps you ought to head on over to the inventory menu and add some '" 
                << ap->getFood() << "'\n\n";
            ap = NULL;
                return;
        } else {
            if ( (fip->getQuantity() - ap->getIntake()) < 0 ){
                std::cout 
                    << "not enough food to feed '"
                    << ap->getName()
                    << "'\ngo to the inventory menu and add more '"
                    << ap->getFood() 
                    << "'\n" << std::endl;
                ap = NULL;
                fip = NULL;
                return;
            } else {
                fip->setQuantity( (fip->getQuantity() - ap->getIntake() ) );
                ap->updateLastFedTime();
                std::cout
                    << "'"
                    << ap->getName()
                    << "' has been fed.\n\n";
                ap = NULL;
                fip = NULL;
                return;
            }
        }
    }
}

void Zoo::feedAllAnimals(){
    PopulationType *pop = population->getPopulation();
    for (PopulationType::iterator iter = pop->begin(); iter != pop->end() ; pop++){
        feedAnimal(iter->second->getName());
    }
    std::cout << "\n";
}

void Zoo::checkAllAnimalFoodStatus(){
    // seconds in a day = 86400
    time_t curTime;
    double diff;

    PopulationType * pop = population->getPopulation();
    for (PopulationType::iterator iter = pop->begin(); iter != pop->end() ; pop++){
        ap = iter->second;
        time(&curTime);
        diff = difftime(curTime,ap->getLastFedTime());
        if (ap->getLastFedTime() == 0){
            std::cout << "'" << ap->getName() << "' has not been fed yet" << std::endl;
	        std::cout << "feeding '" << ap->getName() << "' at " << ctime(&curTime) << std::endl;
            feedAnimal(ap->getName());
        } else if (ap->getType().compare("herbivore") == 0 && diff > HERBIVORE_FEEDING_TIME){
            std::cout << "'" << ap->getName() << "' was last fed on " << ap->getPrettyTime() << std::endl;
	        std::cout << "feeding '" << ap->getName() << "' at " << ctime(&curTime) << std::endl;
            feedAnimal(ap->getName());
        } else if (ap->getType().compare("carnivore") == 0 && diff > CARNIVORE_FEEDING_TIME){
            std::cout << "'" << ap->getName() << "' was last fed on " << ap->getPrettyTime() << std::endl;
	        std::cout << "feeding '" << ap->getName() << "' at " << ctime(&curTime) << std::endl;
            feedAnimal(ap->getName());
        }
    }
    ap = NULL;
}

void Zoo::printWarehouse(){
    warehouse->printWarehouse();
}

void Zoo::printPopulation(){
    population->printPopulation();
}

void Zoo::printPopulationToFile(){
    population->printPopulationToFile(POPULATION_FILE);
}
void Zoo::printWarehouseToFile(){
    warehouse->printWarehouseToFile(WAREHOUSE_FILE);
}
void Zoo::printZooToFile(){
    warehouse->printWarehouseToFile(WAREHOUSE_FILE);
    population->printPopulationToFile(POPULATION_FILE);
}
