#include "search.h"
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
 *  function: search
 *      searches for books with given searchString and adds them to foundBooksArray
 *  params:
 *      Array *books        (pointer to books structure)
 *      foundBooks *foundBooks      (pointer to array of book pointers)
 *      char *searchString  (pointer to string to search for)
*/
void search(Array *books, foundBooks *foundBooks, char *searchString)
{
    // initialize the array where the book pointers will be stored
    foundBooks->array = malloc(0);

    // make the searchString to lower case, so the comparison is case insensitive
    stringToLower(searchString);

    // replace umlauts of searchstring with corresponding chars (ä=>ae, ü=>ue, ö=>oe, ß=>ss)
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
    // use variable newSearchString from now on

    // iterate over array of books and add pointer to PointerArray "foundBooks" if isbn, author or title matches the given SearchString
    int index = 0;
    for(int i=0; i<books->used; i++)
    {
        // make the author and the title to lower case, so the comparison is case insensitive
        char author[strlen(books->array[i].author)+1];
        char title[strlen(books->array[i].title)+1];
        strcpy(author, books->array[i].author);
        strcpy(title, books->array[i].title);
        stringToLower(author);
        stringToLower(title);

        // check if newSearchString matches any of isbn, author or title of the current book
        if(strstr(books->array[i].isbn, newSearchString) != NULL || strstr(author, newSearchString) != NULL || strstr(title, newSearchString) != NULL){
            // adding the pointer to this book to the foundBooks array
            foundBooks->array = (book *) realloc(foundBooks->array, (index+1)*sizeof(book *));
            foundBooks->array[index] = &books->array[i];
            index++;
        }
    }
    // write the number of found elements to the size attribute of the foundBooks structure
    foundBooks->size = index;
}
