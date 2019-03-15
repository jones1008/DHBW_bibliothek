#include "helperFunctions.h"

/*
 *  function:
 *
 *  params:
 *
 */
void getUserInput(char *userVariable)
{
//    char buffer[BUFFERSIZE];
//    char *buf = buffer;
//
//    // reset buffer (and userVariable if previous inputs changed strlen of userVariable)
//    memset(buffer, 0, BUFFERSIZE);
//    memset(userVariable, 0, strlen(buf));
//
//    // get user input
//    fgets(buf, BUFFERSIZE, stdin);
//    printf("buf: %s\n", buf);
//    printf("bufD: %d\n", strlen(buf));
//    if(buf[strlen(buf)-1] == '\n'){
//        buf[strlen(buf)-1] = '\0';
//    }
//    printf("buf: %s\n", buf);
//    printf("bufD: %d\n", strlen(buf));
//
//    // write users input into given variable without the newline char and add the null terminator to the string if input wasn't ENTER
//    printf("sizeof realloc: %d\n", strlen(buf)*sizeof(char));
//    userVariable = realloc(userVariable, strlen(buf)*sizeof(char));
//    strncpy(userVariable, buf, strlen(buf));
//    // TODO: fix: ENTER zum abbrechen
////    printf("before terminatoring: %s\n", userVariable);
////    userVariable[strlen(buf)-1] = '\0';
////    printf("after terminatoring: %s\n", userVariable);
////    if(buf[0] != '\n'){
//////        printf("nullify");
////        userVariable[strlen(buf)-1] = '\0';
////    }
////    else{
////        userVariable[strlen(buf)] = '\0';
////    }
//
//    printf("userVar: %s\n", userVariable);
////    printf("userVarD: %d\n", userVariable[0]);
////    printf("userVar(len): %d\n", strlen(userVariable));
//    char buffer[BUFFERSIZE];
//    char *buf = buffer;
//
//    // reset buffer (and userVariable if previous inputs changed strlen of userVariable)
//    memset(buffer, 0, BUFFERSIZE);
//    memset(userVariable, 0, strlen(userVariable));
//
//    // get user input
//    fgets(buf, BUFFERSIZE, stdin);
//
//    printf("buf: %s\n", buf);
//    printf("bufD: %d\n", strlen(buf));
//
//    userVariable = realloc(userVariable, sizeof(buf)*sizeof(char));
//    strncpy(userVariable, buf, strlen(buf));
//    // TODO: fix: ENTER zum abbrechen
////    userVariable[strlen(buf)] = '\0';
//    if(buf[0] != '\n'){
////        printf("nullify");
//        userVariable[strlen(buf)-1] = '\0';
//    } else{
//        userVariable[strlen(buf)] = '\0';
//    }
//    printf("userVar: %s\n", userVariable);
//    printf("userVarD: %d\n", userVariable[0]);
//    printf("userVar(len): %d\n", strlen(userVariable));

//    char userVariable[BUFFERSIZE];



//    memset(userVariable, 0, BUFFERSIZE);
    fgets(userVariable, BUFFERSIZE, stdin);
//    printf("userVar: %s\n", userVariable);
    if ( strlen(userVariable)>0 && userVariable[strlen(userVariable)-1] == '\n' ){
//        printf("strlen(userVariable): %d\n", strlen(userVariable));
        userVariable[strlen(userVariable)-1] = '\0';
//        printf("userVar: %s\n", userVariable);
        trim(userVariable);
//        printf("after trim: %s\n", userVariable);
    }
//    printf("after getUserInput\n");
//    printf("userVariableD: %d\n", userVariable[0]);
    printf("userVariable: %s\n", userVariable);



//    return *userVariable;

//    if(line[0] != '\n'){
//        userVariable = realloc(userVariable, sizeof(line)*sizeof(char));
//        int sscanf_result = scanf(line, "%s", userVariable);
//
//        if(sscanf_result == 0 || sscanf_result == EOF){
//            printf("error: wrong input\n");
//        }
//        printf("userinput: %s\n", userVariable);
//    }

}

/*
 *  function:
 *
 *  params:
 *
 */
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

/*
 *  function:
 *
 *  params:
 *
 */
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

//char *trimWhitespace(char *str)
//{
//    char *end;
//    // Trim leading space
//    while(isspace((unsigned char)*str)){
//        str++;
//    }
//    // All spaces
//    if(*str == 0){
//        return str;
//    }
//    // Trim trailing space
//    end = str + strlen(str)-1;
//    while(end > str && isspace((unsigned char)*end)){
//        end--;
//    }
//    // Write new null terminator character
//    end[1] = '\0';
//    return str;
//}

/*
 *  function:
 *
 *  params:
 *
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
//size_t trimWhitespace(char *out, size_t len, const char *str)
//{
//    if(len == 0){
//        return 0;
//    }
//    const char *end;
//    size_t out_size;
//
//    // Trim leading space
//    while(isspace((unsigned char)*str)){
//        str++;
//    }
//    // all spaces?
//    if(*str == 0){
//        *out = 0;
//        return 1;
//    }
//    // Trim trailing space
//    end = str + strlen(str) - 1;
//    while(end > str && isspace((unsigned char)*end)) end--;
//    end++;
//
//    // Set output size to minimum of trimmed string length and buffer size minus 1
//    out_size = (end-str) < len-1 ? (end-str) : len-1;
//
//    // Copy trimmed string and add null terminator
//    memcpy(out, str, out_size);
//    out[out_size] = 0;
//
//    return out_size;
//}

/*
 *  function:
 *
 *  params:
 *
 */
char *replaceUmlauts(char *str)
{
//    printf("urspruenglich: %s\n", str);
    char newString[strlen(str)*2+1];
    strcpy(newString, str);
    int i=0;
    int occ=0;
    while(str[i]){
        unsigned char ch = str[i];
//        printf("char: %d\n", ch);
//        printf("char: %d\n", (unsigned char) str[i]);
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
//    printf("newString after: %s\n", newString);
//    str = realloc(str, sizeof(newString)*sizeof(char));
    strncpy(str, newString, strlen(newString));
    str[strlen(newString)] = '\0';
//    printf("stringAfter: %s\n", str);
    return str;
}

/*
 *  function: stringToLower
 *      turns a string into a complete lowercased string
 *  params:
 *      char *strPtr    (a pointer to the string that should be lowercased)
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
 *
 *  params:
 *
 */
int countChars(char* str, char c)
{
    return (*str == '\0') ? 0 : countChars(str+1, c) + (*str == c);
}

/*
 *  function:
 *
 *  params:
 *
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
 *
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
 *
 *  params:
 *
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
 *
 *  params:
 *
 */
void printMenuEnd(char *end)
{
    printHeaderTabs();
    printf(" ende: %s ", end);
    printHeaderTabs();
    printf("\n");
}

//void printMenuEnding(int menuHeaderLength)
//{
//    printHeaderTabs();
//    for(int i=0; i<menuHeaderLength+2; i++){
//        printf("#");
//    }
//    printHeaderTabs();
//    printf("\n");
//}

/*
 *  function:
 *
 *  params:
 *
 */
void freeTempString(char *var)
{
    free(var);
    var = NULL;
}

/*
 *  function: freeFoundBooks
 *      frees previously allocated memory of a foundBooks structure
 *  params:
 *      foundBooks *foundBooks    (a pointer to the foundBooks structure)
 */
void freeFoundBooks(foundBooks *foundBooks)
{
    // Free all pointers of each array element first
//    printf("free: foundbooks->size: %d\n", foundBooks->size);
    for(int i=0; i<foundBooks->size; i++)
    {
//        printf("free: in loop\n");
        free(&foundBooks->books[i]);
        foundBooks->books[i]=NULL;
//        printf("free: end of loop\n");
    }
    // Now free the array
//    printf("free: before free()\n");
    free(foundBooks->books);
//    printf("before setting NULL\n");
    foundBooks->books = NULL;
//    printf("after NUlling: %p\n", foundBooks->books);

    foundBooks->size = 0;
}
