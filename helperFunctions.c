#include "helperFunctions.h"

void getUserInput(char *userVariable)
{
    char buffer[BUFFERSIZE];
    char *buf = buffer;

    // reset buffer (and userVariable if previous inputs changed strlen of userVariable)
    memset(buffer, 0, BUFFERSIZE);
    memset(userVariable, 0, strlen(userVariable));

    // get user input
    fgets(buf, BUFFERSIZE, stdin);
//    printf("buf: %s\n", buf);
//    printf("bufD: %d\n", strlen(buf));

    // write users input into given variable without the newline char and add the null terminator to the string if input wasn't ENTER
    userVariable = realloc(userVariable, sizeof(buf)*sizeof(char));
    strncpy(userVariable, buf, strlen(buf));
//    userVariable[strlen(buf)] = '\0';
    if(buf[0] != '\n'){
        userVariable[strlen(buf)-1] = '\0';
    }

//    printf("userVar: %s\n", userVariable);
//    printf("userVarD: %d\n", userVariable[0]);
//    printf("userVar(len): %d\n", strlen(userVariable));
}

int wrongCharInput(char *userInput, char *allowedChars)
{
//    printf("verifyUI: %s\n", userInput);
//    printf("verifyUId: %d\n", userInput[0]);
//    printf("verifyLength: %d\n", strlen(userInput));

    if(userInput[0] == '\0'){
        printf("ERROR: Gib einen Buchstaben ein!\n");
        return 1;
    } else if(strlen(userInput)>1){
        // check if userInput is longer than one character or not the first loop
        printf("ERROR: Bitte nur einen Buchstaben eingeben!\n");
        return 1;
    } else if(strchr(allowedChars, userInput[0]) == NULL){
        // check if user input is an allowed char
        printf("ERROR: Falsche Eingabe!\n");
        return 1;
    } else{
        return 0;
    }
}

int isAborted(char *userInput)
{
//    printf("abortUI: %s\n", userInput);
//    printf("abortUId: %d\n", userInput[0]);
    if(userInput[0] == '\0'){
        printf("Abbrechen...\n");
        return 1;
    } else{
        return 0;
    }
}

char *trimwhitespace(char *str)
{
  char *end;

  // Trim leading space
  while(isspace((unsigned char)*str)) str++;

  if(*str == 0)  // All spaces?
    return str;

  // Trim trailing space
  end = str + strlen(str) - 1;
  while(end > str && isspace((unsigned char)*end)) end--;

  // Write new null terminator character
  end[1] = '\0';

  return str;
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
