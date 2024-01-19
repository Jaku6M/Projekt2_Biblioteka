#ifndef PRACOWNIK_BIBLIOTEKI_H
#define PRACOWNIK_BIBLIOTEKI_H

#include "Czytelnik.h" 

class Pracownik : public Czytelnik {// Pracownik to klasa dziedziczaca po klasie czytelnik
public:
    Pracownik(int id, std::string imie, std::string nazwisko, int identyfikator_podany): Czytelnik(id, imie, nazwisko), identyfikator(identyfikator_podany) {}
   //deklaracja konstruktora klasy Pracownik                                         lista inicjalizacyjna konstruktora wywolujaca klase bazowa 
    void wypozyczKsiazke(Produkt& produkt) 
    {
    std::cout << "Pracownik " << getImie() << " " << getNazwisko() << " o numerze ID " << getIdentyfikator() << " wypożyczył(a) książkę " << produkt.getTytul() <<  " o ID: "<< produkt.getID()<< "." << std::endl;
    }
    int getIdentyfikator() const
    {
        return identyfikator;
    };
private:
    int identyfikator; // Przechowywana informacja o nr identyfgikatora pracownika biblioteki
};

#endif