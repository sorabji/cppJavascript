#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <sstream>

#include "Menu.h"
#include "Warehouse.h"
#include "FoodItem.h"
#include "Animal.h"
#include "Zoo.h"

#define WAREHOUSE_FILE "warehouse.data"
#define WAREHOUSE_BAK "warehouse.data.bak"

void usage(){
    std::cout 
        << "usage:\n"
        << "\t-r to read from the file\n"
        << "\t-c to clear the file and start from scratch\n";

    exit(1);

}

using namespace std;

int main(int argc,char **argv){

    Warehouse *wh = new Warehouse();
    Zoo *z = new Zoo();

    int readFlag=0;
    int createFlag=0;

    if(2!=argc){
        usage();
    }

    while(argc){
        if(!std::strcmp("-r",*argv)) readFlag=1;
        if(!std::strcmp("-c",*argv)) createFlag=1;
        argc--;
        argv++;
    }

    if(readFlag){
        std::ifstream infile;
        std::ofstream outfile;

        outfile.open(WAREHOUSE_BAK,std::ios::out|std::ios::trunc);
        infile.open(WAREHOUSE_FILE,ios::in);

        if(infile){
            std::string type;
            std::string units;
            std::string line;
            double quantity;

            while(true){
                std::getline(infile,line);
                if( infile.eof() ){ break; }

                outfile << line << "\n";

                std::istringstream iss(line);
                iss >> type;
                iss >> units;
                iss >> quantity;

                if(iss.bad()){
                    std::cout << "error parsing file." << std::endl;
                    exit(1);
                }

                FoodItem fi = FoodItem(type,units,quantity);
                wh->addToInv(fi);

            }
            infile.close();
            outfile.close();
        }
    }

    if(createFlag){
        std::ofstream killIt;
        killIt.open(WAREHOUSE_FILE,std::ios::out | std::ios::trunc);
        killIt.close();

    }

    cout << "Welcome to the Zoo Management Suite\n" << endl;

    Menu menu = Menu(wh,z);
    menu.mainMenu();

    return 0;
}
