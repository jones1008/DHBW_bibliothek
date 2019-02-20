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
    printf("before loop\n");
    printf("%d", books->used);
    for(int i=0; i<books->used; i++)
    {
        printf("loop\n");
        free(&books->array[i].isbn);
        printf("after first free");
        books->array[i].isbn=NULL;
        printf("after setting NULL");

        printf("%s", books->array[i].title);
        free(&books->array[i].title);
        printf("after second free");
        books->array[i].title=NULL;
//        printf("after setting NULL2");

        free(&books->array[i].author);
        books->array[i].author=NULL;
        printf("after third free");

        free(&books->array[i].numberof);
        books->array[i].numberof=NULL;
        printf("after fourth free");

//        printf("%d\n", &books->array[i].borrowlist[0]);
        free(&books->array[i].borrowlist);
        books->array[i].borrowlist=NULL;
        printf("after fifth free");
    }

    printf("after loop\n");
    // Now free the array
    free(books->array);
    books->array = NULL;

    printf("after freeing\n");

    books->used = 0;
    books->size = 0;
}

int main()
{
    Array books;
    loadBooks(&books);

    book **foundBooks = search(&books, "a");
//    for(int i=0; i<sizeof(*foundBooks)/sizeof(book *); i++){
//        printf("%d:\n", i);
//        printf("author: %s | title: %s\n", foundBooks[i].author, foundBooks[i].title);
//        printf("after printed stuff\n");
//    }
    printf("asafter for");

    // TODO: testen, ob das freeMemoryArray tatsächlich die Daten löscht
//    freeArray(&books);
    return 0;
}
