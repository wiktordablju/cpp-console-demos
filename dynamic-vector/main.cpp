#include <iostream>
#include "wektor.h"

int main() {
    wektor v(4);
    
    v[0] = 1.5;
    v[1] = 2.7;
    v[2] = 3.8;
    v[3] = 4.2;
    std::cout << "Element v[2] = " << v[2] << std::endl;
    std::cout << "Cały wektor: ";
    v.print();
    
    return 0;
}