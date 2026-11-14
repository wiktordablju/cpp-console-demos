#ifndef KLASY_H
#define KLASY_H
#include <string>

class Klient;

struct Dane {
    Klient *cli;
    std::string msg; 
};

class Serwer {
private:
    Dane * tab; 
    int n; 
public:
    void receive(std::string msg, Klient *cli);
    Serwer(int size);
    void drukuj();
};

class Klient
{
private:
    Serwer *s;
    std::string nazwa;
    static int licznik;

public:
    Klient(std::string nazwa, Serwer *serwer);
    void send(std::string msg);
    ~Klient();
    static int getLicznik();
    friend class Serwer;
};

#endif