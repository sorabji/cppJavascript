#include "Menu.h"


Menu::Menu(Zoo* z){
    this->z = z;
}

void Menu::mainMenu(){
    while (true){
        checkAllAnimalFoodStatus();
        std::cout 
            << "enter the corresponding number for your selection\n"
            << "\t1: Manage Food Inventory\n"
            << "\t2: Manage Population\n"
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
                    populationMenu();
                    break;
                case 3:
                    std::cout << EXIT_PHRASE << std::endl;
                    wh->printInvToFile(WAREHOUSE_FILE);
                    z->printPopulationToFile(ZOO_FILE);
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
        checkAllAnimalFoodStatus();
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
                    z->printPopulationToFile(ZOO_FILE);
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

void Menu::populationMenu(){
    while (true){
        checkAllAnimalFoodStatus();
        std::cout
            << "welcome to the Population\n"
            << "what would you like to do in the Population management section?\n"
            << "\t1: View population\n"
            << "\t2: Add an animal to the Population\n"
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
                    z->printPopulation();
                    break;
                case 2:{
                    Animal a = Animal();
                    std::cin >> a;
                    z->addToPopulation(a);
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
                    z->printPopulationToFile(ZOO_FILE);
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
    feedAnimal();
}

void Menu::feedAnimal(){
}

void Menu::feedAllAnimals(){
}

void Menu::checkAllAnimalFoodStatus(){
}

