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
#include "helperFunctions.h"

void showMenu(Array *books)
{
    printf("HAUPTMEN%c:\n", UE);

    printf("[S]: B%ccher suchen\n", ue);
    printf("[A]: Buch ausleihen\n");
    printf("[Z]: Buch zur%cckgeben\n", ue);
    printf("[H]: Buch hinzuf%cgen\n", ue);
    printf("[L]: Buch l%cschen\n", oe);
    printf("[C]: Buchexemplar hinzuf%cgen\n", ue);
    printf("[E]: Bibliotheksverwaltung verlassen\n");

//    char *menuPoint = malloc(0);
    char menuPoint[BUFFERSIZE];
    char *allowedChars = "sazhlce";

    // repeat user input if the input was wrong
    // TODO: manchmal spackt user input rum, wenn man beim Suchen rumprobiert
    do{
        // get user input
        printf("Aktion w%chlen: ", ae);
        getUserInput(menuPoint);
        *menuPoint = tolower(*menuPoint);

//        printf("menuPoint: %s\n", menuPoint);
//        printf("menuPointD: %d\n", menuPoint[0]);

        // verify user input and output error messages
//        verifyCharInput(menuPoint, allowedChars);

    } while(wrongCharInput(menuPoint, allowedChars));

    // switch case structure to call the chosen function
    char *menuHeader = "";
    printf("\n");
    switch(menuPoint[0]){
        case 's':
            menuHeader = "BUCH SUCHEN";
            printMenuHeader(menuHeader);
            searchBooks(books);
            break;
        case 'a':
            menuHeader = "BUCH AUSLEIHEN";
            printMenuHeader(menuHeader);
            borrowBook(books);
            break;
        case 'z':
            menuHeader = "BUCH ZURUECKGEBEN";
            printMenuHeader(menuHeader);
            returnBook(books);
            break;
        case 'h':
            menuHeader = "NEUES BUCH HINZUFUEGEN";
            printMenuHeader(menuHeader);
            addBook(books);
            break;
        case 'l':
            menuHeader = "BUCH LOESCHEN";
            printMenuHeader(menuHeader);
            deleteBooks(books);
            break;
        case 'c':
            menuHeader = "BUCHEXEMPLAR HINZUFUEGEN";
            printMenuHeader(menuHeader);
            addCopies(books);
            break;
        case 'e':
            printf("Schlie%ce Bibliothek...\n", ss);
            exit(0);
            break;
        default:
            printf("ERROR: Falsche Eingabe!\n");
            break;
    }

//    freeTempString(menuPoint);

    printMenuEnding(strlen(menuHeader));
    printf("\n");
    // call itself after other functions are completed
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


// TODO: ist dies an der richtigen Stelle? Brauchen wir das nicht woanders? brauchen wir das überhaupt noch?
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
//    system("cls");
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
