#include "searchBooks.h"

/*
 *  function:
 *
 *  params:
 *
 */
void searchBooks(Bib *bib)
{
    // get user search input
//    char *searchString = malloc(0);
    char searchString[BUFFERSIZE];

//    getUserInput(searchString, "Suchtext ([ENTER] zum Abbrechen): ");
    printf("Suchtext ([ENTER] zum Abbrechen): ");
    getUserInput(searchString);

//    printf("searchString: %s\n", searchString);
//    printf("searchStringD: %d\n", searchString[0]);

    // check if the input was aborted
    printf("isAborted: %d\n", isAborted(searchString));
    if(!isAborted(searchString)){
        printf("is not aborted!\n");
        // pass searchString to the search-function
        foundBooks foundBooks;
        printf("vor search: book->numberof: %s\n", bib->books[5].numberof);
        printf("before search\n");
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
                contextBookAction(bib, book, 1);
            } else{
                freeFoundBooks(&foundBooks);
            }
        } else{
//            printf("no results: before freefoundBooks\n");
            freeFoundBooks(&foundBooks);
//            printf("no results: before searchBooks\n");
            searchBooks(bib);
        }
//        freeFoundBooks(&foundBooks);
    }
}
//    printf("end of searchBooks()\n");
