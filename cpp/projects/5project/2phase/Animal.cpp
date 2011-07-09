#include "Animal.h"

Animal::Animal(){
    name = "";
    food = "";
    intake = 0;
    lastFedTime = 0;
}

Animal::Animal(std::string name,std::string food,double intake, time_t lastFedTime){
    this->name = name;
    this->food = food;
    this->intake = intake;
    this->lastFedTime = lastFedTime;
}

Animal::~Animal(){
    name = "";
    food = "";
    intake = 0;
    lastFedTime = 0;
}

std::ostream& operator<<(std::ostream &os,const Animal& a){
    std::cout << a.name << "\t\t" << a.food << "\t\t" << a.intake << "\t\t" << a.lastFedTime << std::endl;
    return os;
}

std::istream& operator>>(std::istream &is, Animal &a){
    std::cout << "enter the name of the animal\n\n" << "$  " << std::flush;
    std::cin >> a.name;
    std::cout << "\n\nenter the type of food it eats\n\n" << "$  " << std::flush;
    std::cin >> a.food;
    while (true){
        std::cout << "\n\nenter the quantity of food it eats\n(number of 'units' it's food is measured in)\n\n" << "$  " << std::flush;
        bool flag = validateInput<double>(&a.intake);

        if (flag){
            return is;
        } else {
            std::cout << "please enter a valid number for the intake quantity\n\n" << std::flush;
            continue;
        }
    }
}

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

void Animal::updateLastFedTime(){
    time(&(this->lastFedTime));
}
