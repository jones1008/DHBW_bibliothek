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
    char *buf = buffer;

    // reset buffer (and userVariable if previous inputs changed strlen of userVariable)
    memset(buffer, 0, BUFFERSIZE);
    memset(userVariable, 0, strlen(userVariable));

    // get user input
    fgets(buf, BUFFERSIZE, stdin);

    // write users input into given variable without the \n char
    userVariable = realloc(userVariable, strlen(buf));
    strncpy(userVariable, buf, strlen(buf)-1);
}

void verifyCharInput(char *userInput, char *allowedChars)
{
    if(userInput[0] == '\0'){
        printf("ERROR: Gib einen Buchstaben ein!\n");
    } else if(strlen(userInput)>1){
        // check if userInput is longer than one character or not the first loop
        printf("ERROR: Bitte nur einen Buchstaben eingeben!\n");
    } else if(strchr(allowedChars, userInput[0]) == NULL){
        // check if user input is an allowed char
        printf("ERROR: Falsche Eingabe!\n");
    }
}

int isWrongCharInput(char *userInput, char *allowedChars)
{
    if(strlen(userInput)>1 || strchr(allowedChars, userInput[0]) == NULL || userInput[0] == '\0'){
        return 1;
    } else{
        return 0;
    }
}

int isAborted(char *userInput)
{
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
