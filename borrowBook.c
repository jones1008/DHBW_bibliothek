#include "borrowBook.h"

/*
 *  function:
 *      First the user is asked which book he wants to borrow (input searchString).
 *      Then he decides which one he wants from the found books. If it is only one result it auto-selects the first one and continues.
 *  params:
 *      Bib *bib
 */
void borrowBook(Bib *bib)
{
//    saveBooks(bib);
    char searchString[BUFFERSIZE];
    printf("Welches Buch soll ausgeliehen werden? (Titel, Autor, ISBN) ([ENTER] zum Abbrechen): ");
    // get user search, search for it
    getUserInput(searchString);
    if(!isAborted(searchString)){
        foundBooks foundBooks;
        search(bib, &foundBooks, searchString);
//        printf("Anzahl gefunden: %d\n", foundBooks.size);
        showFoundBooks(&foundBooks, "atib");

        // if only one result choose this book automatically
        if(foundBooks.size>1){
            // let the user choose a book
            int chosenBook = 0;
            int isNotAborted;
            chooseBook(&foundBooks, &chosenBook, &isNotAborted);

            if(isNotAborted){
                chosenBook--;
                // write book and free foundBooks before other function is called
                book *book = foundBooks.books[chosenBook];
                freeFoundBooks(&foundBooks);

                showChosenBook(chosenBook, book);
                actualBorrowBook(bib, book, chosenBook);
            }
        } else if(foundBooks.size == 1){
            // write book and free foundBooks before other function is called
            book *book = foundBooks.books[0];
            freeFoundBooks(&foundBooks);
            showChosenBook(0, book);
            actualBorrowBook(bib, book, 1);
        } else{
            freeFoundBooks(&foundBooks);
            borrowBook(bib);
        }
//        freeFoundBooks(&foundBooks);
    }
}

/*
 *  function:
 *      Gets the chosen book as second parameter and checks if it is borrowable. If yes, it asks for the name (user input) and adds it to the borrowlist
 *  params:
 *      Bib *bib
 *      book *book (the book pointer that was chosen before)
 *      int chosenBook
 */
void actualBorrowBook(Bib *bib, book *book, int chosenBook)
{
    // TODO: speichern stürzt hier danach ab bei fprintf in saveBooks()
    // get current number of borrowers
    int numberOfBorrowers;

    if(strlen(book->borrowlist)==0){
        numberOfBorrowers = 0;
    } else{
        int numberOfCommas = countChars(book->borrowlist, ',');
//        printf("numberOfCommas: %d\n", numberOfCommas);
        if(numberOfCommas == 0){
            numberOfBorrowers = 1;
        } else{
            numberOfBorrowers = numberOfCommas+1;
        }
    }
    int numberof = atoi(book->numberof);
    // check if book has enough copies to borrow a copy (compare numberof and number of borrowers in borrowlist)
    if(numberOfBorrowers >= numberof){
        printf("ERROR: Dieses Buch kann nicht ausgeliehen werden, da keine Exemplare mehr zur Verf%cgung stehen.\n", ue);
    } else{
        // get name of borrower from user
        char name[BUFFERSIZE];
        printf("Name Ausleiher (z.B. Max Mustermann) ([ENTER] zum Abbrechen): ");
        getUserInput(name);
//        printf("actalBorrow: name: %s\n", name);
        if(!isAborted(name)){
            // remove comma if user put some in -> for example: Mustermann, Max
            removeChar(name, ',');
            replaceUmlauts(name);

            // create new borrowlist and write it
            char newBorrowList[strlen(book->borrowlist)+1+strlen(name)];
            if(numberOfBorrowers == 0){
                printf("numberof bo\n");
                sprintf(newBorrowList, "%s", name);
            } else{
                sprintf(newBorrowList, "%s, %s", book->borrowlist, name);
            }
//            printf("newBorrowList: %s\n", newBorrowList);
            book->borrowlist = newBorrowList;
//            printf("book->newBorrowList: %s\n", book->borrowlist);

            saveBooks(bib);
            printf("---> '%s' wurde in die Ausleihliste eingetragen.\n", name);
            printf("after saving");
        }
    }
}
