#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include "addBook.h"
#include "addCopies.h"
#include "borrowBook.h"
#include "deleteBooks.h"
#include "loadBooks.h"
#include "returnBook.h"
#include "search.h"
#include "searchBooks.h"
#include "structure.h"

#define AE (unsigned char)142
#define ae (unsigned char)132
#define OE (unsigned char)153
#define oe (unsigned char)148
#define UE (unsigned char)154
#define ue (unsigned char)129
#define ss (unsigned char)225

void printErrorMessage()
{

}
void exitProgram()
{

}
void showMenu(Array *books)
{
    char menuPoint;
    printf("[S]: B%ccher suchen\n", ue);
    printf("[A]: Buch ausleihen\n");
    printf("[Z]: Buch zur%cckgeben\n", ue);
    printf("[H]: Buch hinzuf%cgen\n", ue);
    printf("[L]: Buch l%cschen\n", oe);
    printf("[E]: Bibliotheksverwaltung verlassen\n");
    printf("Aktion w%chlen: ", ae);
    scanf(" %c", &menuPoint);
    menuPoint = tolower(menuPoint);
    //printf("%c\n", menuPoint);
    printf("\n");
    switch(menuPoint){
        case 's':
            searchBooks(books);
            break;
        case 'a':
            borrowBook(books);
            break;
        case 'z':
            returnBook(books);
            break;
        case 'h':
            addBook(books);
            break;
        case 'l':
            deleteBooks(books);
            break;
        case 'e':
            printf("Schlie%ce Bibliothek...", ss);
            exit(0);
            break;
        default:
            printf("Falsche Eingabe!\n");
            break;
    }
    printf("\n");
    showMenu(books);
}
void showHeading()
{
    printf(" _______  ___   _______  ___      ___   _______  _______  __   __  _______  ___   _ \n|  _    ||   | |  _    ||   |    |   | |       ||       ||  | |  ||       ||   | | |\n| |_|   ||   | | |_|   ||   |    |   | |   _   ||_     _||  |_|  ||    ___||   |_| |\n|       ||   | |       ||   |    |   | |  | |  |  |   |  |       ||   |___ |      _|\n|  _   | |   | |  _   | |   |___ |   | |  |_|  |  |   |  |       ||    ___||     |_ \n| |_|   ||   | | |_|   ||       ||   | |       |  |   |  |   _   ||   |___ |    _  |\n|_______||___| |_______||_______||___| |_______|  |___|  |__| |__||_______||___| |_|\n\n");
}

void freeArray(Array *books)
{
    // Free all name variables of each array element first
    for(int i=0; i<books->used; i++)
    {
        free(books->array[i].isbn);
        books->array[i].isbn=NULL;
        free(books->array[i].title);
        books->array[i].title=NULL;
        free(books->array[i].author);
        books->array[i].author=NULL;
        free(books->array[i].numberof);
        books->array[i].numberof=NULL;
        free(books->array[i].borrowlist);
        books->array[i].borrowlist=NULL;
    }

    // Now free the array
    free(books->array);
    books->array = NULL;

    books->used = 0;
    books->size = 0;
}
void freeMemoryArray(Array *books){
    for(int i=0; i<books->size-1; i++){
        free(&books->array[i]);
    }
    free(books);
}

int main()
{
    Array books;
    loadBooks(&books);
// how to access the books
//    for(int i=0; i<books.used; i++){
//        printf("%s\n", books.array[i].isbn);
//        printf("%s\n", books.array[i].title);
//        printf("%s\n", books.array[i].author);
//        printf("%s\n", books.array[i].numberof);
//        printf("%s\n", books.array[i].borrowlist);
//        printf("\n");
//    }

    book *foundBooks = search(&books, "a");
//    printf("got books");
//    printf("%d\n", sizeof(foundBooks));
//    printf("%d\n", sizeof(book *));
    for(int i=0; i<sizeof(*foundBooks)/sizeof(book *); i++){
        printf("%d:\n", i);
        printf("author: %s | title: %s\n", foundBooks[i].author, foundBooks[i].title);
        printf("after printed stuff\n");
    }
    freeMemoryArray(&books);
    printf(books.array[0].author);
    return 0;
}
