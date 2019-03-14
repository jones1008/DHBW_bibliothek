#include "borrowBook.h"
void borrowBook(Bib *bib)
{
    char searchString[BUFFERSIZE];
    printf("Welches Buch soll ausgeliehen werden? (Titel, Autor, ISBN) ([ENTER] zum Abbrechen): ");
    // get user search, search for it
    getUserInput(searchString);
    if(!isAborted(searchString)){
        foundBooks foundBooks;
        search(bib, &foundBooks, searchString);

        // if only one result choose this book automatically
        if(foundBooks.size>1){
            // print the results and let the user choose a book
            showFoundBooks(&foundBooks, "atinb");
            int chosenBook = 0;
            int isNotAborted;
            chooseBook(&foundBooks, &chosenBook, &isNotAborted);
            if(isNotAborted){
                actualBorrowBook(bib, foundBooks.books[chosenBook]);
            }
        } else if(foundBooks.size == 1){
            actualBorrowBook(bib, foundBooks.books[0]);
        }
    }
}

void actualBorrowBook(Bib *bib, book *book)
{
    // TODO: convert umlaute
    // get number of borrowers
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
        if(!isAborted(name)){
            // remove comma if user put some in -> for example: Mustermann, Max
            removeChar(name, ',');

            // create new borrowlist and write it
            char newBorrowList[strlen(book->borrowlist)+1+strlen(name)];
            sprintf(newBorrowList, "%s, %s", book->borrowlist, name);
            book->borrowlist = newBorrowList;

            saveBooks(bib);
        }
    }
}
