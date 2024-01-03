// Produkt.h

#ifndef PRODUKT_H
#define PRODUKT_H

#include <string>

class Produkt {
public:
    Produkt(int id, std::string tytul);
    virtual ~Produkt() = default;  // Dodaj wirtualny destruktor
    virtual int getID() const;
    virtual std::string getTytul() const;

private:
    int id;
    std::string tytul;
};

#endif
