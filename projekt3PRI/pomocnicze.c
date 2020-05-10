#include "pomocnicze.h"
#include "pomocnicze2.h"



FILE* openFile(FILE* dataBase){
    char fileName[MAX_LIT];
    
    printf("\nWPISZ NAZWE PLIKU, Z KTOREGO CHCESZ WCZYTYWAC DANE:\n#nazwa pliku -> ");
    scanf("%s", fileName);
    
    if (!(dataBase=fopen(fileName, "r"))){
        printf("\nBLAD! PLIK %s NIE ISTNIEJE LUB NIE MOZE ZOSTAC OTWARTY\n\n", fileName);
        return NULL;
    }
    else{
        puts("\nPLIK ZOSTAŁ POMYSLNIE WCZYTANY\n");
    }
    
    return dataBase;
}



void closeFile(FILE* dataBase){
    if(fclose(dataBase) != 0){
        puts("BLAD! PLIK %s NIE MOZE ZOSTAC ZAMKNIETY\n");
    }
}



bool isEmpty(Customer* headC){
    if(headC != NULL){
        return false;
    }
    else{
        return true;
    }
}

Customer* readFile(Customer* headC, FILE* dataBase){
    Customer *current = NULL;
    Customer *previous = NULL;
    char ch = getc(dataBase);
    
    while (ch != '\n' && ch != EOF) {
        current = malloc(sizeof(Customer));
        if(!current){
            exit(-1);
        }
        if(headC == NULL){
            headC = current;
        }
        else{
            previous -> next = current;
        }
        readName(&ch, current, dataBase);
        ch = getc(dataBase);
        readSurname(&ch, current, dataBase);
        ch = getc(dataBase);
        readTools(&ch, &current, dataBase, &previous);
    }
    return headC;
}

void show(Customer* headC){
    
    Customer *current = headC;
    Licence *this = NULL;
    printf("\n");
    
    while (current != NULL) {
        
        this = current -> headL;
        
        printf("IMIE: %s\n", current -> name);
        printf("NAZWISKO: %s\n\n", current -> surname);
        
        while (this != NULL) {
            
            printf("NARZEDZIE: ");
            
            switch ((char)this -> tool){
                case ('A'):
                    printf("Architecture Toolset\n");
                    break;
                case ('E'):
                    printf("Electrical Toolset\n");
                    break;
                case ('C'):
                    printf("Mechanical Toolset\n");
                    break;
                case ('M'):
                    printf("Map 3D Toolset\n");
                    break;
                case ('P'):
                    printf("Plant 3D Toolset\n");
                    break;
                default:
                    printf("none\n");
                    break;
            }
            printf("LICZBA LICENCJI: %d\n", this -> licenceNum);
            
            printf("START: %s", ctime(&this -> dateStart));
            printf("KONIEC: %s\n", ctime(&this -> dateEnd));
            this = this -> next;
        }
        
        printf("\n");
        current = current -> next;
    }
}

void clearTools(Licence* headL){
    Licence* previous = NULL;
    Licence* current = headL;
    
    if(current -> next != NULL){
        current = current -> next;
        
        do{
            previous = current;
            current = previous -> next;
            free(previous);
        }while (current != NULL);
    }
}

void chooseCount(Customer* headC){
    puts("\nWYBIERZ SPOSROD PONIZSZYCH NARZEDZIE, JAKIE CHCESZ ODSZUKAC I ZATWIERDZ WYBOR KLAWISZEM ENTER\n");
    puts("A - ARCHITECTURE TOOLSET");
    puts("E - ELECTRICAL TOOLSET");
    puts("C - MECHANICAL TOOLSET");
    puts("M - MAP 3D TOOLSET");
    puts("P - PLANT 3D TOOLSET");
    printf("#wybor -> ");
    
    char chs;
    getchar();
    chs = getchar();
    
    switch (chs){
        case 'A':
            chChosenCount(headC, chs);
            break;
        case 'E':
            chChosenCount(headC, chs);
            break;
        case 'C':
            chChosenCount(headC, chs);
            break;
        case 'M':
            chChosenCount(headC, chs);
            break;
        case 'P':
            chChosenCount(headC, chs);
            break;
        default:
            puts("\nNIE MA TAKIEGO NARZEDZIA\n");
            break;
    }
}

void chooseTool(Customer* headC){
    puts("\nWYBIERZ SPOSROD PONIZSZYCH NARZEDZIE, KTOREGO LISTE UZYTKOWNIKOW CHCESZ WYSWIETLIC I ZATWIERDZ WYBOR KLAWISZEM ENTER\n");
    puts("A - ARCHITECTURE TOOLSET");
    puts("E - ELECTRICAL TOOLSET");
    puts("C - MECHANICAL TOOLSET");
    puts("M - MAP 3D TOOLSET");
    puts("P - PLANT 3D TOOLSET");
    printf("#wybor -> ");
    
    char chs;
    getchar();
    chs = getchar();
    
    switch (chs){
        case 'A':
            chChosenTool(headC, chs);
            break;
        case 'E':
            chChosenTool(headC, chs);
            break;
        case 'C':
            chChosenTool(headC, chs);
            break;
        case 'M':
            chChosenTool(headC, chs);
            break;
        case 'P':
            chChosenTool(headC, chs);
            break;
        default:
            puts("\nNIE MA TAKIEGO NARZEDZIA\n");
            break;
    }
}

void showExp(Customer* headC){
    Customer *current = headC;
    Licence *this = NULL;
    time_t date = time(NULL);
    
    puts("\nLICENCJA WYGASA NASTEPUJACYM UZYTKOWNIKOM:\n");
    
    while (current != NULL) {
        this = current -> headL;
        while (this != NULL) {
            if ((long)date <= (long)this -> dateEnd && (long)this -> dateEnd <= (long)date + TWOWEEKS) {
                printf("IMIE: %s\n", current -> name);
                printf("NAZWISKO: %s\n", current -> surname);
                printf("NARZEDZIE: ");
                switch ((char)this -> tool) {
                    case ('A'):
                        printf("Architecture Toolset\n");
                        break;
                    case ('E'):
                        printf("Electrical Toolset\n");
                        break;
                    case ('C'):
                        printf("Mechanical Toolset\n");
                        break;
                    case ('M'):
                        printf("Map 3D Toolset\n");
                        break;
                    case ('P'):
                        printf("Plant 3D Toolset\n");
                        break;
                    default:
                        printf("none\n");
                        break;
                }
                printf("START: %s", ctime(&this -> dateStart));
                printf("KONIEC: %s\n", ctime(&this -> dateEnd));
            }
            this = this -> next;
        }
        current = current -> next;
    }
}

void chooseToolExp(Customer* headC){
    puts("\nWYBIERZ SPOSROD PONIZSZYCH NARZEDZIE, DLA KTOREGO CHCESZ WYSIETLIC LISTE WYGASAJACYCH LICENCJI\n");
    puts("A - ARCHITECTURE TOOLSET");
    puts("E - ELECTRICAL TOOLSET");
    puts("C - MECHANICAL TOOLSET");
    puts("M - MAP 3D TOOLSET");
    puts("P - PLANT 3D TOOLSET");
    printf("#wybor -> ");
    
    char chs;
    getchar();
    chs = getchar();
    
    switch (chs){
        case 'A':
            chChosenExp(headC, chs);
            break;
        case 'E':
            chChosenExp(headC, chs);
            break;
        case 'C':
            chChosenExp(headC, chs);
            break;
        case 'M':
            chChosenExp(headC, chs);
            break;
        case 'P':
            chChosenExp(headC, chs);
            break;
        default:
            puts("\nNIE MA TAKIEGO NARZEDZIA\n");
            break;
    }
}

void chooseUserExp(Customer* headC){
    Customer *current = headC;
    Licence *this = NULL;
    time_t date = time(NULL);
    char fName[MAX_LIT + 1];
    char fSurname[MAX_LIT +1];
    int i = 0;
    int j = 0;
    
    printf("\nWPISZ IMIE UZYTKOWNIKA, KTOREGO CHCESZ ODSZUKAC\n#imie ->");
    scanf("%s", fName);
    empBuf();
    printf("\nWPISZ NAZWISKO UZYTKOWNIKA, KTOREGO CHCESZ ODSZUKAC\n#nazwisko ->");
    scanf("%s", fSurname);
    
    printf("\nWYGASAJACE NARZEDZIA UZYTKOWNIKA %s %s:\n\n", fName, fSurname);
    
    while (current != NULL) {
        this = current -> headL;
        while (this != NULL) {
            
            if(strcmp(fName, current -> name) == 0 && strcmp(fSurname, current -> surname) == 0){
                ++i;
            }
            
            if(strcmp(fName, current -> name) == 0 && strcmp(fSurname, current -> surname) == 0 && (long)date <= (long)this -> dateEnd && (long)this -> dateEnd <= (long)date + TWOWEEKS) {
                ++j;
                printf("NARZEDZIE: ");
                switch ((char)this -> tool) {
                    case ('A'):
                        printf("Architecture Toolset\n");
                        break;
                    case ('E'):
                        printf("Electrical Toolset\n");
                        break;
                    case ('C'):
                        printf("Mechanical Toolset\n");
                        break;
                    case ('M'):
                        printf("Map 3D Toolset\n");
                        break;
                    case ('P'):
                        printf("Plant 3D Toolset\n");
                        break;
                    default:
                        printf("none\n");
                        break;
                }
                printf("START: %s", ctime(&this -> dateStart));
                printf("KONIEC: %s\n", ctime(&this -> dateEnd));
            }
            this = this -> next;
        }
        current = current -> next;
    }
    
    if(i == 0){
        printf("UZYTKOWNIK %s %s NIE WIDNIEJE W BAZIE DANYCH\n\n", fName, fSurname);
    }
    
    if(j == 0) {
        printf("BRAK\n\n");
    }
    
}

void find(Customer* headC){
    Customer *current = headC;
    Licence *this = NULL;
    char fName[MAX_LIT + 1];
    char fSurname[MAX_LIT +1];
    int i = 0;
    
    printf("\nWPISZ IMIE UZYTKOWNIKA, KTOREGO CHCESZ ODSZUKAC\n#imie -> ");
    scanf("%s", fName);
    empBuf();
    printf("\nWPISZ NAZWISKO UZYTKOWNIKA, KTOREGO CHCESZ ODSZUKAC\n#nazwisko -> ");
    scanf("%s", fSurname);
    
    printf("\nNARZEDZIA UZYTKOWNIKA %s %s:\n\n", fName, fSurname);
    
    while (current != NULL) {
        this = current -> headL;
        while (this != NULL) {
            if (strcmp(fName, current -> name) == 0 && strcmp(fSurname, current -> surname) == 0) {
                ++i;
                printf("NARZEDZIE: ");
                switch ((char)this -> tool) {
                    case ('A'):
                        printf("Architecture Toolset\n");
                        break;
                    case ('E'):
                        printf("Electrical Toolset\n");
                        break;
                    case ('C'):
                        printf("Mechanical Toolset\n");
                        break;
                    case ('M'):
                        printf("Map 3D Toolset\n");
                        break;
                    case ('P'):
                        printf("Plant 3D Toolset\n");
                        break;
                    default:
                        printf("none\n");
                        break;
                }
                printf("START: %s", ctime(&this -> dateStart));
                printf("KONIEC: %s\n", ctime(&this -> dateEnd));
            }
            this = this -> next;
        }
        current = current -> next;
    }
    
    if(i == 0){
        printf("UZYTKOWNIK %s %s NIE WIDNIEJE W BAZIE DANYCH\n\n", fName, fSurname);
    }
}

Customer* add(Customer* last){
    time_t date = time(NULL);
    Customer* newC = NULL;
    Licence* newL = NULL;
    
    newC = malloc(sizeof(Customer));
    if(!newC){
        exit(-1);
    }
    
    newL = malloc(sizeof(Licence));
    if(!newL) {
        exit(-1);
    }
    
    newC -> headL = newL;
    
    if(last == NULL){
        last = newC;
    }
    else{
        last -> next = newC;
    }
    
    printf("\nWPISZ IMIE UZYTKOWNIKA, KTOREGO CHCESZ DODAC\n#imie -> ");
    scanf("%s", newC -> name);
    empBuf();
    printf("\nWPISZ NAZWISKO UZYTKOWNIKA, KTOREGO CHCESZ DODAC\n#nazwisko -> ");
    scanf("%s", newC -> surname);
    empBuf();
    
    puts("\nWYBIERZ SPOSROD PONIZSZYCH NARZEDZIE, KTORE CHCESZ PRZYPISAC DO UZYTKOWNIKA\n");
    puts("A - ARCHITECTURE TOOLSET");
    puts("E - ELECTRICAL TOOLSET");
    puts("C - MECHANICAL TOOLSET");
    puts("M - MAP 3D TOOLSET");
    puts("P - PLANT 3D TOOLSET");
    printf("#wybor -> ");
    
    char chs;
    
    int i = 0;
    while(i == 0){
        
        chs = getc(stdin);
        
        switch (chs){
            case 'A':
                newL -> tool = chs;
                ++i;
                break;
            case 'E':
                newL -> tool = chs;
                ++i;
                break;
            case 'C':
                newL -> tool = chs;
                ++i;
                break;
            case 'M':
                newL -> tool = chs;
                ++i;
                break;
            case 'P':
                newL -> tool = chs;
                ++i;
                break;
            default:
                puts("\nNIE MA TAKIEGO NARZEDZIA");
                puts("\nWYBIERZ PONOWNIE:\n");
                puts("A - ARCHITECTURE TOOLSET");
                puts("E - ELECTRICAL TOOLSET");
                puts("C - MECHANICAL TOOLSET");
                puts("M - MAP 3D TOOLSET");
                puts("P - PLANT 3D TOOLSET");
                printf("#wybor -> ");
                break;
        }
    }
    
    printf("\nWPISZ LICZBE LICENCJI, JAKA CHCESZ PRZYZNAC UZYTKOWNIKOWI\n#nazwisko -> ");
    scanf("%ud", &(newL -> licenceNum));
    
    newL -> dateStart = (long)date;
    newL -> dateEnd = (long)date + YEAR;
    
    printf("\nREKORD ZOSTAL UTWORZONY\n\n");
    
    return last;
}

Customer* findLast(Customer* headC){
    
    Customer* current = NULL;
    
    current = headC;
    while(current->next != NULL){
        current = current->next;
    }
    
    return current;
}

Customer* rm(Customer* headC){
    Customer *current = headC;
    Customer *tmp = headC;
    Licence *this = NULL;
    Licence *previous = NULL;
    char fName[MAX_LIT + 1];
    char fSurname[MAX_LIT +1];
    int i = 0;
    
    printf("\nWPISZ IMIE UZYTKOWNIKA, KTOREGO CHCESZ USUNAC\n#imie -> ");
    scanf("%s", fName);
    empBuf();
    printf("\nWPISZ NAZWISKO UZYTKOWNIKA, KTOREGO CHCESZ USUNAC\n#nazwisko -> ");
    scanf("%s", fSurname);
    
    if(strcmp(fName, headC -> name) == 0 && strcmp(fSurname, headC -> surname) == 0){
        
        this = headC -> headL;
        
     
            while (this != NULL) {
                previous = this;
                free(previous);
                this = this -> next;

        }
        
        current = headC;
        headC = headC -> next;
        
        
            free(current);
        
        
        ++i;
    }
    
    while (current != NULL) {
        if(strcmp(fName, current -> name) == 0 && strcmp(fSurname, current -> surname) == 0) {
            this = current -> headL;
            while (this != NULL) {
                previous = this;
                this = this -> next;
                free(previous);
            }
            
            if(current -> next == NULL){
                tmp -> next = NULL;
                free(current);
            }
            else{
                tmp -> next = current -> next;
                free(current);
            }
            ++i;
        }
        tmp = current;
        current = current -> next;
    }
    
    if(i == 0){
        printf("\nUZYTKOWNIK %s %s NIE WIDNIEJE W BAZIE DANYCH\n\n", fName, fSurname);
    }
    else{
        printf("\nUZYTKOWNIK %s %s ZOSTAL USUNIETY Z BAZY DANYCH\n\n", fName, fSurname);
    }
    
    return headC;
}



