#ifndef ARTYKUL_H
#define ARTYKUL_H

#include "Produkt.h"
#include <iostream>

class Artykul : public Produkt {
public:
    Artykul(int id, std::string tytul, std::string autor, int rok, int ilosccytowan): Produkt(id, tytul), autor(autor), rok(rok), ilosccytowan(ilosccytowan) {}
    void wypiszInformacje() const
    {
        std::cout << "ID: " << getID() << ", Tytul: " << getTytul() << ", Autor: " << autor << ", Rok: " << rok <<  " ilosc zacytowanych dziel: " <<ilosccytowan<< std::endl;
    }

private:
    std::string autor;
    int rok;
    int ilosccytowan;
};

#endif