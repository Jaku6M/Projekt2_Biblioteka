// Produkt.h

#ifndef PRODUKT_H
#define PRODUKT_H

#include <string>
#include <iostream>

class Produkt { //Klasa ktora wspomaga dodawanie nowych typow rzeczy w bibliotece (np. oprocz ksiazek dodajesz jeszcze artykuly do biblioteki itp)
public:
    Produkt(int id, std::string tytul): id(id), tytul(tytul) {}
    virtual ~Produkt() = default;  // wirtualny destruktor aby klasy pochodne tez byly destruktowane

    virtual void wypiszInformacje() const
    {
        std::cout << "ID: " << getID() << ", Tytul: " << getTytul() << std::endl;
    }
    virtual int getID() const 
    {
        return id;
    }
    virtual std::string getTytul() const
    {
        return tytul;
    }

private:
    int id;
    std::string tytul;
};

#endif
