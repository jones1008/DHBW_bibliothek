#include "helperFunctions.h"

/*
 *  function:
 *      Waits for the user input and writes it to the given variable.
 *  params:
 *      char *userVariable (the variable the user input value is written to)
 */
void getUserInput(char *userVariable)
{
    fgets(userVariable, BUFFERSIZE, stdin);
    if ( strlen(userVariable)>0 && userVariable[strlen(userVariable)-1] == '\n' ){
        userVariable[strlen(userVariable)-1] = '\0';
        trim(userVariable);
    }
}

/*
 *  function:
 *      If there is an input where only one char is allowed, this checks if the user has entered only one char and checks if the char is an allowed char.
 *      Returns 1 if it was wrong, else 0.
 *  params:
 *      char *userInput (where the user input is stored)
 *      char *allowedChars (a char pointer to the allowed chars)
 */
int wrongCharInput(char *userInput, char *allowedChars)
{
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

/*
 *  function:
 *      Checks if the userInput was ENTER and prints Abbrechen...
 *      Returns 1 if it was aborted, else 0.
 *  params:
 *      char *userInput
 */
int isAborted(char *userInput)
{
    if(userInput[0] == '\0'){
        printf("Abbrechen...\n");
        return 1;
    } else{
        return 0;
    }
}

/*
 *  function:
 *      Returns the number of borrowers from the given book.
 *  params:
 *      book *book (pointer to the book)
 */
int getNumberOfBorrowers(book *book)
{
    int numberOfBorrowers;
    if(strlen(book->borrowlist)==0){
        numberOfBorrowers = 0;
    } else{
        int numberOfCommas = countChars(book->borrowlist, ',');
        if(numberOfCommas == 0){
            numberOfBorrowers = 1;
        } else{
            numberOfBorrowers = numberOfCommas+1;
        }
    }
    return numberOfBorrowers;
}

/*
 *  function:
 *      Trims leading and trailing whitespaces from given input.
 *  params:
 *      char *str (pointer to the string)
 */
char *trim(char *str)
{
    size_t len = 0;
    char *frontp = str;
    char *endp = NULL;

    if(str == NULL){
        return NULL;
    }
    if(str[0] == '\0'){
        return str;
    }

    len = strlen(str);
    endp = str + len;

    // Move the front and back pointers to address the first non-whitespace characters from each end.
    while(isspace((unsigned char) *frontp)){
        ++frontp;
    }
    if(endp != frontp){
        while(isspace((unsigned char) *(--endp)) && endp != frontp){}
    }
    if(str + len-1 != endp){
        *(endp + 1) = '\0';
    } else if(frontp != str &&  endp == frontp){
        *str = '\0';
    }

    // Shift the string so that it starts at str
    endp = str;
    if(frontp != str)
    {
        while(*frontp){
            *endp++ = *frontp++;
        }
        *endp = '\0';
    }

    return str;
}

/*
 *  function:
 *      Replaces German umlauts with the corresponding equivalent. E.g.: ä -> ae
 *      Returns the given string with replaced umlauts
 *  params:
 *      char *str (a pointer to the string where the umlauts should be replaced)
 */
char *replaceUmlauts(char *str)
{
    char newString[strlen(str)*2+1];
    strcpy(newString, str);
    int i=0;
    int occ=0;
    while(str[i]){
        unsigned char ch = str[i];
        if(ch==132 || ch==148 || ch==129 || ch==225 || ch==153 || ch==142 || ch==154){
            strncpy(newString, newString, i+occ);
            newString[i+occ] = '\0';
            switch(ch){
                case 132:{
                    char addText[3] = "ae";
                    strcat(newString, addText);
                    break;
                }
                case 148:{
                    char addText[3] = "oe";
                    strcat(newString, addText);
                    break;
                }
                case 129:{
                    char addText[3] = "ue";
                    strcat(newString, addText);
                    break;
                }
                case 225:{
                    char addText[3] = "ss";
                    strcat(newString, addText);
                    break;
                }
                case 153:{
                    char addText[3] = "Oe";
                    strcat(newString, addText);
                    break;
                }
                case 142:{
                    char addText[3] = "Ae";
                    strcat(newString, addText);
                    break;
                }
                case 154:{
                    char addText[3] = "Ue";
                    strcat(newString, addText);
                    break;
                }
            }
            strcat(newString, str+i+1);
            occ++;
        }
        i++;
    }
    strncpy(str, newString, strlen(newString));
    str[strlen(newString)] = '\0';
    return str;
}

/*
 *  function: stringToLower
 *      Turns a string into a complete lowercased string.
 *  params:
 *      char *strPtr (a pointer to the string that should be lowercased)
 */
void stringToLower(char *strPtr)
{
    while(*strPtr != '\0'){
        *strPtr = tolower(*strPtr);
        strPtr++;
    }
}

/*
 *  function:
 *      Recursive function that counts the occurrences of a specific char in a string and returns the count.
 *  params:
 *      char *str (string in which the char should be searched for)
 *      char c (the char that should be counted)
 */
int countChars(char *str, char c)
{
    return (*str == '\0') ? 0 : countChars(str+1, c) + (*str == c);
}

/*
 *  function:
 *      Removes a specific char from a given string
 *  params:
 *      char *str (the string where the char should be removed from)
 *      int c (the char as the corresponding ascii integer value)
 */
void removeChar(char *str, int c)
{
    int j, n = strlen(str);
    for (int i=j=0; i<n; i++){
        if (str[i] != c){
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

/*
 *  function:
 *      Prints a specific amount of '#'
 *  params:
 *
 */
void printHeaderTabs()
{
    for(int i=0; i<HEADERTABSIZE; i++){
        printf("#");
    }
}

/*
 *  function:
 *      Prints the header of a menu with given header-string.
 *  params:
 *      char *header (the name of the header)
 */
void printMenuHeader(char *header)
{
    printHeaderTabs();
    printf(" START: %s ", header);
    printHeaderTabs();
    printf("\n");
}

/*
 *  function:
 *      Prints the end of a menu with the given end-string.
 *  params:
 *      char *end (the name of the end)
 */
void printMenuEnd(char *end)
{
    printHeaderTabs();
    printf(" ende: %s ", end);
    printHeaderTabs();
    printf("\n");
}

/*
 *  function:
 *      Frees a string that was allocated before.
 *  params:
 *      char *var (the variable to be freed)
 */
void freeTempString(char *var)
{
    free(var);
    var = NULL;
}

/*
 *  function: freeFoundBooks
 *      Frees previously allocated memory of a foundBooks structure.
 *  params:
 *      foundBooks *foundBooks (a pointer to the foundBooks structure)
 */
void freeFoundBooks(foundBooks *foundBooks)
{
    // Free all pointers of each array element first
    for(int i=0; i<foundBooks->size; i++)
    {
        free(&foundBooks->books[i]);
        foundBooks->books[i]=NULL;
    }
    // Now free the array
    free(foundBooks->books);
    foundBooks->books = NULL;

    foundBooks->size = 0;
}
