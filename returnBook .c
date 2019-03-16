#include "returnBook.h"

/*
 *  function:
 *      Asks the user which book should be returned (searchString) and lets the user choose which one he want to return.
 *      If only one book was found auto-select this one. After that actualReturnBook with the given book is called.
 *  params:
 *      Bib *bib
 */
void returnBook(Bib *bib)
{
    char searchString[BUFFERSIZE];
    printf("Welches Buch soll zur%cckgegeben werden? (Titel, Autor, ISBN) ([ENTER] zum Abbrechen): ", ue);
    // get user search, search for it and print the results
    getUserInput(searchString);
    if(!isAborted(searchString)){
        foundBooks foundBooks;
        search(bib, &foundBooks, searchString);
        showFoundBooks(&foundBooks, "atib");

        // if only one result choose this book automatically
        if(foundBooks.size>1){
            // let the user choose a book
            int chosenBook = 0;
            int isNotAborted;
            chooseBook(&foundBooks, &chosenBook, &isNotAborted);
            printf("after chosing\n");

            if(isNotAborted){
                chosenBook--;
                // write book and free foundBooks before other function is called
                book *book = foundBooks.books[chosenBook];
                freeFoundBooks(&foundBooks);

                showChosenBook(chosenBook, book);
                actualReturnBook(bib, book, chosenBook);
            } else{
                freeFoundBooks(&foundBooks);
            }
        } else if(foundBooks.size == 1){
            book *book = foundBooks.books[0];
            freeFoundBooks(&foundBooks);
            showChosenBook(0, book);
            actualReturnBook(bib, book, 1);
        } else{
            freeFoundBooks(&foundBooks);
            returnBook(bib);
        }
    }
}

/*
 *  function:
 *      Checks if book can be returned (if something is in the borrowlist)
 *      Then lets the user choose which one of the borrowlist is returning the book to delete him from the borrowlist.
 *  params:
 *      Bib *bib
 *      book *book (the pointer to the book that was chosen before)
 *      int chosenBook (the index of the pointer in the foundBooks array)
 */
void actualReturnBook(Bib *bib, book *book, int chosenBook)
{
    // print error message if borrowlist is empty
    if(book->borrowlist[0] != '\0'){
        char delimiter[] = ",";

        char borrowlistCopy[strlen(book->borrowlist)];
        strcpy(borrowlistCopy, book->borrowlist);
        char *ptr = strtok(borrowlistCopy, delimiter);

        printf("Liste der Ausleiher:\n");
        int i = 0;
        while(ptr != NULL){
            char *tmpPtr = trim(ptr);
            printf("[%d] %s\n", i+1, tmpPtr);
            ptr = strtok(NULL, delimiter);
            i++;
        }

        int isNotAborted;
        int borrowerCount = i;
        int chosenNumber;
        char userInput[BUFFERSIZE];

        do{
            printf("W%chle Zur%cckgebender [NUMMER] ([ENTER] zum Abbrechen): ", ae, ue);
            getUserInput(userInput);
            chosenNumber = atoi(userInput);

            // check for Abortion through user (pressed ENTER)
            isNotAborted = !isAborted(userInput);

            // if number out of index was chosen
            if(isNotAborted && (chosenNumber<=0 || chosenNumber>borrowerCount)){
                printf("ERROR: Falsche Eingabe oder eingegebene Zahl au%cerhalb des Index!\n", ss);
            }
        } while(isNotAborted && (chosenNumber<=0 || chosenNumber>borrowerCount));

        if(isNotAborted){
            char newBorrowList[strlen(book->borrowlist)];
            char chosenBorrower[strlen(book->borrowlist)];
            memset(newBorrowList, 0, strlen(book->borrowlist));

            char *newPtr = strtok(book->borrowlist, delimiter);
            int j = 0;
            int firstUnmatch = 1;
            while(newPtr != NULL){
                char *tmpPtr = trim(newPtr);
                // if the chosenNumber is not the current loop -> not the current tmpPtr -> not the current borrower -> add this borrower to the newBorrowList
                if(j!=(chosenNumber-1)){
                    if(firstUnmatch){
                        snprintf(newBorrowList, strlen(tmpPtr)+1, "%s", tmpPtr);
                    } else{
                        snprintf(newBorrowList, strlen(newBorrowList)+3+strlen(tmpPtr), "%s, %s", newBorrowList, tmpPtr);
                    }
                    firstUnmatch = 0;
                } else{
                    snprintf(chosenBorrower, strlen(tmpPtr)+1, "%s", tmpPtr);
                }
                newPtr = strtok(NULL, delimiter);
                j++;
            }
            book->borrowlist = newBorrowList;

            printf("\n");
            saveBooks(bib);
            printf("---> '%s' wurde von der Ausleihliste entfernt.\n", chosenBorrower);
        }
    } else{
        printf("ERROR: Das gew%chlte Buch wurde bisher noch nicht ausgeliehen!\n", ae);
    }
}
