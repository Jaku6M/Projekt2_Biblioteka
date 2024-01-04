// Biblioteka.cpp

#include "Biblioteka.h"
#include "Ksiazka.h" 
#include "Czytelnik.h" 
#include "Student.h"
#include <algorithm>
#include <iostream>

Biblioteka::Biblioteka() : ostatnieID(0) {}

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

void Biblioteka::wyswietlStanKsiazek() const {
    std::cout << "Stan książek w bibliotece:" << std::endl;
    for (const auto& para : produkty) {
        const Ksiazka* ksiazka = dynamic_cast<const Ksiazka*>(para.second);
        if (ksiazka != nullptr) {
            ksiazka->wypiszInformacje();
        }
    }
}

void Biblioteka::wyswietlCzytelnikow() const {
    std::cout << "\n==== Lista Czytelnikow ====\n";
    for (const auto& czytelnik : czytelnicy) {
        std::cout << "ID: " << czytelnik->getID() << ", Imie: " << czytelnik->getImie()
                  << ", Nazwisko: " << czytelnik->getNazwisko();
        if (auto student = dynamic_cast<const Student*>(czytelnik)) {
            std::cout << ", Kierunek: " << student->getKierunek();
        }
        std::cout << std::endl;
    }
}

