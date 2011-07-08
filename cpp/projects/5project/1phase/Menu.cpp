#include "Menu.h"


Menu::Menu(Warehouse *wh){
    this->wh = wh;
}

void Menu::mainMenu(){
    while (true){
        std::cout 
            << "enter the corresponding number for your selection\n"
            << "\t1: Manage Food Inventory\n"
            << "\t2: Save Changes and Exit\n"
            << "\t3: Exit (don't save)\n\n"
            << "$  " << std::flush;

        flag = validateInput<int>(&sel);

        if (flag){
            switch (sel){
                case 1:
                    foodInventoryMenu();
                    break;
                case 2:
                    std::cout << EXIT_PHRASE << std::endl;
                    wh->printInvToFile(WAREHOUSE_FILE);
                    exit(0);
                    break;
                case 3:
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
                    exit(0);
                    break;
                case 5:
                    std::cout << EXIT_PHRASE << std::endl;
                    exit(0);
                    break;
                default:
                    std::cout << "please enter a valid number\n" << std::endl;
            }
        }
    }
}
