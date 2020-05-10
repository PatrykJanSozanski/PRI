/*
 PRI
 PROJEKT2
 
 tresc zadania:
 "Dany ciag co najwyzej 40-cyfrowych liczb calkowitych w kodzie BCD (nie moga byc one reprezentowane wewnętrznie jako zaden typ liczbowy).
 Zalozyc, ze dlugosc ciagu jest nie wieksza niz 100. Wprowadzanie konczy sie slowem KONIEC podanym zamiast liczby.
 Wynikiem powinien byc wyswietlony ciag liczb danych uporzadkowany w/g rosnacej wartosci.
 Zastosowac sortowanie metoda prostego wybierania."
 
 autor: Patryk Jan Sozański
 grupa: 1I5
 nr albumu: 300258
 
 listopad 2018
 */

#ifndef funkcje_h
#define funkcje_h

#include <stdio.h>

struct LiczbaBCD{
    int dlugoscLiczby;
    int kodLiczby[160];
};

void randomizuj(void); //funkcja rozpoczyna rondomizaję liczb

int losujDlugoscCiagu(void); //losuje dlugosc ciągu

int losujDlugoscLiczby(void); //losuje dlugosc wyrazu

int losuj0lub1(void); //generuje czworki BCD

void wygenerujCiag(struct LiczbaBCD ciag[100], int*); //generuje ciag

void wyswietlCiag(struct LiczbaBCD ciag[100], int); //wyswietla ciag

void usunZera(struct LiczbaBCD ciag[100], int); //usuwa zeraz powstale na poczatku wyrazow

void sortujCiagRosnaco(struct LiczbaBCD ciag[100], int); //sortuje rosnaco

void zamien(struct LiczbaBCD*, struct LiczbaBCD*); //zamienia miejscami elementy tablicy


#endif /* funkcje_h */

