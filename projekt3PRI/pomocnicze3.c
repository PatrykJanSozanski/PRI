#include "pomocnicze3.h"

void readTool(char *ch, Licence **this) {
    (*this) -> tool = *ch;
}

void readLicenceNum(char *ch, FILE *dataBase, Licence **this) {
    int i = 0;
    char num[MAX_LIT];
    while (*ch != '#') {
        num[i] = *ch;
        *ch = getc(dataBase);
        i++;
    }
    
    (*this) -> licenceNum = atoi(num);
}

void readStartDate(char *ch, FILE *dataBase, Licence **this) {
    int i = 0;
    char num[MAX_LIT];
    while (*ch != '#') {
        num[i] = *ch;
        *ch = getc(dataBase);
        i++;
    }
    
    (*this) -> dateStart = atoi(num);
}

void readEndDate(char *ch, FILE *dataBase, Licence **this) {
    int i = 0;
    char num[MAX_LIT];
    while (*ch != '#' && *ch != '!') {
        num[i] = *ch;
        *ch = getc(dataBase);
        i++;
    }
    
    (*this) -> dateEnd = atoi(num);
}
