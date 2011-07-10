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

        flag = validateInput<int>(&sel);

        if (flag){
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
                    std::cout << "please enter a valid number\n" << std::endl;
            }
        }else{
            std::cout <<"please enter the number next to your selection\n" << std::endl;
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

        flag = validateInput<int>(&sel);

        if (flag){
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
                    std::cout << "please enter a valid number\n" << std::endl;
            }
        }else{
            std::cout <<"please enter the number next to your selection\n" << std::endl;
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
            << "\t3: Feed an animal\n"
            << "\t4: Return to main menu\n"
            << "\t5: Save Changes and Exit\n"
            << "\t6: Exit (don't save changes)\n\n"
            << "$  " << std::flush;

        flag = validateInput<int>(&sel);

        if (flag){
            switch (sel){
                case 1:
                    z->printHerd();
                    break;
                case 2:{
                    Animal a = Animal();
                    std::cout << "fuck:  " << a.getPrettyTime() << "\n";
                    std::cin >> a;
                    std::cout << "fuck:  " << a.getPrettyTime() << "\n";
                    z->addToHerd(a);
                    std::cout << "animal added!\n\n" << std::flush;
                    break;
                       }
                case 3:
                    feedAnimal();
                    break;
                case 4:
                    return;
                    break;
                case 5:
                    std::cout << EXIT_PHRASE << std::endl;
                    wh->printInvToFile(WAREHOUSE_FILE);
                    z->printHerdToFile(ZOO_FILE);
                    exit(0);
                    break;
                case 6:
                    std::cout << EXIT_PHRASE << std::endl;
                    exit(0);
                    break;
                default:
                    std::cout << "please enter a valid number\n" << std::endl;
            }
        }else{
            std::cout <<"please enter the number next to your selection\n" << std::endl;
            continue;
        }
    }
}

void Menu::feedAnimal(){
    std::cout << "enter the name of the animal you wish to feed\n\n" << "$  " << std::flush;
    std::cin >> choice;
    flag = z->searchHerd(choice);
    if(flag){
        Animal* ap = z->getAnimal(choice);
        if (NULL == ap){
            std::cout << "strange error, animal exists but cannot be found...hrm\n\n";
            return;
        }

        flag = wh->searchInv(ap->getFood() );
        if(flag){
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
                    << ap->getName()
                    << " has been fed.\n\n";
                return;
            }
        } else {
            std::cout 
                << "no suitable food exists in the inventory!\n"
                << "perhaps you ought to head on over to the inventory menu and add some '" 
                << ap->getFood() << "'\n\n";
        }
    } else {
        std::cout << "no animal by that name exists...sorry\n\n" << std::flush;
    }
}
