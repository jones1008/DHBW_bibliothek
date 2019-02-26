#include "search.h"
void stringToLower(char *strPtr)
{
    while(*strPtr != '\0'){
        *strPtr = tolower(*strPtr);
        strPtr++;
    }
}
book **search(Array *books, char *searchString)
{
    // TODO: umlaute in der Suche ersetzen mit ue, oe, ae, ss etc.
    // TODO: handling, wenn nichts gefunden wurde

    // initialize an array of pointer
//    book **foundBooks = malloc(sizeof(book *));
    book **foundBooks = malloc(0);
//    book *foundBooks = calloc(sizeof(book *), sizeof(int));
//    printf("malloc of search()\n");
//    printf("sizeof book pointer: %d\n", sizeof(book *));
//    printf("sizeof book pointer: %d\n", sizeof(*foundBooks));
    // iterate over array of books and add pointer to PointerArray "foundBooks" if isbn, author or title matches the given SearchString

    // make the searchString to lower case, so the comparison is case insensitive
    stringToLower(searchString);

    // replace Umlaute with corresponding chars
    char newSearchString[strlen(searchString)*2+1];
    strcpy(newSearchString, searchString);
    int i=0;
    int occ=0;
    while(searchString[i]){
        if(searchString[i]=='ä' || searchString[i]=='ö' || searchString[i]=='ü' || searchString[i]=='ß' ){
            strncpy(newSearchString, newSearchString, i+occ);
            newSearchString[i+occ] = '\0';
            switch(searchString[i]){
                case 'ä':{
                    char addText[3] = "ae";
                    strcat(newSearchString, addText);
                    break;
                }
                case 'ö':{
                    char addText[3] = "oe";
                    strcat(newSearchString, addText);
                    break;
                }
                case 'ü':{
                    char addText[3] = "ue";
                    strcat(newSearchString, addText);
                    break;
                }
                case 'ß':{
                    char addText[3] = "ss";
                    strcat(newSearchString, addText);
                    break;
                }
            }
            strcat(newSearchString, searchString+i+1);
            occ++;
        }
        i++;
    }

    int index = 0;
    for(int i=0; i<books->used; i++)
    {
        // make the author and the title to lower case, so the comparison is case insensitive
        char *author = books->array[i].author;
        stringToLower(author);
        char *title = books->array[i].title;
        stringToLower(title);
        if(strstr(books->array[i].isbn, newSearchString) != NULL || strstr(author, newSearchString) != NULL || strstr(title, newSearchString) != NULL){
//        if(strstr(books->array[i].isbn, newSearchString) != NULL || strstr(books->array[i].author, newSearchString) != NULL || strstr(books->array[i].title, newSearchString) != NULL){
//            printf("adding book pointer\n");
//            printf("sizeof foundbooks in loop: %d\n", sizeof(*foundBooks));
//            printf("sizeof book in loop: %d\n", sizeof(book *));
//            foundBooks = (book *) realloc(foundBooks, sizeof(*foundBooks)+sizeof(book *));
            foundBooks = (book *) realloc(foundBooks, (index+1)*sizeof(book *));
            foundBooks[index] = &books->array[i];
            index++;
        }
    }
    printf("Ergebnisse: %d", index);

//    printf("size of foundBooks: %d\n", sizeof(*foundBooks));
    // returns a pointer to the array of pointers
    return foundBooks;
}
