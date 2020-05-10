#include "funkcje.h"
#include "pomocnicze.h"

void help(void){
    puts("\nLISTA DOSTEPNYCH KOMEND:");
    puts("01. exit : KONCZY PRACE PROGRAMU");
    puts("02. clear : CZYSCI OKNO KONSOLI");
    puts("03. load-data : WCZYTUJE REKORDY BAZY DANYCH Z PLIKU");
    puts("04. show-data : WYSWIETLA REKORDY BAZY DANYCH");
    puts("05. add-user : DODAJE NOWY REKORD DO BAZY DANYCG");
    puts("06. rm-user : USUWA REKORD Z BAZY DANYCH");
    puts("07. find-user : WYSZUKUJE UZYTKOWNIKA W BAZIE DANYCH");
    puts("08. count-tool : ZLICZA UZYTKOWNIKOW KORZYSTAJACYCH Z WYBRANEGO NARZEDZIA ORAZ LICZBE AKTYWNYCH LICENCJI");
    puts("09. tool-user : WYSWIETLA LISTE UZYTKOWNIKOW KORZYSTJACYCH Z DANEGO NARZEDZIA");
    puts("10. check-exp : WYSWIETLA LISTE UZYTKOWNIKOW, KTORYM LICENCJA NA KORZYSTANIE Z NARZEDZI WYGASA W TERMINIE DWOCH TYGODNI");
    puts("11. tool-exp : WYSWIETLA LISTE UZYTKOWNIKOW, KTORYM LICENCJA NA KORZYSTANIE Z WYBRANEGO NARZEDZIA WYGASA W TERMINIE DWOCH TYGODNI");
    puts("12. user-exp : WYSWIETLA LISTE NARZEDZI UZYTKOWNIKA, NA KTORE LICENCJA NA KORZYSTANIE WYGASA W TERMINIE DWOCH TYGODNI");
    printf("\n");
}



void clean(void){
    system("clear");
}



void wPattern(void){
    puts("\nBLEDNY FORMAT WPISANEJ KOMENDY!");
    puts("SPROBUJ JESZCZE RAZ LUB WPISZ \"help\", ABY WYSWIETLIC LISTE DOSTEPNYCH KOMEND");
}

void empBuf(void){
    char c;
    
    do
        c = getchar();
    while(c != '\n' && c != EOF);
}

Customer* loadData(FILE* dataBase, Customer* headC){
    if(isEmpty(headC)){
        empBuf();
        dataBase = openFile(dataBase);
        
        if(dataBase){
            headC = readFile(headC, dataBase);
            closeFile(dataBase);
        }
    }
    else{
        puts("\nBLAD! BAZA DANYCH NIE JEST PUSTA");
        puts("NIE MOZNA NADPISAC REKORDOW BAZY DANYCH\n");
    }
    return headC;
}

Customer* clearData(Customer* headC){
    Customer* previous = NULL;
    Customer* current = headC;
    
        while (current != NULL) {
            previous = current;
            clearTools(previous -> headL);
            current = previous -> next;
            free(previous);
        }
    headC = NULL;
    puts("\nBAZA DANYCH ZOSTALA WYCZYSZCZONA\n");
    return headC;
}



void showData(Customer* headC){
    if(isEmpty(headC)){
        puts("\nBAZA DANYCH JEST PUSTA!\n");
    }
    else
    {
        show(headC);
    }
}

void countTool(Customer* headC){
    
    if(isEmpty(headC)){
        puts("\nBAZA DANYCH JEST PUSTA!\n");
    }
    else{
        chooseCount(headC);
    }
}

void toolUser(Customer* headC){
   
    if(isEmpty(headC)){
        puts("\nBAZA DANYCH JEST PUSTA!\n");
    }
    else{
        chooseTool(headC);
    }
}

void checkExp(Customer* headC){
    
    if(isEmpty(headC)){
        puts("\nBAZA DANYCH JEST PUSTA!\n");
    }
    else{
        showExp(headC);
    }
}

void toolExp(Customer* headC){
    
    if(isEmpty(headC)){
        puts("\nBAZA DANYCH JEST PUSTA!\n");
    }
    else{
        chooseToolExp(headC);
    }
}

void userExp(Customer* headC){
    
    if(isEmpty(headC)){
        puts("\nBAZA DANYCH JEST PUSTA!\n");
    }
    else{
        chooseUserExp(headC);
    }
}

void findUser(Customer* headC){
    if(isEmpty(headC)){
        puts("\nBAZA DANYCH JEST PUSTA!\n");
    }
    else{
        find(headC);
    }
}

Customer* addUser(Customer* headC){
    if(isEmpty(headC)){
        headC = add(headC);
    }
    else{
        Customer* last = NULL;
        last = findLast(headC);
        add(last);
    }
    return headC;
}

Customer* rmUser(Customer* headC){
    if(isEmpty(headC)){
        puts("\nBAZA DANYCH JEST PUSTA!\n");
    }
    else{
        headC = rm(headC);
    }
    
    return headC;
}
















