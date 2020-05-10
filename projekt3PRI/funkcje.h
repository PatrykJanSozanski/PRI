#ifndef funkcje_h
#define funkcje_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LIT 30
#define TWOWEEKS 14*24*60*60
#define YEAR 365*24*60*60

enum Tools{ A, E, C, M, P};

typedef struct licence{
    enum Tools tool;
    unsigned int licenceNum;
    time_t dateStart;
    time_t dateEnd;
    
    struct licence* next;
}Licence;

typedef struct customer{
    char name[MAX_LIT + 1];
    char surname[MAX_LIT + 1];
    
    Licence* headL;
    
    struct customer* next;
}Customer;

//wyswietla liste dostepnych komend
void help(void);

//czyści ekran konsoli
void clean(void);

//informuje o blednym formacie wpisanej komendy
void wPattern (void);

//czyści bufor
void empBuf(void);

//wczytuje baze danych z pliku .txt
//można wczytac tylko jedna baze danych z pliku (w innym przypadku nastapi nadpisanie)
//ta funkcja nie sluzy do laczenia baz danych
//w przypadku, gdy lista nie jest pusta, funkcja sie nie wykona
Customer* loadData(FILE*, Customer*);

//zwalnia pamięć
Customer* clearData(Customer*);

//wyswietla na ekranie baze danych
void showData(Customer*);

//zlicza liczbe uzytkownikow wykupujacych licencje i liczbe licencji
void countTool(Customer*);

//wyswietla liste uzytkownikow korzystajacych aktualnie z danego narzedzia
void toolUser(Customer*);

//wyswietla liste uzytkownikow, ktorym licencja na narzedzie wygasnie w terminie 2 tygodni
void checkExp(Customer*);

//wyswietla liste uzytkownikow, ktorym licencja na wybrane narzedzie wygasnie w terminie 2 tygodni
void toolExp(Customer*);

//wyswietla wygasajace narzedzia wybranego uzytkownika
void userExp(Customer*);

//wyszukuje uzytkownika w bazie danych
void findUser(Customer*);

//dodaje nowy rekord
Customer* addUser(Customer*);

//usuwa rekord
Customer* rmUser(Customer*);

#endif /* funkcje_h */



