#include "Produkt.h"
#include "Ksiazka.h"
#include "Artykul.h"
#include "Czytelnik.h"
#include "Biblioteka.h"
#include "Student.h"
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

        int wybor;
        std::cout << "Wybierz opcje: ";
        std::cin >> wybor;

        switch (wybor)
        {
            case 1:
                {
                    std::cout << "\n==== Menu ====\n";
                    std::cout << "1. Dodaj ksiazke do bazy danych\n";
                    std::cout << "2. Dodaj artykul do bazy danych\n";

                    int wybor_pozycji;
                    std::cout << "Wybierz opcje: ";
                    std::cin >> wybor_pozycji;
                        switch (wybor_pozycji) 
                        {
                            case 1:
                            {
                                std::string tytul, autor;
                                int rok;
                                int ISBN;

                                std::cout << "Podaj tytul ksiazki: ";
                                std::cin.ignore(); // Ignoruj znak nowej linii w buforze
                                std::getline(std::cin, tytul);

                                std::cout << "Podaj autora ksiazki: ";
                                std::getline(std::cin, autor);

                                std::cout << "Podaj rok wydania ksiazki: ";
                                std::cin >> rok;
                                
                                std::cout << "Podaj ISBN: ";
                                std::cin >> ISBN;

                                Produkt* ksiazka = new Ksiazka(biblioteka.pobierzNoweID(), tytul, autor, rok, ISBN);
                                biblioteka.dodajProdukt(ksiazka);

                                std::cout << "Ksiazka dodana do biblioteki.\n";
                                break;
                            }
                            case 2:
                            {
                                std::string tytul, autor;
                                int rok, ilosccytowan;

                                std::cout << "Podaj tytul artykulu: ";
                                std::cin.ignore();
                                std::getline(std::cin, tytul);

                                std::cout << "Podaj autora artykulu: ";
                                std::getline(std::cin, autor);

                                std::cout << "Podaj rok publikacji artykulu: ";
                                std::cin >> rok;

                                std::cout << "Podaj ilosc zacytowanych dziel: ";
                                std::cin >> ilosccytowan;

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
                std::string imie, nazwisko, kierunek;

                std::cout << "Podaj imie czytelnika: ";
                std::cin >> imie;

                std::cout << "Podaj nazwisko czytelnika: ";
                std::cin >> nazwisko;

                std::cout << "Podaj kierunek studiow (tylko dla studentow): ";
                std::cin >> kierunek;

                Czytelnik* czytelnik;

                if (!kierunek.empty()) {
                    czytelnik = new Student(biblioteka.pobierzNoweID_czytelnika(), imie, nazwisko, kierunek);//wymienic to na make_unique!!!!!!
                } else {
                    czytelnik = new Czytelnik(biblioteka.pobierzNoweID_czytelnika(), imie, nazwisko);
                }

                biblioteka.dodajCzytelnika(czytelnik);

                std::cout << "Czytelnik dodany do biblioteki.\n";
                break;
            }
            case 3: 
            {
                int czytelnikID, ksiazkaID;

                std::cout << "Podaj ID czytelnika: ";
                std::cin >> czytelnikID;

                std::cout << "Podaj ID ksiazki: ";
                std::cin >> ksiazkaID;

                biblioteka.wypozyczProdukt(czytelnikID, ksiazkaID);
                break;
            }
            case 4:
                std::cout << "Zakonczono program.\n";
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

                int wybor_typu;
                std::cout << "Wybierz opcje: ";
                std::cin >> wybor_typu;

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
                std::cout << "Nieprawidlowy wybor. Sprobuj ponownie.\n";
        }
    }
}
