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
#include "saveBooks.h"
#include "structure.h"

//TODO: rausschmeiﬂen, falls das nicht mehr gebraucht wird


void printErrorMessage()
{

}
void exitProgram()
{

}
void showMenu(Array *books)
{
    char menuPoint;
    printf("\n");
    printf("[S]: B%ccher suchen\n", ue);
    printf("[A]: Buch ausleihen\n");
    printf("[Z]: Buch zur%cckgeben\n", ue);
    printf("[H]: Buch hinzuf%cgen\n", ue);
    printf("[L]: Buch l%cschen\n", oe);
    printf("[C]: Buchexemplar hinzuf%cgen\n", oe);
    printf("[E]: Bibliotheksverwaltung verlassen\n");
    printf("Aktion w%chlen: ", ae);
    // TODO: zu getUserInput ‰ndern (nicht scanf verwenden!)
    scanf(" %c", &menuPoint);
    menuPoint = tolower(menuPoint);
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
        case 'c':
            addCopies(books);
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

/*
 *  function: freeBooks
 *      frees previously allocated memory of a books structure
 *  params:
 *      Array *books    (a pointer to the books structure)
 */
void freeBooks(Array *books)
{
    // Free all name variables of each array element first
    for(int i=0; i<books->used; i++)
    {
        free(&books->array[i].isbn);
        books->array[i].isbn=NULL;

        free(&books->array[i].title);
        books->array[i].title=NULL;

        free(&books->array[i].author);
        books->array[i].author=NULL;

        free(&books->array[i].numberof);
        books->array[i].numberof=NULL;

        free(&books->array[i].borrowlist);
        books->array[i].borrowlist=NULL;
    }
    // Now free the array
    free(books->array);
    books->array = NULL;

    books->used = 0;
    books->size = 0;
}

/*
 *  function: freeFoundBooks
 *      frees previously allocated memory of a foundBooks structure
 *  params:
 *      foundBooks *foundBooks    (a pointer to the foundBooks structure)
 */
void freeFoundBooks(foundBooks *foundBooks){
    // Free all pointers of each array element first
    for(int i=0; i<foundBooks->size-1; i++)
    {
        free(&foundBooks->array[i]);
        foundBooks->array[i]=NULL;
    }
    // Now free the array
    free(foundBooks->array);
    foundBooks->array = NULL;

    foundBooks->size = 0;
}

int main()
{
    // initially loading the books from the data-text file
    Array books;
    loadBooks(&books);

    showHeading();
    showMenu(&books);

//    books.array[0].author = "neu";
//    saveBooks(&books);

    // searching for books and printing the author and the title of the found ones
//    char string[] = "e";
//    char *searchString = string;
//    foundBooks foundBooks;
//    search(&books, &foundBooks, searchString);
//    for(int i=0; i<foundBooks.size; i++){
//        printf("author: %s | title: %s\n", foundBooks.array[i]->author, foundBooks.array[i]->title);
//    }

    // free all previously allocated memory
    freeBooks(&books);
//    freeFoundBooks(&foundBooks);

    return 0;
}
