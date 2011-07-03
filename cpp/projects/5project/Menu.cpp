#include "Menu.h"

using namespace std;

bool Menu::validateInt(int *i){
    if (! (std::cin >> *i) ){
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        return false;
    }
    return true;
}

void Menu::mainMenu(){
    while (true){
        cout 
            << "enter the corresponding number for your selection\n"
            << "\t1: Manage Food Inventory\n"
            << "\t2: Exit\n\n"
            << "$  " << flush;

        flag = validateInt(&sel);

        if (flag){
            switch (sel){
                case 1:
                    foodInventoryMenu();
                    break;
                case 2:
                    cout << "Thank you for managing your zoo with us!\n" << endl;
                    exit(0);
                    break;
                default:
                    cout << "please enter a valid number\n" << endl;
            }
        }else{
            cout <<"please enter the number next to your selection\n" << endl;
            continue;
        }
    }
}

void Menu::foodInventoryMenu(){
    while (true){
        cout
            << "welcome to the food inventory\n"
            << "what would you like to do in the food inventory section?\n"
            << "\t1: View Inventory\n"
            << "\t2: Add to Inventory\n"
            << "\t3: Return to main menu\n"
            << "\t4: Exit\n\n"
            << "$  " << flush;

        flag = validateInt(&sel);

        if (flag){
            switch (sel){
                case 1:
                    // view inventory
                    break;
                case 2:
                    // add to inventory
                    break;
                case 3:
                    return;
                    break;
                case 4:
                    cout << "Thank you for managing your zoo with us!\n" << endl;
                    exit(0);
                    break;
                default:
                    cout << "please enter a valid number\n" << endl;
            }
        }
    }
}
