#include "helperFunctions.h"

// TODO: umschreiben! darf wirklich nur den UserInput zurückgeben -> die Logik mit der Message und muss außerhalb passieren
//void getUserInput(char *userVariable, const char message[])
//{
//    char buffer[BUFFERSIZE];
//    memset(buffer, 0, BUFFERSIZE);
//    char *buf = buffer;
//
//    // repeat if user doesn't input anything
//    do{
//        // TODO: sobald über 6 Zeichen eingegeben, kommt Müll raus
//        // print message to show before the user input
////        if(buffer[0] == '\0' || buffer[0] == '\n'){
//        if(buffer[0] == '\0'){
//            printf("%s ", message);
//        }
//        fgets(buf, BUFFERSIZE, stdin);
//        printf("bufBefore: %s\n", buf);
////    } while (buffer[0] == '\0' || buffer[0] == '\n');
//    } while (buffer[0] == '\0');
//
//    // increase size of userVariable to size of user input
//    printf("strlen(buf): %d\n", strlen(buf));
//    userVariable = realloc(userVariable, strlen(buf));
////    userVariable = realloc(userVariable, strlen(userVariable)+strlen(buf)+1);
//    // copy the buf into the userVariable without '\n' at the end:
//
//    printf("bufAfter: %s\n", buf);
////    strncpy(userVariable, buf, strlen(buf));
//    strncpy(userVariable, buf, strlen(buf)-1);
//    printf("UserVar: %s\n", userVariable);
//}
void getUserInput(char *userVariable)
{
    char buffer[BUFFERSIZE];
    memset(buffer, 0, BUFFERSIZE);
    char *buf = buffer;

    fgets(buf, BUFFERSIZE, stdin);

    userVariable = realloc(userVariable, strlen(buf));
    strncpy(userVariable, buf, strlen(buf)-1);
}
int isAborted(char *userInput){
    if(userInput[0] == '\0'){
        printf("Abbrechen...\n");
        return 1;
    } else{
        return 0;
    }
}

int isUserInputAborted(char *userVariable, const char message[])
{
    getUserInput(userVariable);
//    getUserInput(userVariable, message);
    if(userVariable[0] == '\n'){
        printf("Abbrechen...\n");
        return 1;
    } else{
        return 0;
    }

}

//void getUserInt(char *userVariable)
//{
//
//}

void printHeaderTabs()
{
    for(int i=0; i<HEADERTABSIZE; i++){
        printf("#");
    }
}

void printMenuHeader(char *header)
{
    printHeaderTabs();
    printf(" %s ", header);
    printHeaderTabs();
    printf("\n");
}

void printMenuEnding(int menuHeaderLength)
{
    printHeaderTabs();
    for(int i=0; i<menuHeaderLength+2; i++){
        printf("#");
    }
    printHeaderTabs();
    printf("\n");
}

void showReturnToMenu()
{
    printf("Zur%cck zum Men%c [ENTER]:", ue, ue);
    char enter = 0;
    while (enter != '\r' && enter != '\n'){
        enter = getchar();
    }
}

void freeTempString(char *var)
{
    free(var);
    var = NULL;
}
