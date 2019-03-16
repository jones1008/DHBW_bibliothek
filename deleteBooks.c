#include "deleteBooks.h"

/*
 *  function:
 *      Asks the user for a searchString to specify which book should be deleted.
 *      If results are more than one let the user choose. If it has only one result auto select this book. After that call the actualDeleteBooks function.
 *  params:
 *      Bib *bib
 */
void deleteBooks(Bib *bib)
{
    char searchString[BUFFERSIZE];
    printf("Welches Buch soll gel%cscht werden? (Titel, Autor, ISBN) ([ENTER] zum Abbrechen): ", oe);
    // get user search, search for it and print the results
    getUserInput(searchString);
    if(!isAborted(searchString)){
        foundBooks foundBooks;
        search(bib, &foundBooks, searchString);
        showFoundBooks(&foundBooks, "atbn");

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
                actualDeleteBooks(bib, book, chosenBook);
            }
        } else if(foundBooks.size == 1){
            book *book = foundBooks.books[0];
            freeFoundBooks(&foundBooks);
            showChosenBook(0, book);
            actualDeleteBooks(bib, book, 1);
        } else{
            freeFoundBooks(&foundBooks);
            deleteBooks(bib);
        }
    }
}

/*
 *  function:
 *      Asks the user how many books should be deleted from given book.
 *      Then checks if the number is equal to the current number of copies. If yes: deletes book entry completely. If no: subtracts the number from the numberof-attribute
 *  params:
 *      Bib *bib
 *      book *book (the pointer to the book that was chosen before)
 *      int chosenBook (the index of the pointer in the foundBooks array)
 */
void actualDeleteBooks(Bib *bib, book *book, int chosenBook)
{
    char deleteCountString[BUFFERSIZE];
    int deleteCount;

    // get numberof into int
    int numberof = atoi(book->numberof);
    // note: you can't delete books that are currently borrowed -> maxDeletion
    int maxDeletion = numberof-getNumberOfBorrowers(book);

    int isNotAborted;
    // repeat input if deleteCount is not a number or above numberof
    do{
        printf("Anzahl zu l%cschender Exemplare (max. %d) ([ENTER] zum Abbrechen): ", oe, maxDeletion);
        getUserInput(deleteCountString);
        isNotAborted = !isAborted(deleteCountString);
        if(isNotAborted){
            deleteCount = atoi(deleteCountString);

            // if number out of allowed area was chosen
            if(deleteCount>maxDeletion || deleteCount<=0){
                printf("ERROR: Falsche Eingabe oder eingegebene Zahl au%cerhalb des Index!\n", ss);
            }
        }
    } while(isNotAborted && (deleteCount>maxDeletion || deleteCount<=0));

    if(isNotAborted){
        // lower the number of if deleteCount is lower than the existing copies, else delete book entry completely
        if(deleteCount<numberof){
            int newNumberof = numberof-deleteCount;
            char newNumberofString[12];
            sprintf(newNumberofString, "%d", newNumberof);
            book->numberof = newNumberofString;
            printf("\n");
            printf("---> %d Exemplare des Buchs werden entfernt...\n", deleteCount);
        } else{
            // ask user if he wants is sure to delete the complete book
            char choice[BUFFERSIZE];
            char *allowedChars = "jn";
            do{
                printf("Wirklich das Buch komplett l%cschen? [J][N]: ", oe);
                getUserInput(choice);
                *choice = tolower(*choice);
            } while(wrongCharInput(choice, allowedChars));

            if(choice[0] == 'j'){
                // delete book completely
                book->isbn = NULL;
                book->author = NULL;
                book->title = NULL;
                book->numberof = NULL;
                book->borrowlist = NULL;
                printf("\n");
                printf("---> Das Buch wird komplett gel%cscht...\n", oe);
            } else if(choice[0] == 'n'){
                // set isNotAborted to 0, so it won't save
                isNotAborted = 0;
                // show "Abbrechen"
                isAborted("");
            }
        }
        if(isNotAborted){
            saveBooks(bib);
        }
    }
}
