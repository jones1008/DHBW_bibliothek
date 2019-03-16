#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include "addBook.h"
#include "borrowBook.h"
#include "deleteBooks.h"
#include "loadBooks.h"
#include "returnBook.h"
#include "search.h"
#include "searchBooks.h"
#include "saveBooks.h"
#include "showAll.h"
#include "structure.h"
#include "helperFunctions.h"

/*
 *  function: freeBooks
 *      frees previously allocated memory of a books structure
 *  params:
 *      Bib *books    (a pointer to the books structure)
 */
void freeBooks(Bib *bib)
{
    // Free all name variables of each array element first
    for(int i=0; i<bib->used; i++)
    {
        free(&bib->books[i].isbn);
        bib->books[i].isbn=NULL;

        free(&bib->books[i].title);
        bib->books[i].title=NULL;

        free(&bib->books[i].author);
        bib->books[i].author=NULL;

        free(&bib->books[i].numberof);
        bib->books[i].numberof=NULL;

        free(&bib->books[i].borrowlist);
        bib->books[i].borrowlist=NULL;
    }
    // Now free the array
    free(bib->books);
    bib->books = NULL;

    bib->used = 0;
    bib->size = 0;
}

/*
 *  function:
 *      shows the options to the user, receives it's choice and decides which function to call
 *  params:
 *      Bib *bib
 */
void showMenu(Bib *bib)
{
    printf("HAUPTMEN%c:\n", UE);

    printf("[B]: Alle B%ccher anzeigen\n", ue);
    printf("[S]: B%ccher suchen\n", ue);
    printf("[A]: Buch ausleihen\n");
    printf("[Z]: Buch zur%cckgeben\n", ue);
    printf("[H]: Buch hinzuf%cgen\n", ue);
    printf("[L]: Buch l%cschen\n", oe);
    printf("[E]: Bibliotheksverwaltung verlassen\n");

    char menuPoint[BUFFERSIZE];
    char *allowedChars = "bsazhlce";

    // repeat user input if the input was wrong
    do{
        // get user input
//        printf("vor UserInput: book->numberof: %s\n", bib->books[5].numberof);
        printf("Aktion w%chlen: ", ae);
        getUserInput(menuPoint);
//        printf("nach UserInput: book->numberof: %s\n", bib->books[5].numberof);
        *menuPoint = tolower(*menuPoint);
//        return 0;

//        printf("menuPoint: %s\n", menuPoint);
//        printf("menuPointD: %d\n", menuPoint[0]);

        // verify user input and output error messages
//        verifyCharInput(menuPoint, allowedChars);

    } while(wrongCharInput(menuPoint, allowedChars));

    // TODO: nachdem editing-functions erfolgreich durchgeführt wurden, stürzts nach der nächsten suche/Eingabe ab
    // switch case structure to call the chosen function
    char menuHeader[BUFFERSIZE] = "";
    printf("\n");
    switch(menuPoint[0]){
        case 'b':
            strcpy(menuHeader, "ALLE BUECHER");
//            menuHeader = "ALLE BUECHER";
            printMenuHeader(menuHeader);
            showAll(bib);
            break;
        case 's':
            strcpy(menuHeader, "BUCH SUCHEN");
//            menuHeader = "BUCH SUCHEN";
            printMenuHeader(menuHeader);
            searchBooks(bib);
            break;
        case 'a':
            strcpy(menuHeader, "BUCH AUSLEIHEN");
//            menuHeader = "BUCH AUSLEIHEN";
            printMenuHeader(menuHeader);
            borrowBook(bib);
            break;
        case 'z':
            strcpy(menuHeader, "BUCH ZURUECKGEBEN");
//            menuHeader = "BUCH ZURUECKGEBEN";
            printMenuHeader(menuHeader);
            returnBook(bib);
            break;
        case 'h':
            strcpy(menuHeader, "NEUES BUCH HINZUFUEGEN");
//            menuHeader = "NEUES BUCH HINZUFUEGEN";
            printMenuHeader(menuHeader);
            addBook(bib);
            break;
        case 'l':
            strcpy(menuHeader, "BUCH LOESCHEN");
//            menuHeader = "BUCH LOESCHEN";
            printMenuHeader(menuHeader);
            deleteBooks(bib);
            break;
        case 'e':
            printf("Schlie%ce Bibliothek...\n", ss);
            // TODO: stürzt ab und zu ab
//            freeBooks(bib);
            exit(0);
            break;
        default:
            printf("ERROR: Falsche Eingabe!\n");
            break;
    }
//    printf("before strToLower\n");
    stringToLower(menuHeader);
    printMenuEnd(menuHeader);

//    freeTempString(menuPoint);

//    printMenuEnding(strlen(menuHeader));
    printf("\n");
    // call itself after other functions are completed
    showMenu(bib);
}

/*
 *  function:
 *      Initializes the Bibliothek, calls the loadBooks-function to loads the Bibliothek from data.csv file and starts the initial program.
 *  params:
 *
 */
int main()
{
    // initially loading the books from the data-text file
    Bib bib;
    loadBooks(&bib);

    // show "BIBLIOTHEK"-Header
    printf(" _______  ___   _______  ___      ___   _______  _______  __   __  _______  ___   _ \n|  _    ||   | |  _    ||   |    |   | |       ||       ||  | |  ||       ||   | | |\n| |_|   ||   | | |_|   ||   |    |   | |   _   ||_     _||  |_|  ||    ___||   |_| |\n|       ||   | |       ||   |    |   | |  | |  |  |   |  |       ||   |___ |      _|\n|  _   | |   | |  _   | |   |___ |   | |  |_|  |  |   |  |       ||    ___||     |_ \n| |_|   ||   | | |_|   ||       ||   | |       |  |   |  |   _   ||   |___ |    _  |\n|_______||___| |_______||_______||___| |_______|  |___|  |__| |__||_______||___| |_|\n\n");
    showMenu(&bib);

//    bib.books[0].author = "neu";
//    saveBooks(&bib);

    // searching for books and printing the author and the title of the found ones
//    char string[] = "e";
//    char *searchString = string;
//    foundBooks foundBooks;
//    search(&bib, &foundBooks, searchString);
//    for(int i=0; i<foundBooks.size; i++){
//        printf("author: %s | title: %s\n", foundBooks.books[i]->author, foundBooks.books[i]->title);
//    }

    // free all previously allocated memory
//    freeBooks(&bib);
//    freeFoundBooks(&foundBooks);

    return 0;
}
