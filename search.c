#include "search.h"
book **search(Array *books, char *searchString)
{
    // initialize an array of pointer
//    book **foundBooks = malloc(sizeof(book *));
    book **foundBooks = malloc(0);
//    book *foundBooks = calloc(sizeof(book *), sizeof(int));
//    printf("malloc of search()\n");
//    printf("sizeof book pointer: %d\n", sizeof(book *));
//    printf("sizeof book pointer: %d\n", sizeof(*foundBooks));
    // iterate over array of books and add pointer to PointerArray "foundBooks" if isbn, author or title matches the given SearchString
    int index = 0;
    for(int i=0; i<books->used; i++)
    {
//        printf("%d\n", i);
        if(strstr(books->array[i].isbn, searchString) != NULL || strstr(books->array[i].author, searchString) != NULL || strstr(books->array[i].title, searchString) != NULL){
//            printf("adding book pointer\n");
//            printf("sizeof foundbooks in loop: %d\n", sizeof(*foundBooks));
//            printf("sizeof book in loop: %d\n", sizeof(book *));
//            foundBooks = (book *) realloc(foundBooks, sizeof(*foundBooks)+sizeof(book *));
            foundBooks = (book *) realloc(foundBooks, (index+1)*sizeof(book *));
            foundBooks[index] = &books->array[i];
            index++;
        }
    }
//    printf("size of foundBooks: %d\n", sizeof(*foundBooks));
    // returns a pointer to the array of pointers
    return foundBooks;
}
