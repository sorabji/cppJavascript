#include "Menu.h"
#include "Warehouse.h"
#include "FoodItem.h"
#include <iostream>
using namespace std;

int main(int argc,char **argv){
    Warehouse *wh = new Warehouse();
    Menu menu = Menu(wh);
    cout << "Welcome to the Zoo Management Suite\n" << endl;
    menu.mainMenu();
    return 0;
}
