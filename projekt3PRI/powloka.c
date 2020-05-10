#include "powloka.h"
#include "funkcje.h"

#include <string.h>


void shell(char* command){
    
    FILE* dataBase = NULL;
    Customer* headC = NULL;
    
    while (strcmp(command, "exit") != 0){
        
        printf("#wpisz polecenie -> ");
        scanf("%s", command);
        
        if(strcmp(command, "help") == 0){
            help();
        }
        else if(strcmp(command,"clear") == 0){
            clean();
        }
        else if(strcmp(command,"load-data") == 0){
            headC = loadData(dataBase, headC);//wsk do listy utworzonej z pliku
        }
        else if(strcmp(command,"clear-data") == 0){
            headC = clearData(headC);
        }
        else if(strcmp(command,"show-data") == 0){
            showData(headC);
        }
        else if(strcmp(command,"count-tool") == 0){
            countTool(headC);
        }
        else if(strcmp(command,"tool-user") == 0){
            toolUser(headC);
        }
        else if(strcmp(command,"check-exp") == 0){
            checkExp(headC);
        }
        else if(strcmp(command,"tool-exp") == 0){
            toolExp(headC);
        }
        else if(strcmp(command,"user-exp") == 0){
            userExp(headC);
        }
        else if(strcmp(command,"find-user") == 0){
            findUser(headC);
        }
        else if(strcmp(command,"add-user") == 0){
            headC = addUser(headC);
        }
        else if(strcmp(command,"rm-user") == 0){
            headC = rmUser(headC);
        }
        else{
            if(strcmp(command, "exit") != 0){
                wPattern();
            }
        }
        empBuf();
    }
    clearData(headC);
}
