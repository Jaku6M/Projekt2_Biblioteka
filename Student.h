
#ifndef STUDENT_H
#define STUDENT_H

#include "Czytelnik.h" // Assuming Czytelnik is a base class for Student

class Student : public Czytelnik {
public:
    Student(int id, std::string imie, std::string nazwisko, std::string kierunek);
    
    // Add any specific members or functions for the Student class if needed

private:
    std::string kierunek; // Assuming kierunek is a field specific to Student
};

#endif
