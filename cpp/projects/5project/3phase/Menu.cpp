#include "Menu.h"


Menu::Menu(Warehouse *wh,Zoo *z){
    this->wh = wh;
    this->z = z;
}

void Menu::mainMenu(){
    while (true){
        std::cout 
            << "enter the corresponding number for your selection\n"
            << "\t1: Manage Food Inventory\n"
            << "\t2: Manage Herd\n"
            << "\t3: Save Changes and Exit\n"
            << "\t4: Exit (don't save)\n\n"
            << "$  " << std::flush;

        try {
            validateInput<int>(sel);
            switch (sel){
                case 1:
                    foodInventoryMenu();
                    break;
                case 2:
                    herdMenu();
                    break;
                case 3:
                    std::cout << EXIT_PHRASE << std::endl;
                    wh->printInvToFile(WAREHOUSE_FILE);
                    z->printHerdToFile(ZOO_FILE);
                    exit(0);
                    break;
                case 4:
                    std::cout << EXIT_PHRASE << std::endl;
                    exit(0);
                    break;
                default:
                    std::cout << "please enter a valid number\n\n" << std::flush;
            }
        } catch (...){
            std::cout <<"please enter the number next to your selection\n\n" << std::flush;
            continue;
        }
    }
}

void Menu::foodInventoryMenu(){
    while (true){
        std::cout
            << "welcome to the food inventory\n"
            << "what would you like to do in the food inventory section?\n"
            << "\t1: View Inventory\n"
            << "\t2: Add to Inventory\n"
            << "\t3: Return to main menu\n"
            << "\t4: Save Changes and Exit\n"
            << "\t5: Exit (don't save changes)\n\n"
            << "$  " << std::flush;

        try {
            validateInput<int>(sel);
            switch (sel){
                case 1:
                    wh->printInv();
                    break;
                case 2:{
                    FoodItem fi = FoodItem();
                    std::cin >> fi;
                    std::cout << "food item added!\n\n" << std::flush;
                    wh->addToInv(fi);
                    break;
                       }
                case 3:
                    return;
                    break;
                case 4:
                    std::cout << EXIT_PHRASE << std::endl;
                    wh->printInvToFile(WAREHOUSE_FILE);
                    z->printHerdToFile(ZOO_FILE);
                    exit(0);
                    break;
                case 5:
                    std::cout << EXIT_PHRASE << std::endl;
                    exit(0);
                    break;
                default:
                    std::cout << "please enter a valid number\n\n" << std::flush;
            }
        } catch (...){
            std::cout <<"please enter the number next to your selection\n\n" << std::flush;
            continue;
        }
    }
}

void Menu::herdMenu(){
    while (true){
        std::cout
            << "welcome to the herd\n"
            << "what would you like to do in the herd management section?\n"
            << "\t1: View Herd\n"
            << "\t2: Add an animal to the Herd\n"
            << "\t3: Feed ALL animals\n"
            << "\t4: Feed an animal\n"
            << "\t5: Return to main menu\n"
            << "\t6: Save Changes and Exit\n"
            << "\t7: Exit (don't save changes)\n\n"
            << "$  " << std::flush;

        try {
            validateInput<int>(sel);
            switch (sel){
                case 1:
                    z->printHerd();
                    break;
                case 2:{
                    Animal a = Animal();
                    std::cin >> a;
                    z->addToHerd(a);
                    std::cout << "animal added!\n\n" << std::flush;
                    break;
                       }
                case 3:
                    feedAllAnimals();
                    break;
                case 4:
                    getAnimalNameFromUser();
                    break;
                case 5:
                    return;
                    break;
                case 6:
                    std::cout << EXIT_PHRASE << std::endl;
                    wh->printInvToFile(WAREHOUSE_FILE);
                    z->printHerdToFile(ZOO_FILE);
                    exit(0);
                    break;
                case 7:
                    std::cout << EXIT_PHRASE << std::endl;
                    exit(0);
                    break;
                default:
                    std::cout << "please enter a valid number\n" << std::endl;
            }
        } catch (...){
            std::cout <<"please enter the number next to your selection\n" << std::endl;
            continue;
        }
    }
}

void Menu::getAnimalNameFromUser(){
    std::cout << "enter the name of the animal you wish to feed\n\n" << "$  " << std::flush;
    std::getline(std::cin,choice);
    feedAnimal(choice);
}

void Menu::feedAnimal(std::string animalName){
    try {
        z->searchHerd(animalName);
        Animal* ap = z->getAnimal(animalName);
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

void Menu::feedAllAnimals(){
    std::vector<std::string> v = z->getKeys();
    for (std::vector<std::string>::iterator it = v.begin() ; it != v.end() ; ++it){
        feedAnimal(*it);
    }
    std::cout << "\n";
}

void Menu::checkAllAnimalFoodStatus(){
    // seconds in a day = 86400
    time_t curTime;
    Animal *ap;

    std::vector<std::string> v = z->getKeys();
    for (std::vector<std::string>::iterator it = v.begin() ; it != v.end() ; ++it){
        ap = z->getAnimal(*it);
        time(&curTime);
        if ( (curTime - ap->getLastFedTime()) > 86400 ){
            feedAnimal(*it);
        }
    }
}

