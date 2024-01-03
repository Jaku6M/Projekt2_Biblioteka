#include "Biblioteka.h"
#include <algorithm>
#include <iostream>

void Biblioteka::dodajProdukt(Produkt* produkt) {
    produkty[produkt->getID()] = produkt;
}

void Biblioteka::dodajCzytelnika(Czytelnik* czytelnik) {
    czytelnicy.push_back(czytelnik);
}

void Biblioteka::wypozyczProdukt(int czytelnikID, int produktID) {
    auto itCzytelnik = std::find_if(czytelnicy.begin(), czytelnicy.end(), [czytelnikID](Czytelnik* c) {
        return c->getID() == czytelnikID;
    });

    auto itProdukt = produkty.find(produktID);

    if (itCzytelnik != czytelnicy.end() && itProdukt != produkty.end()) {
        (*itCzytelnik)->wypozyczKsiazke(*(itProdukt->second));
    } else {
        std::cout << "Nie znaleziono czytelnika lub ksiazki." << std::endl;
    }
}

int Biblioteka::pobierzNoweID() {
    return ++ostatnieID;
}