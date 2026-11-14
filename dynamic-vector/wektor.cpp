#include "wektor.h"
#include <iostream>
#include <stdexcept>

wektor::wektor() : dane(nullptr), rozmiar(0) {}

wektor::wektor(int rozmiar) : rozmiar(rozmiar) {
    if (rozmiar < 0) {
        std::cout << "Rozmiar nie może być ujemny";
    }
    dane = new double[rozmiar];
    for (int i = 0; i < rozmiar; i++) {
        dane[i] = 0.0;
    }
}

wektor::wektor(int rozmiar, double wartosc) : rozmiar(rozmiar) {
    if (rozmiar < 0) {
        std::cout << "Rozmiar nie może być ujemny";
    }
    dane = new double[rozmiar];
    for (int i = 0; i < rozmiar; i++) {
        dane[i] = wartosc;
    }
}

wektor::wektor(const wektor& inny) : rozmiar(inny.rozmiar) {
    dane = new double[rozmiar];
    for (int i = 0; i < rozmiar; i++) {
        dane[i] = inny.dane[i];
    }
}

wektor::~wektor() {
    delete[] dane;
}

wektor& wektor::operator=(const wektor& inny) {
    if (this != &inny) {
        delete[] dane;
        rozmiar = inny.rozmiar;
        dane = new double[rozmiar];
        for (int i = 0; i < rozmiar; i++) {
            dane[i] = inny.dane[i];
        }
    }
    return *this;
}

double& wektor::operator[](int indeks) {
    if (indeks < 0 || indeks >= rozmiar) {
        std::cout << "Indeks poza zakresem";
    }
    return dane[indeks];
}

const double& wektor::operator[](int indeks) const {
    if (indeks < 0 || indeks >= rozmiar) {
        std::cout << "Indeks poza zakresem";    
    }
    return dane[indeks];
}

wektor wektor::operator+(const wektor& inny) const {
    if (rozmiar != inny.rozmiar) {
        std::cout << "Wektory muszą mieć ten sam rozmiar";
    }
    wektor wynik(rozmiar);
    for (int i = 0; i < rozmiar; i++) {
        wynik.dane[i] = dane[i] + inny.dane[i];
    }
    return wynik;
}

wektor wektor::operator*(double skalar) const {
    wektor wynik(rozmiar);
    for (int i = 0; i < rozmiar; i++) {
        wynik.dane[i] = dane[i] * skalar;
    }
    return wynik;
}

double wektor::dotproduct(const wektor& inny) const {
    if (rozmiar != inny.rozmiar) {
        std::cout << "Wektory muszą mieć ten sam rozmiar";
    }
    double suma = 0.0;
    for (int i = 0; i < rozmiar; i++) {
        suma += dane[i] * inny.dane[i];
    }
    return suma;
}

int wektor::getRozmiar() const {
    return rozmiar;
}

void wektor::print() const {
    std::cout << "[";
    for (int i = 0; i < rozmiar; i++) {
        std::cout << dane[i];
        if (i < rozmiar - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}
