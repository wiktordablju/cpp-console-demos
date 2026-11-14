#include "klasy.h"
#include <iostream>

int Klient::licznik = 0;

Klient::Klient(std::string nazwa, Serwer *serwer) {
    s = serwer;
    this->nazwa = nazwa;
    licznik++; 
}

void Klient::send(std::string msg) {
    s->receive(msg, this);
}

Klient::~Klient() {
    licznik--;
    s->receive("DEL", this);
}

int Klient::getLicznik() {
    return licznik;
}

void Serwer::receive(std::string msg, Klient *cli) {
    if (msg == "DEL") {
        for (int i = 0; i < n; i++) {
            if (tab[i].cli == cli) {
                tab[i].cli = nullptr;
                tab[i].msg = "";
                return;
            }
        }
        return;
    }
    
    for (int i = 0; i < n; i++) {
        if (tab[i].cli == cli) {
            tab[i].msg = tab[i].msg + "#" + msg;
            return;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (tab[i].cli == nullptr) {
            tab[i].cli = cli;
            tab[i].msg = msg;
            return;
        }
    }
    
    std::cout << "tablica zostala przepelniona" << std::endl;
}


Serwer::Serwer(int size) {
    n = size;
    tab = new Dane[n];
    for (int i = 0; i < n; i++) {
        tab[i].cli = nullptr;
        tab[i].msg = "";
    }
}

void Serwer::drukuj() {
    int aktywni = 0;    
    for (int i = 0; i < n; i++) {
        if (tab[i].cli != nullptr) {
            aktywni++;
            std::cout << "Klient: " << tab[i].cli->nazwa;
            std::cout << " | Wiadomości: " << tab[i].msg << std::endl;
        }
    }
    std::cout << "Liczba aktywnych klientów: " << aktywni << std::endl;
}
