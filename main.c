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

//TODO: rausschmeißen, falls das nicht mehr gebraucht wird


void printErrorMessage()
{

}
void exitProgram()
{

}

void showMenu(Array *books)
{
    printf("HAUPTMEN%c:\n", UE);
    // initialize buffer with zeros
    char buffer[BUFFERSIZE];
    memset(buffer, 0, BUFFERSIZE);

    // some more variables
    char *buf = buffer;
    char menuPoint;
    char *allowedChars = "sazhlce";

    // repeat user input if the input was wrong
    do{
        // check if userInput is longer than one character or not the first loop
        if((strlen(buffer)-1)>1 && strlen(buffer)!=0){
            // TODO: an printErrorMessage schicken, wenn diese geschrieben ist
            printf("Bitte nur einen Buchstaben eingeben\n");
        }

        // write menu if user input was wrong
        if(strlen(buffer)==0 || strlen(buffer)>1 || buffer[0]=='\n'){
            printf("[S]: B%ccher suchen\n", ue);
            printf("[A]: Buch ausleihen\n");
            printf("[Z]: Buch zur%cckgeben\n", ue);
            printf("[H]: Buch hinzuf%cgen\n", ue);
            printf("[L]: Buch l%cschen\n", oe);
            printf("[C]: Buchexemplar hinzuf%cgen\n", ue);
            printf("[E]: Bibliotheksverwaltung verlassen\n");
        }

        // TODO: mit getUserInput bauen!
        printf("Aktion w%chlen: ", ae);
        fgets(buf, BUFFERSIZE, stdin);
        strncpy(&menuPoint, buf, 1);
        menuPoint = tolower(menuPoint);

        // check if user input is an allowed char
        if(strchr(allowedChars, menuPoint) == NULL){
            // TODO: an printErrorMessage schicken, wenn diese geschrieben ist
            printf("Falsche Eingabe!\n");
        }
    } while ((strlen(buffer)-1)>1 || strchr(allowedChars, menuPoint) == NULL);

    // switch case structure to call the chosen function
    // TODO: in function
    char *menuHeader;
    printf("\n");
    switch(menuPoint){
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
            printf("Falsche Eingabe!\n");
            break;
    }
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


// TODO: ist dies an der richtigen Stelle? Brauchen wir das nicht woanders?
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
