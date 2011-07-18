#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <limits>

template<class T> void validateInput(T &t){
    if (! (std::cin >> t) ){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        throw false;
    }
    std::cin.ignore();
}
#endif
