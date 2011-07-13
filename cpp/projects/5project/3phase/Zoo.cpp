#include "Zoo.h"


Zoo::Zoo(Warehouse *wh,Population *population){
    this->wh = wh;
    this->population = population;
}

Zoo::~Zoo(){
    wh->clear();
    population->clear();
}

void Zoo::feedAnimal(std::string animalName){
        population->searchPopulation(animalName);
        Animal* ap = population->getAnimal(animalName);
        if (NULL == ap){
            std::cout << "strange error, animal exists but cannot be found...hrm\n\n";
            return;
        }

        try {
            wh->searchInv(ap->getFood() );
            FoodItem* fip = wh->getFoodItem(ap->getFood() );
            if (NULL == fip){
                std::cout << "strange error, food item exists but resists being located.\n\n";
                return;
            }
            if ( (fip->getQuantity() - ap->getIntake()) < 0 ){
                std::cout 
                    << "not enough food to feed the '"
                    << ap->getName()
                    << "'\ngo to the inventory menu and add more '"
                    << ap->getFood() << "'\n\n";
                return;
            } else {
                fip->setQuantity( (fip->getQuantity() - ap->getIntake() ) );
                ap->updateLastFedTime();
                std::cout
                    << "'"
                    << ap->getName()
                    << "' has been fed.\n\n";
                return;
            }
        } catch (int e){
            std::cout 
                << "no suitable food exists in the inventory for '"
                << ap->getName() << "'\n"
                << "perhaps you ought to head on over to the inventory menu and add some '" 
                << ap->getFood() << "'\n\n";
        }
    } catch (...) {
        std::cout << "no animal named '" << choice << "' exists...weird\n\n" << std::flush;
    }
}

void Zoo::feedAllAnimals(){
    std::vector<std::string> v = population->getKeys();
    for (std::vector<std::string>::iterator it = v.begin() ; it != v.end() ; ++it){
        feedAnimal(*it);
    }
    std::cout << "\n";
}

void Zoo::checkAllAnimalFoodStatus(){
    // seconds in a day = 86400
    time_t curTime;
    Animal *ap;
    double diff;

    std::vector<std::string> v = population->getKeys();
    for (std::vector<std::string>::iterator it = v.begin() ; it != v.end() ; ++it){
        ap = population->getAnimal(*it);
        time(&curTime);
        diff = difftime(curTime,ap->getLastFedTime());
        if (ap->getLastFedTime() == 0){
            std::cout << "'" << ap->getName() << "' has not been fed yet" << std::endl;
	        std::cout << "feeding '" << ap->getName() << "' at " << ctime(&curTime) << std::endl;
            feedAnimal(*it);
        } else if (ap->getType().compare("herbivore") == 0 && diff > HERBIVORE_FEEDING_TIME){
            std::cout << "'" << ap->getName() << "' was last fed on " << ap->getPrettyTime() << std::endl;
	        std::cout << "feeding '" << ap->getName() << "' at " << ctime(&curTime) << std::endl;
            feedAnimal(*it);
        } else if (ap->getType().compare("carnivore") == 0 && diff > CARNIVORE_FEEDING_TIME){
            std::cout << "'" << ap->getName() << "' was last fed on " << ap->getPrettyTime() << std::endl;
	        std::cout << "feeding '" << ap->getName() << "' at " << ctime(&curTime) << std::endl;
            feedAnimal(*it);
        }
    }
}

