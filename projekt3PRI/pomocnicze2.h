#ifndef pomocnicze2_h
#define pomocnicze2_h

#include <stdio.h>
#include "funkcje.h"

//wczytuje z pliku imie i przypisuje do odpowiedniego wskaźnika struktury
void readName(char *, Customer *, FILE *);


//wczytuje z pliku nazwisko i przypisuje do opowiedniego wskaźnika struktury
void readSurname(char *, Customer *, FILE *);

//wczytuje z pliku narzędzia i ich opis i przypisuje do odpowiedniego wskaźnika struktury
void readTools(char *, Customer **, FILE *, Customer **);

//zlicza uzytkownikow i licencje
void chChosenCount(Customer*, char);

//wyswietla uzytkownikow korzystajacych z danego narzedzia
void chChosenTool(Customer*, char);

//wyswietla uzytkownikow, ktorym licencja na wybrane narzedzie wygasa
void chChosenExp(Customer*, char);


#endif /* pomocnicze2_h */
