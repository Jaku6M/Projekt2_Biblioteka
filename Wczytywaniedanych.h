#ifndef WCZYTYWANIE_H
#define WCZYTYWANIE_H

#include <iostream>
#include <stdexcept>
#include <limits>

template <typename T>
T wczytajDane(const std::string& komunikat) {
    while (true) {
        try {
            T wartosc;
            std::cout << komunikat;
            if constexpr (std::is_same_v<T, std::string>) {
                // Kod wewnątrz tego bloku jest kompilowany tylko, gdy T jest typem std::string.
                // Tutaj używamy std::getline do wczytania całej linii tekstu ze standardowego wejścia.
                std::getline(std::cin, wartosc);
            } else {
                // Kod wewnątrz tego bloku jest kompilowany tylko, gdy T nie jest typem std::string.
                // Tutaj używamy standardowego operatora >> do wczytania danych dla innych typów.
                std::cin >> wartosc;
            }

            if (std::cin.fail()) {//sprawdzenie czy operacja wczytywania danych zakonczyla sie porazka
                throw std::runtime_error("Blad: Nieprawidlowy format danych.");//jesli tak to wyswietl komunikat
            }

            return wartosc;

        } catch (const std::exception& e) {
            std::cerr << e.what() << '\n';//Linia ta wypisuje komunikat błędu na standardowe wyjście błędów 
            std::cin.clear();  // Ta linia służy do czyszczenia flagi błędu w strumieniu wejściowym std::cin jak uzytkownik juz dobrze wpisze
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignorowanie nieprawidłowych danych w strumieniu wejsciowym cin
     
        }
    }
}

#endif
