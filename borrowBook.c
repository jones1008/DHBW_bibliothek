#include "borrowBook.h"
void borrowBook(Bib *books)
{
    char searchString[BUFFERSIZE];
    printf("Welches Buch soll ausgeliehen werden? (Titel, Autor, ISBN) ([ENTER] zum Abbrechen): ");
    // get user search, search for it and print the results
    getUserInput(searchString);
    if(!isAborted(searchString)){
        foundBooks foundBooks;
        search(books, &foundBooks, searchString);
        showFoundBooks(&foundBooks, "atinb");

        // let the user choose a book
        int chosenBook = 0;
        int isNotAborted;
        chooseBook(&foundBooks, &chosenBook, &isNotAborted);
        if(isNotAborted){
            // TODO: rausfinden, wie man hier auf das gewählte Buch kommt (PointerPointer)
            printf("chosenBook: %d\n", chosenBook);
//            printf("chosenbook isbn: %d\n", *foundBooks.array[chosenBook]);


//            printf("pointer to chosenBook: %s\n", foundBooks.array[chosenBook]->author);
//            actualBorrowBook(books, &foundBooks.array[chosenBook]);
        }
    }
}

void actualBorrowBook(Bib *books, book *book)
{
    // TODO: testen!!! ist bisher ungetestet

    // get number of borrowers
//    int numberOfBorrowers;
//    if(strlen(book->borrowlist)==0){
//        numberOfBorrowers = 0;
//    } else{
//        int numberOfCommas = countChars(book->borrowlist, ',');
//        if(numberOfCommas == 0){
//            numberOfBorrowers = 1;
//        } else{
//            numberOfBorrowers = numberOfCommas+1;
//        }
//    }
//    printf("numberOfBorrowers: %d\n", numberOfBorrowers);
//    // check if book has enough copies to borrow a copy (compare numberof and number of borrowers in borrowlist)
//    if(book->numberof >= numberOfBorrowers){
//        printf("ERROR: Dieses Buch kann nicht ausgeliehen werden, da keine Exemplare mehr zur Verfügung stehen.\n");
//    } else{
//        // get name of borrower from user
//        char name[BUFFERSIZE];
//        printf("Name Ausleiher (z.B. Max Mustermann) ([ENTER] zum Abbrechen): ");
//        getUserInput(name);
//        if(!isAborted(name)){
//            // remove comma if user put some in -> for example: Mustermann, Max
//            removeChar(name, ',');
//
//            // create new borrowlist and write it
//            char newBorrowList[strlen(book->borrowlist)+1+strlen(name)];
//            snprintf(newBorrowList, "%s, %s", book->borrowlist, name);
//            book->borrowlist = newBorrowList;
//
//            saveBooks(books);
//        }
//    }
}
