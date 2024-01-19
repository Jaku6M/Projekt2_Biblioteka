// Biblioteka.h

#ifndef BIBLIOTEKA_H
#define BIBLIOTEKA_H

#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include "Produkt.h"
#include "Czytelnik.h"
#include "Biblioteka.h"
#include "Ksiazka.h" 
#include "Artykul.h"
#include "Student.h"
#include "Pracownik_biblioteki.h"

class Biblioteka {
public:
    Biblioteka(): ostatnieID(0), ostatnieID_czytelnika(0) {};
    //lista inicjalizujaca wartosci ID pozycji w bazie danych i ID czytelnikow na zera
    void dodajProdukt(Produkt* produkt)//uzywamy tu wskaznika do pracy na rzeczywistym obiekcie a nie na jego kopii - tak by bylo jak bysmy pracowali na kopii:(Produkt produkt)
    //metoda przyjmuje wskaznik do obiektow typu produkt (wskaznik moze wskazywac na ksiazka lub artykul) 
    {
        produkty[produkt->getID()] = produkt;
    //Przypisanie wartości "produkt" (czyli ksiazki lub artykulu podanego w arg funkcji) do elementu mapy o kluczu uzyskanym w [] (czyli ID)
    }
    void dodajCzytelnika(Czytelnik* czytelnik)//uzywamy tu wskaznika do pracy na rzeczywistym obiekcie a nie na jego kopii - tak by bylo jak bysmy pracowali na kopii:(Produkt produkt)
    {
        czytelnicy.push_back(czytelnik);
        //wrzucamy wskazniki czytelnikow do wektora czytelnikow    
    }
    int pobierzNoweID()
    {
        return ++ostatnieID;
    }

    int pobierzNoweID_czytelnika()
    {
       return ++ostatnieID_czytelnika;
    }

    void wypozyczProdukt(int czytelnikID, int produktID)
{                                                                           // Wyrażenie lambda jest predykatem, który sprawdza, czy ID czytelnika zgadza się z czytelnikID.
        auto itCzytelnik = std::find_if(czytelnicy.begin(), czytelnicy.end(), [czytelnikID](Czytelnik* c) {return c->getID() == czytelnikID;});
        //algorytm STL, który szuka elementu spełniającego podany warunek w zakresie //Przeszukujemy wektor czytelnicy w poszukiwaniu obiektu Czytelnik, którego ID jest równe czytelnikID.
        auto itProdukt = produkty.find(produktID);
        //szuka w mapie produktu o zadanym ID. Wynik przypisujemy do iteratora itProdukt.

        if (itCzytelnik != czytelnicy.end() && itProdukt != produkty.end()) 
        //sprawdz czy znaleziono czytelnika i produkt
        //czytelnicy.end() nie wskazuje na ostatni element wektora, ale na "jeden-past-the-end" (jeden za ostatnim) element, co oznacza, że iterator ten wskazuje na pozycję za ostatnim elementem wektora
        {                                   //a do metody podaje odwolanie do drugiego elementu pary w mapie Produktow
            (*itCzytelnik)->wypozyczKsiazke(*(itProdukt->second));
            //wywołujemy metodę wypozyczKsiazke na obiekcie wskazywanym przez iterator itCzytelnik
        } 
        else 
        {
            std::cout << "Nie znaleziono czytelnika lub ksiazki." << std::endl;
        }
    }
    void wyswietlCzytelnikow() const
    {
        std::cout << "\n==== Lista Czytelnikow ====\n";
        for (const auto& czytelnik : czytelnicy) 
        //iteracja przez kazdy element wektora czytelnicy
        //const aut& czytelnik to zmienna przechowujaca kazdy element z wektora czytelnicy
        //const: Oznacza, że elementy są stałe, co oznacza, że nie można ich modyfikować przez zmienną czytelnik wewnątrz pętli.
        //auto: Automatycznie dedukuje typ elementu, który jest przechowywany w wektorze czytelnicy. W ten sposób, nie musisz ręcznie określać typu (np. Czytelnik), co może być wygodne.
        // &: Oznacza, że czytelnik jest referencją do obiektu. W ten sposób unika się kopiowania obiektów, co może być bardziej wydajne.

        {
            std::cout << "ID: " << czytelnik->getID() << ", Imie: " << czytelnik->getImie()<< ", Nazwisko: " << czytelnik->getNazwisko();
            //dla znalezionego przez petle for elementu wypisz 
            if (auto student = dynamic_cast<const Student*>(czytelnik)) 
            {
                std::cout << ", Kierunek: " << student->getKierunek();
            }
            else if (auto pracownik = dynamic_cast<const Pracownik*>(czytelnik)) 
            {
                std::cout << ", nr identyfikatora: " << pracownik->getIdentyfikator();
            }
            std::cout << std::endl;
        }
    }

    void wyswietlStanKsiazek() const
    {
        std::cout << "Stan książek w bibliotece:" << std::endl;
        for (const auto& para : produkty) 
        /*
        Iteruje przez wszystkie pary klucz-wartość w mapie produkty.
         para to para klucz-wartość, gdzie para.first to klucz (ID produktu), a para.second to wartość (wskaźnik do obiektu Produkt).
        */
        {
            const Ksiazka* ksiazka = dynamic_cast<const Ksiazka*>(para.second);
            //sprawdzamy czy wykryty przez iterator obiekt jest instancja Ksiazka poprzez dynamiczne rzutowanie wskaźnika do obiektu Produkt na wskaźnik do obiektu Ksiazka.
            // (a tak naprawde na drugi element mapy czyli wartosc)
            if (ksiazka != nullptr) 
            {
                ksiazka->wypiszInformacje();
                //Jeśli obiekt jest instancją Ksiazka, wywołuje na nim metodę wypiszInformacje, która wypisuje informacje o danej książce.
            }
        }
    }

    void wyswietlStanArtykulow() const
    {
        std::cout << "Stan artykulow w bibliotece:" << std::endl;
        for (const auto& para : produkty) 
        {
            const Artykul* artykul = dynamic_cast<const Artykul*>(para.second);
            if (artykul != nullptr) 
            {
                artykul->wypiszInformacje();
            }
        }
    } 

    const std::map<int, Produkt*>& getProdukty() const
    //nie zmieniamy obiektu//potem typ obiektu taki dziwny ale taki jest wlasnie!//& zwraca referencje do mapy a nie kopie
    {
        return produkty;
    }

    const std::vector<Czytelnik*>& getCzytelnicy() const
    {
        return czytelnicy;
    }

private:
    int ostatnieID;
    int ostatnieID_czytelnika;
    std::map<int, Produkt*> produkty;//stworzenie mapy gdzie klucz jest intem a wartosc to wskaznik na produkt (czyli ksiazka lub biblioteka)
    std::vector<Czytelnik*> czytelnicy;//stworzenie wektora WSKAZNIKOW!!
};

#endif
