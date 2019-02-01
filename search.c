#include "search.h"

search(Array *books, char* searchString)
{

    char *foundBooks = (char *)calloc()
    // iterate over array of books and add pointer to PointerArray "foundBooks" if isbn, author or title matches the given SearchString
    for(int i=0; i<books.array.length; i++)
    {
        if(strstr(searchString, books.array[i].isbn) != NULL || strstr(searchString, books.array[i].author) != NULL || strstr(searchString, books.array[i].title) != NULL){
            foundBooks = *books.array[i];
        }
    }
    return foundBooks;
}
