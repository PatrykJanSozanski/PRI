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

#include "funkcje.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomizuj(void){
    
    unsigned int ziarno;
    time_t zegar;
    ziarno = time(&zegar);
    srand(ziarno); //rozpoczyna randomizacje
}

int losujDlugoscCiagu(void){ //losuje dlugosc ciagu
    
    int dlugoscCiagu;
    dlugoscCiagu = (rand() % 100) + 1; //zakres <1, 100>
    
    return dlugoscCiagu;
}

int losujDlugoscLiczby(void){ //losuje dlugosc liczby
   
    int dlugoscLiczby;
    dlugoscLiczby = ((rand() % 40) + 1) * 4;
    
    return dlugoscLiczby;
}

int losuj0lub1(void){ //losuje kod liczby
   
    int element = 0;
    element = (rand() % 2);
    
    return element;
}

void wygenerujCiag(struct LiczbaBCD ciag[100], int *dlugoscCiagu){ //generuje ciag
    
    randomizuj();
    
    *dlugoscCiagu = losujDlugoscCiagu(); //wyznacza dlugosc ciagu
    int element[4];
    
    for(int i = 0; i < *dlugoscCiagu; ++i){
        ciag[i].dlugoscLiczby = losujDlugoscLiczby(); //wyznacza dlugosc liczby o indeksie i w ciagu
        for(int j = 0; j < (ciag[i].dlugoscLiczby)/4; ++j){
            for(int k = 0; k != 1; ++k){
                for(int l = 0; l < 4; ++l){
                    element[l] = losuj0lub1();
                }
                if(((1 == element[0]) && (1 == element[1])) || ((1 == element[0]) && (1 == element[2]))){ //losuje czworki BCD
                    --k; //zawraca pętle do początku
                }
                else{
                    for(int l = 0; l < 4; ++l){
                        ciag[i].kodLiczby[4 * j + l] = element[l];
                    }
                }
            }
        }
    }
    puts("WYGENEROWANO CIAG");
}

void wyswietlCiag(struct LiczbaBCD ciag[100], int dlugoscCiagu){ //wyswietla ciag
    
    printf("Dlugosc ciagu to: %d.\n",dlugoscCiagu);
    puts("POCZATEK");
    
    for (int i = 0; i < dlugoscCiagu; ++i){
        for(int j = 0; j < ciag[i].dlugoscLiczby; ++j){
            printf("%d", ciag[i].kodLiczby[j]);
        }
        printf("\n");
    }
    puts("KONIEC\n");
}

void usunZera(struct LiczbaBCD ciag[100], int dlugoscCiagu){ //usuwa zera na początku liczby
    
    for(int i = 0; i < dlugoscCiagu; ++i){
        for(int j = 0; j < ciag[i].dlugoscLiczby ; ++j){
            if((ciag[i].kodLiczby[0] == 0) && (ciag[i].kodLiczby[1] == 0) && (ciag[i].kodLiczby[2] == 0) && (ciag[i].kodLiczby[3] == 0) && (ciag[i].dlugoscLiczby > 4)){
                ciag[i].dlugoscLiczby -= 4;
                for(int k = 0; k < dlugoscCiagu; ++k){
                    ciag[i].kodLiczby[k] = ciag[i].kodLiczby[k+4];
                }
                 --j; //kolejną czwórkę sprawdza od początku
            }
            else break;
        }
    }
}


 void sortujCiagRosnaco(struct LiczbaBCD ciag[100], int dlugoscCiagu){ //sortuje ciag rosnaco
    
    int indeksMinimum;
    for(int i = 0; i < dlugoscCiagu - 1; ++i){
        indeksMinimum = i;
        for(int j = i + 1; j < dlugoscCiagu; ++j){
            if(ciag[j].dlugoscLiczby < ciag[indeksMinimum].dlugoscLiczby){ //sortuje liczby wedlug dlugosci
                indeksMinimum = j;
            }
            else if(ciag[j].dlugoscLiczby == ciag[indeksMinimum].dlugoscLiczby){ //sortuje liczby wedlug kodu, gdy ich dlugosci sa rowne
                for(int k = 0; k < ciag[j].dlugoscLiczby; ++k){
                    if(ciag[j].kodLiczby[k] < ciag[indeksMinimum].kodLiczby[k]){
                        indeksMinimum = j;
                        break;
                    }
                    else if(ciag[j].kodLiczby[k] > ciag[indeksMinimum].kodLiczby[k]){
                        break;
                    }
                }
            }
        }
        zamien(&ciag[i], &ciag[indeksMinimum]);
    }
     puts("POSORTOWANO CIAG");
}

void zamien(struct LiczbaBCD *element1, struct LiczbaBCD *element2){ //zamienia miejscami dwa elementy tablicy
    
    struct LiczbaBCD skrzynka = *element1;
    *element1 = *element2;
    *element2 = skrzynka;
}

 
