#include "Produkt.h"
#include "Ksiazka.h"
#include "Artykul.h"
#include "Czytelnik.h"
#include "Biblioteka.h"
#include "Student.h"
#include "Wczytywaniedanych.h"
#include <iostream>

int main() {
    Biblioteka biblioteka;

    while (true) {
        std::cout << "\n==== Menu ====\n";
        std::cout << "1. Dodaj pozycje do bazy danych\n";
        std::cout << "2. Dodaj czytelnika\n";
        std::cout << "3. Wypozycz ksiazke\n";
        std::cout << "4. Wyjdz\n";
        std::cout << "5. Wyswietl czytelnikow\n"; 
        std::cout << "6. Wyswietl baze danych\n";

        int wybor = wczytajDane<int>("Wybierz opcje: ");

        switch (wybor)
        {
            case 1:
                {
                    std::cout << "\n==== Menu ====\n";
                    std::cout << "1. Dodaj ksiazke do bazy danych\n";
                    std::cout << "2. Dodaj artykul do bazy danych\n";

                    int wybor_pozycji = wczytajDane<int>("Wybierz opcje: ");
                        switch (wybor_pozycji) 
                        {
                            case 1:
                            {
                                std::string tytul = wczytajDane<std::string>("Podaj tytul ksiazki: ");
                                std::string autor = wczytajDane<std::string>("Podaj autora ksiazki: ");
                                int rok = wczytajDane<int>("Podaj rok wydania ksiazki: ");     
                                int ISBN = wczytajDane<int>("Podaj ISBN: ");

                                Produkt* ksiazka = new Ksiazka(biblioteka.pobierzNoweID(), tytul, autor, rok, ISBN);//Tworzy nowy obiekt klasy Ksiazka na stercie (heap) przy użyciu operatora new. 
                                biblioteka.dodajProdukt(ksiazka);//Przekazuje wskaźnik ksiazka do metody dodajProdukt obiektu klasy Biblioteka

                                std::cout << "Ksiazka dodana do biblioteki.\n";
                                break;
                            }
                            case 2:
                            {
                                std::string tytul = wczytajDane<std::string>("Podaj tytul artykulu: ");
                                std::string autor = wczytajDane<std::string>("Podaj autora artykulu: ");
                                int rok = wczytajDane<int>("Podaj rok publikacji artykulu: ");     
                                int ilosccytowan = wczytajDane<int>("Podaj ilosc zacytowanych dziel: ");

                                Produkt* artykul = new Artykul(biblioteka.pobierzNoweID(), tytul, autor, rok, ilosccytowan);
                                biblioteka.dodajProdukt(artykul);

                                std::cout << "Artykul dodany do biblioteki.\n";
                                break;
                            }
                        }
                        break;
                }
            case 2:
                {
                    std::string imie = wczytajDane<std::string>("Podaj imie czytelnika: ");
                    std::string nazwisko = wczytajDane<std::string>("Podaj nazwisko czytelnika: ");
                    std::cout << "\n==== Menu ====\n";
                    std::cout << "1. Dodaj Studenta do bazy danych\n";
                    std::cout << "2. Dodaj Czytelnika do bazy danych\n";

                    int wybor_pozycji = wczytajDane<int>("Wybierz opcje: ");
                        switch (wybor_pozycji) 
                        {
                            case 1:
                            {
                                std::string kierunek = wczytajDane<std::string>("Podaj kierunek studiow (tylko dla studentow): ");
                                Czytelnik* czytelnik;//tworzymy wskaznik na obiekt typu Czytelnik wskaznik nazywa sie czytelnik
                                czytelnik = new Student(biblioteka.pobierzNoweID_czytelnika(), imie, nazwisko, kierunek);
                                biblioteka.dodajCzytelnika(czytelnik);
                                std::cout << "Student dodany do biblioteki.\n";
                                break;
                            }
                            case 2:
                            {
                                Czytelnik* czytelnik;//tworzymy wskaznik na obiekt typu Czytelnik wskaznik nazywa sie czytelnik
                                czytelnik = new Czytelnik(biblioteka.pobierzNoweID_czytelnika(), imie, nazwisko);
                                biblioteka.dodajCzytelnika(czytelnik);
                                std::cout << "Czytelnik dodany do biblioteki.\n";
                                break;
                            }
                        }
                        break;
                }
            case 3: 
            {   
                int czytelnikID = wczytajDane<int>("Podaj ID czytelnika: ");
                int ksiazkaID = wczytajDane<int>("Podaj ID ksiazki: ");

                biblioteka.wypozyczProdukt(czytelnikID, ksiazkaID);
                break;
            }
            case 4:
                std::cout << "Zakonczono program.\n";

                //zwalniamy pamiec dynamicznie zaalokowana:
                for(const auto& para : biblioteka.getProdukty())
                {
                    delete para.second;//tylko to zwalniamy bo tylko to jest dynamicznie alokowane
                }

                for(const auto& czytelnik : biblioteka.getCzytelnicy())
                {
                    delete czytelnik;
                }
                return 0;
            case 5:
            {
                biblioteka.wyswietlCzytelnikow();
                break;
            }
            case 6: 
            {
                std::cout << "\n==== Menu ====\n";
                std::cout << "1. Wyswietl ksiazki w bazie danych\n";
                std::cout << "2. Wyswietl artykuly w bazie danych\n";

                int wybor_typu = wczytajDane<int>("Wybierz opcje: ");               

                switch (wybor_typu)
                {
                    case 1:
                        biblioteka.wyswietlStanKsiazek();
                        break;
                    case 2:
                        biblioteka.wyswietlStanArtykulow();
                        break;
                    default:
                        break;
                }
                break;
            }
            default:
            std::cout << "Zla liczba wpisz liczbe w zakresie";
            break;
        }
    }
}
