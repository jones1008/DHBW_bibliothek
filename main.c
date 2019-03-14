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
#include "showAll.h"
#include "structure.h"
#include "helperFunctions.h"

void showMenu(Bib *bib)
{
    printf("HAUPTMEN%c:\n", UE);

    printf("[B]: Alle B%ccher anzeigen\n", ue);
    printf("[S]: B%ccher suchen\n", ue);
    printf("[A]: Buch ausleihen\n");
    printf("[Z]: Buch zur%cckgeben\n", ue);
    printf("[H]: Buch hinzuf%cgen\n", ue);
    printf("[L]: Buch l%cschen\n", oe);
    printf("[C]: Buchexemplar hinzuf%cgen\n", ue);
    printf("[E]: Bibliotheksverwaltung verlassen\n");

//    char *menuPoint = malloc(0);
    char menuPoint[BUFFERSIZE];
    char *allowedChars = "bsazhlce";

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
        case 'b':
            menuHeader = "ALLE BUECHER";
            printMenuHeader(menuHeader);
            showAll(bib);
            break;
        case 's':
            menuHeader = "BUCH SUCHEN";
            printMenuHeader(menuHeader);
            searchBooks(bib);
            break;
        case 'a':
            menuHeader = "BUCH AUSLEIHEN";
            printMenuHeader(menuHeader);
            borrowBook(bib);
            break;
        case 'z':
            menuHeader = "BUCH ZURUECKGEBEN";
            printMenuHeader(menuHeader);
            returnBook(bib);
            break;
        case 'h':
            menuHeader = "NEUES BUCH HINZUFUEGEN";
            printMenuHeader(menuHeader);
            addBook(bib);
            break;
        case 'l':
            menuHeader = "BUCH LOESCHEN";
            printMenuHeader(menuHeader);
            deleteBooks(bib);
            break;
        case 'c':
            menuHeader = "BUCHEXEMPLAR HINZUFUEGEN";
            printMenuHeader(menuHeader);
            addCopies(bib);
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
    showMenu(bib);
}
void showHeading()
{
    printf(" _______  ___   _______  ___      ___   _______  _______  __   __  _______  ___   _ \n|  _    ||   | |  _    ||   |    |   | |       ||       ||  | |  ||       ||   | | |\n| |_|   ||   | | |_|   ||   |    |   | |   _   ||_     _||  |_|  ||    ___||   |_| |\n|       ||   | |       ||   |    |   | |  | |  |  |   |  |       ||   |___ |      _|\n|  _   | |   | |  _   | |   |___ |   | |  |_|  |  |   |  |       ||    ___||     |_ \n| |_|   ||   | | |_|   ||       ||   | |       |  |   |  |   _   ||   |___ |    _  |\n|_______||___| |_______||_______||___| |_______|  |___|  |__| |__||_______||___| |_|\n\n");
}

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
        free(&bib->array[i].isbn);
        bib->array[i].isbn=NULL;

        free(&bib->array[i].title);
        bib->array[i].title=NULL;

        free(&bib->array[i].author);
        bib->array[i].author=NULL;

        free(&bib->array[i].numberof);
        bib->array[i].numberof=NULL;

        free(&bib->array[i].borrowlist);
        bib->array[i].borrowlist=NULL;
    }
    // Now free the array
    free(bib->array);
    bib->array = NULL;

    bib->used = 0;
    bib->size = 0;
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
//        foundBooks->array[i]=NULL;
    }
    // Now free the array
    free(foundBooks->array);
    foundBooks->array = NULL;

    foundBooks->size = 0;
}

int main()
{
    // initially loading the books from the data-text file
    Bib bib;
    loadBooks(&bib);

    showHeading();
//    system("cls");
    showMenu(&bib);

//    bib.array[0].author = "neu";
//    saveBooks(&bib);

    // searching for books and printing the author and the title of the found ones
//    char string[] = "e";
//    char *searchString = string;
//    foundBooks foundBooks;
//    search(&bib, &foundBooks, searchString);
//    for(int i=0; i<foundBooks.size; i++){
//        printf("author: %s | title: %s\n", foundBooks.array[i]->author, foundBooks.array[i]->title);
//    }

    // free all previously allocated memory
    freeBooks(&bib);
//    freeFoundBooks(&foundBooks);

    return 0;
}
