#include "searchBooks.h"

void searchBooks(Array *books)
{
    char *menuHeader = "BUCH SUCHEN";
    printMenuHeader(menuHeader);

    // get user search input
    char *searchString = calloc(1, 1);
    getUserInput(searchString, "Suchtext eingeben (IBSN, Buchtitel, Buchautor):");

    // pass searchString to the search-function
    foundBooks foundBooks;
    search(books, &foundBooks, searchString);

    // TODO: free searchString allocation

    // loop over foundBooks
    if(foundBooks.size > 0){
        // TODO: pagination when more than 5 books
        for(int i=0; i<foundBooks.size; i++){
            printf("author: %s | title: %s\n", foundBooks.array[i]->author, foundBooks.array[i]->title);
        }
        // TODO: Absprünge zum Bearbeiten/Ausleihen etc. hier einbauen (switch case)
    } else{
        printf("Keine B%ccher mit '%s' gefunden\n", ue, searchString);
    }

    showReturnToMenu();

    printMenuEnding(strlen(menuHeader));
}
