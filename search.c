#include "search.h"
book *search(Array *books, char *searchString)
{
    // initialize an array of pointer
    book *foundBooks = malloc(sizeof(book *));
    // iterate over array of books and add pointer to PointerArray "foundBooks" if isbn, author or title matches the given SearchString
    int index = 0;
    for(int i=0; i<books->used; i++)
    {
        if(strstr(books->array[i].isbn, searchString) != NULL || strstr(books->array[i].author, searchString) != NULL || strstr(books->array[i].title, searchString) != NULL){
            foundBooks = (book *) realloc(foundBooks, sizeof(foundBooks)*sizeof(book *));
            foundBooks[index] = books->array[i];
            index++;
        }
    }
    return foundBooks;
}
