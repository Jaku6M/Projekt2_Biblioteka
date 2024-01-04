#include "Czytelnik.h"
#include <iostream>

Czytelnik::Czytelnik(int id, std::string imie, std::string nazwisko) : id(id), imie(imie), nazwisko(nazwisko) {}

void Czytelnik::wypozyczKsiazke(Produkt& produkt) {
    std::cout << imie << " " << nazwisko << " wypozyczyl(a) ksiazke." << std::endl;
}

int Czytelnik::getID() const {
    return id;
}

std::string Czytelnik::getImie() const {
    return imie;
}

std::string Czytelnik::getNazwisko() const {
    return nazwisko;
}