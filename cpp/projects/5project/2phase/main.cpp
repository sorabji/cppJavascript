#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#include <time.h>
#include <string.h>

#include "Menu.h"
#include "Warehouse.h"
#include "FoodItem.h"
#include "Animal.h"
#include "Zoo.h"

#define WAREHOUSE_FILE "warehouse.data"
#define WAREHOUSE_BAK "warehouse.data.bak"
#define MAX_BUFSIZE 255

void usage(){
    std::cout 
        << "usage:\n"
        << "\t-r to read from the file\n"
        << "\t-c to clear the file and start from scratch\n";

    exit(1);

}


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
        char *buf = new char[MAX_BUFSIZE];
        std::ifstream infile;
        std::ofstream outfile;

        outfile.open(WAREHOUSE_BAK,std::ios::out|std::ios::trunc);
        infile.open(WAREHOUSE_FILE,std::ios::in);

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

        outfile.open(ZOO_BAK,std::ios::out|std::ios::trunc);
        infile.open(ZOO_FILE,std::ios::in);

        if(infile){
            std::string line;
            std::string name;
            std::string food;
            /*std::string tmp;
            std::string tmp1;*/
            double intake;
            time_t lastFedTime;

            while(true){
                std::getline(infile,line);
                if( infile.eof() ){ break; }

                outfile << line << "\n";

                std::istringstream iss(line);

                /*std::getline(iss,name,'|');
                std::getline(iss,food,'|');
                std::getline(iss,tmp,'|');
                std::getline(iss,tmp1,'|');

                std::istringstream blah(tmp);
                blah >> intake;

                std::istringstream blah1(tmp1);
                blah1 >> lastFedTime;*/

                iss >> name;
                iss >> food;
                iss >> intake;
                iss >> lastFedTime;

                if(iss.bad()){
                    std::cout << "error parsing file." << std::endl;
                    exit(1);
                }

                Animal a = Animal(name,food,intake,lastFedTime);
                z->addToHerd(a);

            }
            infile.close();
            outfile.close();
        }

    }

    if(createFlag){
        std::ofstream killIt;
        killIt.open(WAREHOUSE_FILE,std::ios::out | std::ios::trunc);
        killIt.close();

        killIt.open(ZOO_FILE,std::ios::out | std::ios::trunc);
        killIt.close();


    }

    std::cout << "Welcome to the Zoo Management Suite\n" << std::endl;

    Menu menu = Menu(wh,z);
    menu.mainMenu();

    return 0;
}
