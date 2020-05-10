#include "pomocnicze2.h"
#include "pomocnicze3.h"

void readName(char *ch, Customer *current, FILE *dataBase) {
    int i = 0;
    
    while(*ch != '#'){
        current -> name[i] = *ch;
        *ch = getc(dataBase);
        i++;
    }
}

void readSurname(char *ch, Customer *current, FILE *dataBase) {
    int i = 0;
    
    while (*ch != '#') {
        current -> surname[i] = *ch;
        *ch = getc(dataBase);
        i++;
    }
}

void readTools(char *ch, Customer **current, FILE *dataBase, Customer **previous) {
    if(*ch == '$'){
        Licence *this = NULL;
        Licence *former = NULL;
        
        while (*ch != '!') {
            *ch = getc(dataBase);
            
            this = malloc(sizeof(Licence));
            if(!this){
                exit(-1);
            }
            
            if(former == NULL){
                (*current) -> headL = this;
            }
            else{
                former -> next = this;
            }
            
            readTool(ch, &this);
            *ch = getc(dataBase);
            readLicenceNum(ch, dataBase, &this);
            *ch = getc(dataBase);
            readStartDate(ch, dataBase, &this);
            *ch = getc(dataBase);
            readEndDate(ch, dataBase, &this);
            former = this;
            
        }
        
        *ch = getc(dataBase);
        *ch = getc(dataBase);
        
        *previous = *current;
    }
}

void chChosenCount(Customer* headC, char chs){
    Customer *current = headC;
    Licence *this = NULL;
    time_t date = time(NULL);
    int userNum = 0;
    int licNum = 0;
    
    while (current != NULL) {
        this = current -> headL;
        while (this != NULL) {
            if (this -> tool == chs && (long)date < (long)this -> dateEnd) {
                userNum += 1;
                licNum += this -> licenceNum;
            }
            this = this -> next;
        }
        current = current -> next;
    }
    
    printf("\nZ WYBRANEGO NARZEDZIA KORZYSTA %d UZYTKOWNIKOW", userNum);
    printf("\n%d LICENCJI WYBRANEGO NARZEDZIA JEST W UZYTKU\n\n", licNum);
}

void chChosenTool(Customer* headC, char chs){
    Customer *current = headC;
    Licence *this = NULL;
    time_t date = time(NULL);
    
    puts("\nZ WYBRANEGO NARDZEDZIA KORZYSTAJA:\n");
    
    while (current != NULL) {
        this = current -> headL;
        while (this != NULL) {
            if (this -> tool == chs && (long)date < (long)this -> dateEnd) {
                printf("IMIE: %s\n", current -> name);
                printf("NAZWISKO: %s\n", current -> surname);
                printf("START: %s", ctime(&this -> dateStart));
                printf("KONIEC: %s\n", ctime(&this -> dateEnd));
            }
            this = this -> next;
        }
        current = current -> next;
    }
}

void chChosenExp(Customer* headC, char chs){
    Customer *current = headC;
    Licence *this = NULL;
    time_t date = time(NULL);
    
    puts("\nLICENCJA NA WYBRANE NARZEDZIE WYGASA NASTEPUJACYM UZYTKOWNIKOM:\n");
    
    while (current != NULL) {
        this = current -> headL;
        while (this != NULL) {
            if ((long)date <= (long)this -> dateEnd && (long)this -> dateEnd <= (long)date + TWOWEEKS && this -> tool == chs) {
                printf("IMIE: %s\n", current -> name);
                printf("NAZWISKO: %s\n", current -> surname);
                printf("START: %s", ctime(&this -> dateStart));
                printf("KONIEC: %s\n", ctime(&this -> dateEnd));
            }
            this = this -> next;
        }
        current = current -> next;
    }
}










