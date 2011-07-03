#include "Menu.h"
#include "Helper.h"

Menu::Menu(Warehouse *wh){
    this->wh = wh;
}

void Menu::mainMenu(){
    while (true){
        std::cout 
            << "enter the corresponding number for your selection\n"
            << "\t1: Manage Food Inventory\n"
            << "\t2: Exit\n\n"
            << "$  " << std::flush;

        flag = validateInput<int>(&sel);

        if (flag){
            switch (sel){
                case 1:
                    foodInventoryMenu();
                    break;
                case 2:
                    std::cout << "Thank you for managing your zoo with us!\n" << std::endl;
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
            << "\t4: Exit\n\n"
            << "$  " << std::flush;

        flag = validateInput<int>(&sel);

        if (flag){
            switch (sel){
                case 1:
                    wh->printInv();
                    break;
                case 2:
                    break;
                case 3:
                    return;
                    break;
                case 4:
                    std::cout << "Thank you for managing your zoo with us!\n" << std::endl;
                    exit(0);
                    break;
                default:
                    std::cout << "please enter a valid number\n" << std::endl;
            }
        }
    }
}
