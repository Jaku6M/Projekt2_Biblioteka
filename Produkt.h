// Produkt.h

#ifndef PRODUKT_H
#define PRODUKT_H

#include <string>

class Produkt {
public:
    Produkt(int id, std::string tytul);
    int getID() const;
    std::string getTytul() const;

private:
    int id;
    std::string tytul;
};

#endif
