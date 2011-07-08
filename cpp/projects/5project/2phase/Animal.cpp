#include "Animal.h"

Animal::Animal(){
    name = "";
    food = "";
    intake = 0;
    lastFedTime = time(NULL);
}

Animal::Animal(std::string name,std::string food,double intake, time_t lastFedTime){
    this->name = name;
    this->food = food;
    this->intake = intake;
    this->lastFedTime = lastFedTime;
}

std::ostream& operator<<(std::ostream &os,const Animal& a){
    std::cout << a.name << "\t\t" << a.food << "\t\t" << a.intake << "\t\t" << a.lastFedTime << std::endl;
    return os;
}

/*
std::istream& operator>>(std::istream &is, Animal &a){
    std::cout << "enter the food item name\n\n" << "$  " << std::flush;
    std::cin >> fi.type;
    std::cout << "\n\nenter the units\n\n" << "$  " << std::flush;
    std::cin >> fi.units;
    while (true){
        std::cout << "\n\nenter the quantity\n\n" << "$  " << std::flush;
        bool flag = validateInput<double>(&fi.quantity);

        if (flag){
            return is;
        } else {
            std::cout << "please enter a valid number for the quantity\n\n" << std::flush;
            continue;
        }
    }
}
*/

std::string Animal::getName(){
    return name;
}

std::string Animal::getFood(){
    return food;
}

double Animal::getIntake(){
    return intake;
}

time_t Animal::getLastFedTime(){
    return lastFedTime;
}

void Animal::setLastFedTime(time_t lastFedTime){
    this->lastFedTime = lastFedTime;
}
