#ifndef CZYTELNIK_H
#define CZYTELNIK_H

#include <string>
#include "Produkt.h"

class Czytelnik {
public:
    Czytelnik(int id, std::string imie, std::string nazwisko);

    virtual void wypozyczKsiazke(Produkt& produkt);
    int getID() const;

protected:
    int id;
    std::string imie;
    std::string nazwisko;
};

#endif