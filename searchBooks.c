#include "searchBooks.h"

/*
 *  function:
 *      Asks the user for a searchString, calls the search function with this searchString.
 *      Then it calls functions to show the results, choose a book and show available context actions.
 *  params:
 *      Bib *bib
 */
void searchBooks(Bib *bib)
{
    // get user search input
    char searchString[BUFFERSIZE];

    printf("Suchtext ([ENTER] zum Abbrechen): ");
    getUserInput(searchString);

    // check if the input was aborted
    if(!isAborted(searchString)){
        // pass searchString to the search-function
        foundBooks foundBooks;
        search(bib, &foundBooks, searchString);

        if(foundBooks.size != 0){
            showFoundBooks(&foundBooks, "atinb");
            if(foundBooks.size>1){
                int chosenBook = 0;
                int isNotAborted;
                chooseBook(&foundBooks, &chosenBook, &isNotAborted);
                if(isNotAborted){
                    chosenBook--;
                    // write book and free foundBooks before other function is called
                    book *book = foundBooks.books[chosenBook];
                    freeFoundBooks(&foundBooks);
                    // run context-action for the foundBooks
                    contextBookAction(bib, book, chosenBook);
                }
            } else if(foundBooks.size == 1){
                // write book and free foundBooks before other function is called
                book *book = foundBooks.books[0];
                freeFoundBooks(&foundBooks);
                contextBookAction(bib, book, 0);
            } else{
                freeFoundBooks(&foundBooks);
            }
        } else{
            freeFoundBooks(&foundBooks);
            searchBooks(bib);
        }
    }
}
