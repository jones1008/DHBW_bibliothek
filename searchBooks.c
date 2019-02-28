#include "searchBooks.h"
#define BUFFERSIZE 10

void searchBooks(Array *books)
{
    printf("---------Buch suchen---------\n");
    printf("Suchtext eingeben (ISBN, Buchtitel, Buchautor): ");

    char *searchString = calloc(1,1);
    char buffer[BUFFERSIZE];
    while( fgets(buffer, BUFFERSIZE, stdin) != NULL ){
        printf("%s\n", buffer);
    }

//    searchString = realloc( searchString, strlen()+1+strlen(buffer) );
//    sscanf(searchString)
    printf("the input is: %s", buffer);

//    while( fgets(buffer, BUFFERSIZE, stdin) ){
//        text = realloc( text, strlen(text)+1+strlen(buffer) );
////        if( !text ) ... /* error handling */
//        strcat( text, buffer ); /* note a '\n' is appended here everytime */
//        printf("%s\n", buffer);
//    }
//    printf("\ntext:\n%s",text);
}
