#ifndef KSIAZKA_H
#define KSIAZKA_H

#include "Produkt.h" 
#include <iostream>

class Ksiazka : public Produkt {
public:
    Ksiazka(int id, std::string tytul, std::string autor, int rok, int ISBN): Produkt(id, tytul), autor(autor), rok(rok), ISBN(ISBN) {}
    void wypiszInformacje() const override
    {
        std::cout << "ID: " << getID() << ", Tytul: " << getTytul() << ", Autor: " << autor << ", Rok: " << rok << " ISBN: " << ISBN << std::endl;
                        //przez wirtualny polimorfizm pobieramy ID dla ksiazki
    }

private:
    std::string autor;
    int rok;
    int ISBN;
    //dzieki wirtualnego polimorfizmowi nie musi tu byc ID ani tytulu
};

#endif
