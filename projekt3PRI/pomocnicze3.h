#ifndef pomocnicze3_h
#define pomocnicze3_h

#include <stdio.h>
#include "funkcje.h"

//wczytuje narzedzie
void readTool(char *, Licence **);

//wczytuje liczbe licencji
void readLicenceNum(char *, FILE *, Licence **);

//wczytuje date startu
void readStartDate(char *, FILE *dataBase, Licence **);

//wczytuje date konca
void readEndDate(char *, FILE *dataBase, Licence **);

#endif /* pomocnicze3_h */
