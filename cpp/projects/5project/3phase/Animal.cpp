#include "Animal.h"

Animal::Animal(){
    name = "";
    food = "";
    intake = 0;
    lastFedTime = time(&lastFedTime);
    prettyTime = ctime(&lastFedTime);
}

Animal::Animal(std::string name,std::string food,std::string type,double intake, time_t lastFedTime){
    this->name = name;
    this->food = food;
    this->type = type;
    this->intake = intake;
    this->lastFedTime = lastFedTime;
    this->prettyTime = ctime(&(this->lastFedTime));
    if (!prettyTime.empty() && prettyTime[prettyTime.length()-1] == '\n') {
        prettyTime.erase(prettyTime.length()-1);
    }
}

Animal::~Animal(){
    std::cout << "in Animal's destructor" << std::endl;
}

std::ostream& operator<<(std::ostream &os,const Animal& a){
    std::cout 
        << std::setw(20)
        << std::left
        << a.name
        << std::setw(20)
        << std::left
        << a.food
        << std::setw(20)
        << std::left
        << a.type
        << std::setw(20)
        << std::left
        << a.intake
        << std::setw(40)
        << std::left
        << a.prettyTime
        << std::endl;
    return os;
}

std::istream& operator>>(std::istream &is, Animal &a){

    std::cout << "enter the name of the animal\n\n" << "$  " << std::flush;
    std::getline(std::cin,a.name);

    std::cout << "\nenter the type of food it eats\n\n" << "$  " << std::flush;
    std::getline(std::cin,a.food);

    std::cout << "\n" << std::endl;
    while (true){
        std::cout 
            << "enter the type of animal it is\n(herbivore or carnivore)\n\n" 
            << "$  " << std::flush;
        std::getline(std::cin,a.type);
        if(a.type.compare("herbivore") != 0 && a.type.compare("carnivore") != 0 ){
            std::cout << "please enter either 'herbivore' or 'carnivore'\n" << std::endl;
            continue;
        } else {
            break;
        }
    }

    std::cout << "\n" << std::endl;
    while (true){
        std::cout << "enter the quantity of food it eats\n(number of 'units' its food is measured in)\n\n" << "$  " << std::flush;
        try {
            validateInput<double>(a.intake);
            return is;
        } catch (...){
            std::cout << "please enter a valid number for the intake quantity\n" << std::endl;
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

std::string Animal::getPrettyTime(){
    return prettyTime;
}

std::string Animal::getType(){
    return type;
}

void Animal::updateLastFedTime(){
    time(&(this->lastFedTime));
    this->prettyTime = ctime(&(this->lastFedTime)) ;

    if (!prettyTime.empty() && prettyTime[prettyTime.length()-1] == '\n') {
        prettyTime.erase(prettyTime.length()-1);
    }
}
