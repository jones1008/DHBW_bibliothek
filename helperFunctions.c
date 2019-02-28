#include "helperFunctions.h"

void getUserInput(char *userVariable, const char message[])
{
    char buffer[BUFFERSIZE];
    char *buf = buffer;

    // repeat if user doesn't input anything
    do{
        // print message to show before the user input
        if(buffer[0] == '\n'){
            printf("%s ", message);
        }
        fgets(buf, BUFFERSIZE, stdin);
    } while (buffer[0] == '\n');

    // increase size of userVariable to size of user input
    userVariable = realloc(userVariable, strlen(userVariable)+strlen(buf)+1);
    // copy the buf into the userVariable without '\n' at the end:
    strncpy(userVariable, buf, strlen(buf)-1);
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
