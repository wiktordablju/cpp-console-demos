#ifndef WEKTOR_H
#define WEKTOR_H

#include <iostream>

class wektor {
private:
    double* dane;
    int rozmiar;

public:
    wektor();                           
    wektor(int rozmiar);               
    wektor(int rozmiar, double wartosc); 
    wektor(const wektor& inny);       
    
    ~wektor();
    
    wektor& operator=(const wektor& inny);
    
    double& operator[](int indeks);
    const double& operator[](int indeks) const;
    
    wektor operator+(const wektor& inny) const;
    wektor operator*(double skalar) const;
    
    double dotproduct(const wektor& inny) const;
    
    int getRozmiar() const;
    void print() const;

};

#endif