#include "search.h"

search(Array *books, char* searchString)
{
    int initialSize = 1;
    book *foundBooks = (book *)calloc(initialSize * sizeof(book), sizeof(int));
    // iterate over array of books and add pointer to PointerArray "foundBooks" if isbn, author or title matches the given SearchString
    for(int i=0; i<books.used; i++)
    {
        if(strstr(searchString, books.array[i].isbn) != NULL || strstr(searchString, books.array[i].author) != NULL || strstr(searchString, books.array[i].title) != NULL){
            foundBooks[i] = (char*)malloc(1);
            book *tmpPointer = &books->array[i];
            foundBooks[i] = tmpPointer;
        }
    }
    return foundBooks;
}
