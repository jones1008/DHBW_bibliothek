#include "borrowBook.h"
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
        showFoundBooks(&foundBooks, "atinb");

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
                // TODO: in function?
                printf("---> gew%chltes Buch: [%d] - %s - %s\n", ae, chosenBook+1, book->author, book->title);
                actualBorrowBook(bib, book, chosenBook);
            }
        } else if(foundBooks.size == 1){
            // write book and free foundBooks before other function is called
            book *book = foundBooks.books[0];
            freeFoundBooks(&foundBooks);
            printf("---> gew%chltes Buch: [%d] - %s - %s\n", ae, 1, book->author, book->title);
            actualBorrowBook(bib, book, 1);
        } else{
            freeFoundBooks(&foundBooks);
        }
//        freeFoundBooks(&foundBooks);
    }
}

void actualBorrowBook(Bib *bib, book *book, int chosenBook)
{
    // TODO: Ausleiher durchnummerieren und Benutzer nur Nummer angeben lassen?
    // TODO: wenn erster Ausleiher hinzugefügt wird, ist ein ", " zu viel davor
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
//                printf("numberof bo")
                sprintf(newBorrowList, "%s", name);
            } else{
                sprintf(newBorrowList, "%s, %s", book->borrowlist, name);
            }
//            printf("newBorrowList: %s\n", newBorrowList);
            book->borrowlist = newBorrowList;
//            printf("book->newBorrowList: %s\n", book->borrowlist);

            saveBooks(bib);
            printf("after saving");
        }
    }
}
