#ifndef STUDENT_H
#define STUDENT_H

#include "Czytelnik.h" 

class Student : public Czytelnik {// Student to klasa dziedziczaca po klasie czytelnik
public:
    Student(int id, std::string imie, std::string nazwisko, std::string kierunek_podany): Czytelnik(id, imie, nazwisko), kierunek(kierunek_podany) {}
   //deklaracja konstruktora klasy student                                         lista inicjalizacyjna konstruktora wywolujaca klase bazowa czyli przekazujesz mu argumenty  z konstruktora studenta
    void wypozyczKsiazke(Produkt& produkt) 
    {
    std::cout << "Student " << getImie() << " " << getNazwisko() << " o kierunku " << getKierunek() << " wypożyczył(a) książkę " << produkt.getTytul() <<  " o ID: "<< produkt.getID()<< "." << std::endl;
    }
    std::string getKierunek() const
    {
        return kierunek;
    }
private:
    std::string kierunek; // Przechowywana informacja o kierunku studiowania
};

#endif