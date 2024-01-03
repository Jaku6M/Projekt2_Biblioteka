// Ksiazka.h

#ifndef KSIAZKA_H
#define KSIAZKA_H

#include "Produkt.h"  // Dodaj nagłówek klasy bazowej

class Ksiazka : public Produkt {
public:
    Ksiazka(int id, std::string tytul, std::string autor, int rok);
    void wypiszInformacje() const;

private:
    std::string autor;
    int rok;
};

#endif
