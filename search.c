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
    // TODO: if searched with isbn-13: 978-3-86680-192-9 strip out the hyphen
    // initialize the array where the book pointers will be stored
    foundBooks->array = malloc(0);

    // replace umlauts of searchstring with corresponding chars (ä=>-124, ü=>-127, ö=>-108, ß=>-31)
    searchString = replaceUmlauts(searchString);

    // make the searchString to lower case, so the comparison is case insensitive
    stringToLower(searchString);

    // iterate over array of books and add pointer to PointerArray "foundBooks" if isbn, author or title matches the given SearchString
    int index = 0;
    for(int i=0; i<books->used; i++){
        // make the author and the title to lower case, so the comparison is case insensitive
        char author[strlen(books->array[i].author)+1];
        char title[strlen(books->array[i].title)+1];
        strcpy(author, books->array[i].author);
        strcpy(title, books->array[i].title);
        stringToLower(author);
        stringToLower(title);

        // check if searchString matches any of isbn, author or title of the current book
        if(strstr(books->array[i].isbn, searchString) != NULL || strstr(author, searchString) != NULL || strstr(title, searchString) != NULL){
            // adding the pointer to this book to the foundBooks array
            foundBooks->array = (book *) realloc(foundBooks->array, (index+1)*sizeof(book *));
            foundBooks->array[index] = &books->array[i];
            index++;
        }
    }
    // write the number of found elements to the size attribute of the foundBooks structure
    foundBooks->size = index;

    // TODO: Output, when keine Ergebnisse gefunden wurden -> dementsprechend bei searchBooks() die Fehlermeldung rausnehmen
}
