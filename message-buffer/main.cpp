#include <iostream>
#include "klasy.h"

int main() {
    Serwer serwer(2);
    Klient* k1 = new Klient("Klient1", &serwer);
    Klient* k2 = new Klient("Klient2", &serwer);
    
    k1->send("test");
    serwer.drukuj();
    std::cout<< "-------------------" << std::endl;
    k2->send("razdwatrzy");
    serwer.drukuj();
    std::cout<< "-------------------" << std::endl;
    Klient* k3 = new Klient("Klient3", &serwer);
    k3->send("powinno byc za duzo");
    serwer.drukuj();
    std::cout<< "-------------------" << std::endl;
    delete k1;
    k3->send("teraz powinno juz byc miejsce");
    serwer.drukuj();


    return 0;
}