#include "Produkt.h"
#include "Ksiazka.h"
#include "Czytelnik.h"
#include "Biblioteka.h"
#include "Student.h"
#include <iostream>

int main() {
    Biblioteka biblioteka;

    while (true) {
        std::cout << "\n==== Menu ====\n";
        std::cout << "1. Dodaj ksiazke\n";
        std::cout << "2. Dodaj czytelnika\n";
        std::cout << "3. Wypozycz ksiazke\n";
        std::cout << "4. Wyjdz\n";

        int wybor;
        std::cout << "Wybierz opcje: ";
        std::cin >> wybor;

        switch (wybor) {
            case 1: {
                std::string tytul, autor;
                int rok;

                std::cout << "Podaj tytul ksiazki: ";
                std::cin.ignore(); // Ignoruj znak nowej linii w buforze
                std::getline(std::cin, tytul);

                std::cout << "Podaj autora ksiazki: ";
                std::getline(std::cin, autor);

                std::cout << "Podaj rok wydania ksiazki: ";
                std::cin >> rok;

                Produkt* ksiazka = new Ksiazka(biblioteka.pobierzNoweID(), tytul, autor, rok);
                biblioteka.dodajProdukt(ksiazka);

                std::cout << "Ksiazka dodana do biblioteki.\n";
                break;
            }
            case 2: {
                std::string imie, nazwisko, kierunek;

                std::cout << "Podaj imie czytelnika: ";
                std::cin >> imie;

                std::cout << "Podaj nazwisko czytelnika: ";
                std::cin >> nazwisko;

                std::cout << "Podaj kierunek studiow (tylko dla studentow): ";
                std::cin >> kierunek;

                Czytelnik* czytelnik;

                if (!kierunek.empty()) {
                    czytelnik = new Student(biblioteka.pobierzNoweID(), imie, nazwisko, kierunek);
                } else {
                    czytelnik = new Czytelnik(biblioteka.pobierzNoweID(), imie, nazwisko);
                }

                biblioteka.dodajCzytelnika(czytelnik);

                std::cout << "Czytelnik dodany do biblioteki.\n";
                break;
            }
            case 3: {
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
            default:
                std::cout << "Nieprawidlowy wybor. Sprobuj ponownie.\n";
        }
    }
}
