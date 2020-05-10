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

#include <stdio.h>
#include "funkcje.h"
#include <stdlib.h>

int main(){
    
    int dlugoscCiagu;
    struct LiczbaBCD ciag[100];
    
    puts("Wcisnij ENTER, aby rozpoczac.\n");
    getchar();
    
    for(;;){
        wygenerujCiag(ciag, &dlugoscCiagu);
        usunZera(ciag, dlugoscCiagu);
        wyswietlCiag(ciag, dlugoscCiagu);
        sortujCiagRosnaco(ciag, dlugoscCiagu);
        wyswietlCiag(ciag, dlugoscCiagu);
        
        puts("Wcisnij ENTER, aby wygenerowac nowy ciag.\n");
        getchar();
        system("clear");
    }
    
    return 0;
}
