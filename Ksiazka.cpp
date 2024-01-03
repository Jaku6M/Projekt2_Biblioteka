// Ksiazka.cpp

#include "Ksiazka.h"
#include <iostream>

// Konstruktor klasy Ksiazka
Ksiazka::Ksiazka(int id, std::string tytul, std::string autor, int rok)
    : Produkt(id, tytul), autor(autor), rok(rok) {
    // Dodatkowe inicjalizacje, jeśli są potrzebne
}

// Funkcja wypisująca informacje o książce
void Ksiazka::wypiszInformacje() const {
    std::cout << "ID: " << getID() << ", Tytul: " << getTytul() << ", Autor: " << autor << ", Rok: " << rok << std::endl;
}
