#ifndef pomocnicze_h
#define pomocnicze_h

#include <stdio.h>
#include <string.h>
#include "stdbool.h"
#include "funkcje.h"
#define MAX_LIT 30

//otwieranie wybranego pliku .txt
FILE* openFile(FILE*);

//zamykanie pliku .txt
void closeFile(FILE*);

//sprawdza czy lista jest pusta
bool isEmpty(Customer*);

//wczytuje dane z pliku .txt
Customer* readFile(Customer*, FILE*);

//wyswietla baze danych
void show(Customer*);

//szuka ostatniego elementu listy
Customer* findLast(Customer*);

//zwalnia pamiec narzedzi
void clearTools(Licence*);

//otwiera menu wyboru narzedzia
void chooseCount(Customer*);

//otwiera menu wyboru narzedzia
void chooseTool(Customer*);

//wyswietla liste uzytkownikow, ktorych licencja konczy sie w okresie 2 tygodni
void showExp(Customer*);

//wyswietla menu wyboru narzedzia
void chooseToolExp(Customer*);

//wyswietla wygasajace narzedzia wybranego uzytkownika
void chooseUserExp(Customer*);

//wyszukuje uzytkownika po imieniu i nazwisku
void find(Customer*);

//dodaje rekord
Customer* add(Customer*);

//usuwa rekord po imieniu i nazwisku
Customer* rm(Customer*);


#endif /* pomocnicze_h */
