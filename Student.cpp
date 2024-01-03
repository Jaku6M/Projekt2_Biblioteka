// Student.cpp

#include "Student.h"

// Constructor for the Student class
Student::Student(int id, std::string imie, std::string nazwisko, std::string kierunek)
    : Czytelnik(id, imie, nazwisko), kierunek(kierunek) {
    // Additional initialization for the Student class, if needed
}

// Add any additional member function implementations for the Student class if needed
