#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#include <time.h>
#include <string.h>

#include "Menu.h"

#include "Warehouse.h"
#include "FoodItem.h"

#include "Population.h"
#include "Animal.h"

void usage(){
    std::cout 
        << "usage:\n"
        << "\t-r to read from the file\n"
        << "\t-c to clear the file and start from scratch\n";

    exit(1);
}


int main(int argc,char **argv){

    Warehouse *wh = new Warehouse();
    Population *p = new Population();
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
        infile.open(WAREHOUSE_FILE,std::ios::in);

        // build up FoodItems from file
        if(infile){
            std::string type;
            std::string units;
            std::string line;
            std::string holder;
            double quantity;

            while(true){
                std::getline(infile,line);
                if( infile.eof() ){ break; }

                outfile << line << "\n";

                std::istringstream iss(line);

                std::getline(iss,type,'|');
                std::getline(iss,units,'|');
                std::getline(iss,holder,'|');

                std::istringstream bleck(holder);
                bleck >> quantity;

                if(iss.bad()){
                    std::cout << "error parsing file." << std::endl;
                    exit(1);
                }

                FoodItem *fi = new FoodItem(type,units,quantity);
                wh->addToInv(fi);

            }
            infile.close();
            outfile.close();
        } else {
            std::cout << WAREHOUSE_FILE << "could not be opened" << std::endl;
        }

        outfile.open(POPULATION_BAK,std::ios::out|std::ios::trunc);
        infile.open(POPULATION_FILE,std::ios::in);

        // build up Animal objects from file
        if(infile){
            std::string line;
            std::string name;
            std::string food;
            std::string type;
            std::string tmp;
            double intake;
            time_t lastFedTime;

            while(true){
                std::getline(infile,line);
                if( infile.eof() ){ break; }

                outfile << line << "\n";

                std::istringstream iss(line);

                std::getline(iss,name,'|');
                std::getline(iss,food,'|');
                std::getline(iss,type,'|');

                std::getline(iss,tmp,'|');
                std::istringstream blah(tmp);
                blah >> intake;

                std::getline(iss,tmp,'|');
                std::istringstream blah2(tmp);
                blah2 >> lastFedTime;

                if(iss.bad()){
                    std::cout << "error parsing file." << std::endl;
                    exit(1);
                }

                Animal *a = new Animal(name,food,type,intake,lastFedTime);
                p->addToHerd(a);

            }
            infile.close();
            outfile.close();
        } else {
            std::cout << POPULATION_FILE << " could not be opened" << std::endl;
        }

    }

    if(createFlag){
        std::ofstream killIt;
        killIt.open(WAREHOUSE_FILE,std::ios::out | std::ios::trunc);
        killIt.close();

        killIt.open(ZOO_FILE,std::ios::out | std::ios::trunc);
        killIt.close();


    }

    std::cout << "Welcome to the Zoo Management Suite\n\n" << std::flush;

    Menu menu = Menu(z);
    menu.mainMenu();

    return 0;
}
