#ifndef BIBLIOTEKA_H
#define BIBLIOTEKA_H

#include <vector>
#include <map>
#include "Produkt.h"
#include "Czytelnik.h"

class Biblioteka {
public:
    void dodajProdukt(Produkt* produkt);
    void dodajCzytelnika(Czytelnik* czytelnik);
    void wypozyczProdukt(int czytelnikID, int produktID);
    int pobierzNoweID();

private:
    int ostatnieID;
    std::map<int, Produkt*> produkty;
    std::vector<Czytelnik*> czytelnicy;
};

#endif
