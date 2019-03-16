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
//        freeFoundBooks(&foundBooks);
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
//    printf("before first if\n");
    if(book->borrowlist[0] != '\0'){
        char delimiter[] = ",";

        char borrowlistCopy[strlen(book->borrowlist)];
        strcpy(borrowlistCopy, book->borrowlist);
        char *ptr = strtok(borrowlistCopy, delimiter);

        int i = 0;
        while(ptr != NULL){
            char *tmpPtr = trim(ptr);
            printf("[%d] %s\n", i+1, tmpPtr);
            ptr = strtok(NULL, delimiter);
            i++;
        }

        int isNotAborted;
        int borrowerCount = i;
        printf("borrowerCount: %d\n", borrowerCount);
        int chosenNumber;
        char userInput[BUFFERSIZE];

        do{
            printf("W%chle Zur%cckgebender [NUMMER] ([ENTER] zum Abbrechen): ", ae, ue);
            getUserInput(userInput);
            printf("after getting userinput\n");
            chosenNumber = atoi(userInput);

            // check for Abortion through user (pressed ENTER)
            isNotAborted = !isAborted(userInput);

//            printf("isNotAborted: %d\n", *name);

            // if number out of index was chosen
            if(isNotAborted && (chosenNumber<=0 || chosenNumber>borrowerCount)){
                printf("ERROR: Falsche Eingabe oder eingegebene Zahl au%cerhalb des Index!\n", ss);
            }
        } while(isNotAborted && (chosenNumber<=0 || chosenNumber>borrowerCount));

//        printf("chosenNumber: %d\n", chosenNumber);

        char newBorrowList[strlen(book->borrowlist)];
        char chosenBorrower[strlen(book->borrowlist)];
        memset(newBorrowList, 0, strlen(book->borrowlist));

        char *newPtr = strtok(book->borrowlist, delimiter);
        int j = 0;
//        printf("chosenNumber-1: %d\n", chosenNumber-1);
        int firstUnmatch = 1;
        while(newPtr != NULL){
            char *tmpPtr = trim(newPtr);
            printf("j: %d\n", j);
            printf("chosenNumber: %d\n", chosenNumber);
            // if the chosenNumber is not the current loop -> not the current tmpPtr -> not the current borrower -> add this borrower to the newBorrowList
            if(j!=(chosenNumber-1)){
                if(firstUnmatch){
//                    printf("before snprintf 1\n");
                    printf("tmpPtr: %s\n", tmpPtr);
                    snprintf(newBorrowList, strlen(tmpPtr)+1, "%s", tmpPtr);
                } else{
//                    printf("before snprintf 2\n");
                    snprintf(newBorrowList, strlen(newBorrowList)+3+strlen(tmpPtr), "%s, %s", newBorrowList, tmpPtr);
                }
                firstUnmatch = 0;
            } else{
                printf("tmpPtr: %s\n", tmpPtr);
                printf("stlren(tmpPtr): %d\n", strlen(tmpPtr));
                snprintf(chosenBorrower, strlen(tmpPtr)+1, "%s", tmpPtr);
            }
            printf("current newBorrowList: %s\n", newBorrowList);
            newPtr = strtok(NULL, delimiter);
            j++;
        }
        // TODO: falscher Wert in newBorrowList, wenn der letzte Ausleiher gelöscht wurde
        printf("newBorrowList: %s\n", newBorrowList);
        book->borrowlist = newBorrowList;

        // TODO: speichern funktioniert hier nicht! (gleicher Fehler wie bei borrowBook -> oder funktionierts doch?
        saveBooks(bib);
        printf("---> '%s' wurde von der Ausleihliste entfernt.\n", chosenBorrower);


        // repeat user input if nothing was found
//        int isNotAborted;
//        int firstUnmatch = 1;
//        int found = 0;


//        printf("before first while\n");
//        do{
//            printf("Name Zur%cckgebender ([ENTER] zum Abbrechen): ", ue);
//            getUserInput(name);
//            printf("after getting input\n");
//            isNotAborted = !isAborted(name);
//            printf("before if\n");
//            if(isNotAborted){
//                // remove commas from user input
//                removeChar(name, ',');
//                printf("before replaceUmlauts\n");
//                replaceUmlauts(name);
//
//                printf("before newBorrowLIst\n");
//                // initialize newBorrowList
//                char *newBorrowList = malloc(strlen(book->borrowlist)*sizeof(char));
//                memset(newBorrowList, 0, strlen(book->borrowlist));
//
//                printf("after memset\n");
//                // split borrowlist into its borrowers
//                char delimiter[] = ",";
//                char *ptr = strtok(book->borrowlist, delimiter);
//
//                printf("before while loop\n");
//
//                int i=0;
//                while(ptr != NULL){
//                    // create a temporary copy of the current string with trimmed spaces
////                    char *tmpPtr = trimWhitespace(ptr);
//                    char *tmpPtr = trim(ptr);
////                    char tmpPtr[strlen(ptr)];
////                    trimWhitespace(tmpPtr, strlen(ptr), ptr);
//
//                    // check if current string doesn't match the user input
//                    if(strcmp(tmpPtr, name) != 0){
//                        // check if this is the first loop it doesn't match the user input and change what should be written to newBorrowList
//                        if(firstUnmatch){
//                            snprintf(newBorrowList, strlen(tmpPtr)+1, "%s", tmpPtr);
//                        } else{
//                            snprintf(newBorrowList, strlen(newBorrowList)+3+strlen(tmpPtr), "%s, %s", newBorrowList, tmpPtr);
//                        }
//                        firstUnmatch = 0;
//                    } else{
//                        found = 1;
//                    }
//                    ptr = strtok(NULL, delimiter);
//                    i++;
//                }
//
//                // save new borrowlist only if something was found
//                if(found){
//                    book->borrowlist = newBorrowList;
//                    printf("---> '%s' wurde von der Ausleihliste entfernt.\n", name);
//                    saveBooks(bib);
//                } else{
//                    printf("ERROR: '%s' nicht in der Ausleihliste gefunden!\n", name);
//                }
//
//                freeTempString(newBorrowList);
//            }
//        } while(isNotAborted && !found);
    } else{
        printf("ERROR: Das gew%chlte Buch wurde bisher noch nicht ausgeliehen!\n", ae);
    }
}
