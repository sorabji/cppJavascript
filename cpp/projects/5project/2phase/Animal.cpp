#include "Animal.h"

Animal::Animal(){
    name = "";
    food = "";
    intake = 0;
    lastFedTime = 0;
    prettyTime = "null";
}

Animal::Animal(std::string name,std::string food,double intake, time_t lastFedTime){
    this->name = name;
    this->food = food;
    this->intake = intake;
    this->lastFedTime = lastFedTime;
    if(0 == lastFedTime) this->prettyTime = "null";
    else this->prettyTime = ctime(&(this->lastFedTime));
}

Animal::~Animal(){
    name = "";
    food = "";
    intake = 0;
    lastFedTime = 0;
    prettyTime = "";
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

    //std::cin >> a.name;

    std::cout << "\n\nenter the type of food it eats\n\n" << "$  " << std::flush;
    std::cin.clear();
    std::getline(std::cin,a.food);

    //std::cin >> a.food;
    while (true){
        std::cout << "\n\nenter the quantity of food it eats\n(number of 'units' its food is measured in)\n\n" << "$  " << std::flush;
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

std::string Animal::getPrettyTime(){
    return prettyTime;
}

void Animal::updateLastFedTime(){
    time(&(this->lastFedTime));
    this->prettyTime = ctime(&(this->lastFedTime)) ;

    if (!prettyTime.empty() && prettyTime[prettyTime.length()-1] == '\n') {
        prettyTime.erase(prettyTime.length()-1);
    }

}
