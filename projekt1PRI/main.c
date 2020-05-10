/*
 PRI
 PROJEKT1
 
 tresc zadania:
 "Dokonac konwersji liczby zapisanej w osemkowym systemie liczbowym do podstawy m=2...16"
 
 autor: Patryk Jan Sozański
        grupa: 1I5
        nr albumu: 300258
 
 pazdziernik 2018
*/

#include <stdio.h>
#include <stdlib.h> //funkcja exit i system("clear")
#include <string.h>
#include <stdbool.h> //typ bool
#include <ctype.h> //funkcja isdigit
#include <math.h> //funkcja pow

void wyczyscBufor (void);
bool sprawdzDlugosc(char liczbaWTablicy[]);
bool sprawdzPoprawnosc(char liczbaWTablicy[]);
long long zamien8na10(long long int liczba8);
void zamien8na2 (long long int liczba8);
void zamien8na16 (long long int liczba8);

int main(void)
{
    puts("\nWitaj!");
    puts("Jestem programem komputerowym, ktory zamienia liczby zapisane w systemie osemkowym na liczby zapisane w innych systemach liczbowych.");
    
    for(;;) //nieskonczona petla
    {
        char wybor;
        
        puts("Jak moge Ci pomoc?");
        puts("\n(Wybiez jedna z ponizszych opcji, wciskajac przypisany do niej numer i zatwierdz klawiszem ENTER)");
        puts("\nOpcje:");
        puts("1. Zamien liczbe zapisana w systemie osemkowym na liczbe zapisana w systemie dwojkowym");
        puts("2. Zamien liczbe zapisana w systemie osemkowym na liczbe zapisana w systemie dziesietnym");
        puts("3. Zamien liczbe zapisana w systemie osemkowym na liczbe zapisana w systemie szesnastkowym");
        puts("0. Wyjdz");
        
        wybor = getchar();
        wyczyscBufor(); //czysci bufor po to, aby program odczytał jedynie pierwszy znak
        
        long long int poprawnaLiczbaW8;
        bool jestPoprawnaLiczbaw8 = true;
        bool jestPoprawnaDlugosc = true;
        char liczba[20];
        
        for(int i = 0; i < 20; ++i) //przypisuje '\0' do każdego elementu tablicy
        {
            liczba[i] = '\0';
        }
        
        switch (wybor)
        {
            case '1':
                puts("Wpisz liczbe zapisana w systemie osemkowym (liczba powinna byc zapisana jedynie za pomoca cyfr z zakresu 0-7 i jej maksymalna dlugosc to 19 znakow):");
                scanf("%s", liczba);
                
                jestPoprawnaDlugosc = sprawdzDlugosc(liczba); //uzywa funkcji sprawdzDlugosc
                jestPoprawnaLiczbaw8 = sprawdzPoprawnosc(liczba); //uzywa funkcji sprawdzPoprawnosc
           
                 if((jestPoprawnaLiczbaw8 == true) && (jestPoprawnaDlugosc == true))
                 {
                     poprawnaLiczbaW8 = atoll(liczba); //zamienia tablice znakow na liczbe long long int
                     printf("Liczba %lld zapisana w osemkowym systemie liczbowym odpowiada liczbie ", poprawnaLiczbaW8); //uzywa funkcji zamien8na10
                     zamien8na2(poprawnaLiczbaW8);
                     puts(" zapisanej w dwojkowym systemie liczbowym.");
                     puts("Wcisnij ENTER, aby sprobowac jeszcze raz.");
                 }
                break;
                
            case '2':
                
                puts("Wpisz liczbe zapisana w systemie osemkowym (liczba powinna byc zapisana jedynie za pomoca cyfr z zakresu 0-7 i jej maksymalna dlugosc to 19 znakow):");
                scanf("%s", liczba);
                
                jestPoprawnaDlugosc = sprawdzDlugosc(liczba); //uzywa funkcji sprawdzDlugosc
                jestPoprawnaLiczbaw8 = sprawdzPoprawnosc(liczba); //uzywa funkcji sprawdzPoprawnosc
                
                if((jestPoprawnaLiczbaw8 == true) && (jestPoprawnaDlugosc == true))
                {
                    poprawnaLiczbaW8 = atoll(liczba); //zamienia tablice znakow na liczbe long long int
                    printf("Liczba %lld zapisana w osemkowym systemie liczbowym odpowiada liczbie %lld zapisanej w dziesietnym systemie liczbowym.", poprawnaLiczbaW8, zamien8na10(poprawnaLiczbaW8)); //uzywa funkcji zamien8na10
                    puts("\nWcisnij ENTER, aby sprobowac jeszcze raz.");
                }
                break;
                
            case '3':
            
                puts("Wpisz liczbe zapisana w systemie osemkowym (liczba powinna byc zapisana jedynie za pomoca cyfr z zakresu 0-7 i jej maksymalna dlugosc to 19 znakow):");
                scanf("%s", liczba);
                
                jestPoprawnaDlugosc = sprawdzDlugosc(liczba); //uzywa funkcji sprawdzDlugosc
                jestPoprawnaLiczbaw8 = sprawdzPoprawnosc(liczba); //uzywa funkcji sprawdzPoprawnosc
                
                if((jestPoprawnaLiczbaw8 == true) && (jestPoprawnaDlugosc == true))
                {
                    poprawnaLiczbaW8 = atoll(liczba); //zamienia tablice znakow na liczbe long long int
                    printf("Liczba %lld zapisana w osemkowym systemie liczbowym odpowiada liczbie ", poprawnaLiczbaW8); //uzywa funkcji zamien8na10
                    zamien8na16(poprawnaLiczbaW8);
                    puts(" zapisanej w szesnastkowym systemie liczbowym.");
                    puts("Wcisnij ENTER, aby sprobowac jeszcze raz.");
                }
                break;
                
            case '0':
                exit(0); //konczy prace programu i zwraca 0
                break;
                
            default: puts("Nie znam takiej opcji. Wcisnij ENTER, aby sprobowac jeszcze raz!");
                break;
        }
        getchar(); getchar(); //przejdzie dalej jedynie po wcisnieciu dowolnego klawisza
        system("clear"); //czysci konsole
    }
    return 0;
}

//ciała funkcji

void wyczyscBufor(void) //czysci
{
    char c;
    
    do
        c = getchar();
    while(c != '\n' && c != EOF);
}

bool sprawdzDlugosc(char liczbaWTablicy[])
{
    bool poprawnosc = true;
    
    if(liczbaWTablicy[19] != '\0') //sprawdza czy liczba ma poprawna dlugosc
    {
        puts("Wpisana liczba jest za dluga. Maksymalna liczba znakow to 19. Wcisnij ENTER, aby sprobowac jeszcze raz.");
        poprawnosc = false;
    }
    return poprawnosc;
}

bool sprawdzPoprawnosc(char liczbaWTablicy[])
{
    bool poprawnosc = true;
    
    for (int i = 0; i<20; ++i)
    {
        if((!isdigit(liczbaWTablicy[i]) && (liczbaWTablicy[i] != '\0')) || ((liczbaWTablicy[i] == '8' ) || (liczbaWTablicy[i] == '9'))) //sprawdza czy liczba jest poprawnie zapisana
        {
            puts("Nieprawidlowy format wpisanej liczby. Dozwolone jedynie cyfry z przedziału 0-7. Wcisnij ENTER, aby sprobowac jeszcze raz.");
            poprawnosc = false;
            break;
        }
    
    }
    return poprawnosc;
}

long long zamien8na10(long long int liczba8)
{
    long long int liczba10 = 0;
    int i = 0;
    
    while(liczba8 != 0)
    {
        liczba10 += (liczba8 % 10) * pow(8,i);
        ++i;
        liczba8/=10;
    }
    
    return liczba10;
}

void zamien8na2(long long int liczba8)
{
    long long int liczba10 = zamien8na10(liczba8); //zamienie liczbe z 8 do 10
    int liczba2[64];
    int i = 0;
    
    while(liczba10 != 0)
    {
        liczba2[i++] = liczba10 % 2;
        liczba10 /= 2;
    }
    
    for(int j = i - 1; j >= 0; j--)
    {
        printf("%d", liczba2[j]);
    }
}

void zamien8na16(long long liczba8)
{
    long long int liczba10 = zamien8na10(liczba8);
    
    char liczba16[64];
    int reszta;
    int i = 0;
    
    while (liczba10 != 0)
    {
        reszta = liczba10 % 16;
        liczba10 /= 16;
        
        if(reszta < 10)
        {
            liczba16[i++] = reszta + '0';
        }
        else
        {
            switch (reszta)
            {
                case 10:
                    liczba16[i++] = 'A';
                    break;
                    
                case 11:
                    liczba16[i++] = 'B';
                    break;
                    
                case 12:
                    liczba16[i++] = 'C';
                    break;
                    
                case 13:
                    liczba16[i++] = 'D';
                    break;
                    
                case 14:
                    liczba16[i++] = 'E';
                    break;
                    
                case 15:
                    liczba16[i++] = 'F';
                    break;
                    
                default:
                    break;
            }
        }
    }
    
    for(int j = i - 1; j >= 0; j--)
    {
        printf("%c", liczba16[j]);
    }
}
