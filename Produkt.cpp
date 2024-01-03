// Produkt.cpp

#include "Produkt.h"

Produkt::Produkt(int id, std::string tytul)
    : id(id), tytul(tytul) {}

int Produkt::getID() const {
    return id;
}

std::string Produkt::getTytul() const {
    return tytul;
}
