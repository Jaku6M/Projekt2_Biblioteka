#ifndef CZYTELNIK_H
#define CZYTELNIK_H

#include "Produkt.h"
#include <string>
#include <iostream>

class Czytelnik {
public:
    Czytelnik(int id, std::string imie, std::string nazwisko): id(id), imie(imie), nazwisko(nazwisko) {};
    //konstruktor klasy czytelnik                             lista inicjalizacyjna (czyli wrzucanie przekazanych argumentow faktycznie do obiektu klasy)

    virtual void wypozyczKsiazke(Produkt& produkt)
    //funkcja ta spodziewa się obiektu klasy Produkt jako parametru i bedzie operowac bezposrednio na przekazanym obiekcie a nie jego kopii
    {
        std::cout << imie << " " << nazwisko << "wypozyczyl(a) ksiazke o tytule: " << produkt.getTytul() << " ID: "<< produkt.getID() << std::endl;
    }
    int getID() const
    {
        return id;
    }
    std::string getImie() const
    {
        return imie;
    }
    std::string getNazwisko() const
    {
        return nazwisko;
    }

protected: //czyli dostepne dla klas dziedziczacych ale dla pozostalych sa jak private
    int id;
    std::string imie;
    std::string nazwisko;
};

#endif