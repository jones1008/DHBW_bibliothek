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
    printf("[H]: Neues Buch hinzuf%cgen\n", ue);
    printf("[L]: Buch l%cschen\n", oe);
    printf("[E]: Bibliotheksverwaltung verlassen\n");

    char menuPoint[BUFFERSIZE];
    char *allowedChars = "bsazhlce";

    // repeat user input if the input was wrong
    do{
        // get user input
        printf("Aktion w%chlen: ", ae);
        getUserInput(menuPoint);
        *menuPoint = tolower(*menuPoint);
    } while(wrongCharInput(menuPoint, allowedChars));

    // switch case structure to call the chosen function
    char menuHeader[BUFFERSIZE] = "";
    printf("\n");
    switch(menuPoint[0]){
        case 'b':
            strcpy(menuHeader, "ALLE BUECHER");
            printMenuHeader(menuHeader);
            showAll(bib);
            break;
        case 's':
            strcpy(menuHeader, "BUCH SUCHEN");
            printMenuHeader(menuHeader);
            searchBooks(bib);
            break;
        case 'a':
            strcpy(menuHeader, "BUCH AUSLEIHEN");
            printMenuHeader(menuHeader);
            borrowBook(bib);
            break;
        case 'z':
            strcpy(menuHeader, "BUCH ZURUECKGEBEN");
            printMenuHeader(menuHeader);
            returnBook(bib);
            break;
        case 'h':
            strcpy(menuHeader, "NEUES BUCH HINZUFUEGEN");
            printMenuHeader(menuHeader);
            addBook(bib);
            break;
        case 'l':
            strcpy(menuHeader, "BUCH LOESCHEN");
            printMenuHeader(menuHeader);
            deleteBooks(bib);
            break;
        case 'e':
            printf("Schlie%ce Bibliothek...\n", ss);
            exit(0);
            break;
        default:
            printf("ERROR: Falsche Eingabe!\n");
            break;
    }
    stringToLower(menuHeader);
    printMenuEnd(menuHeader);
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

    return 0;
}
