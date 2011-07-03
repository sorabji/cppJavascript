#include "Menu.h"
#include "Warehouse.h"
#include "FoodItem.h"
#include <iostream>
using namespace std;

int main(int argc,char **argv){
    Menu menu = Menu();
    cout << "Welcome to the Zoo Management Suite\n" << endl;
    menu.mainMenu();
    return 0;
}
