#include "searchBooks.h"

// wrapper function
void searchBooks(Array *books)
{
    char *menuHeader = "BUCH SUCHEN";
    printMenuHeader(menuHeader);

    actualSearchBooks(books);

    printMenuEnding(strlen(menuHeader));
}

void actualSearchBooks(Array *books)
{
    // get user search input
    char *searchString = calloc(1, 1);
    getUserInput(searchString, "Suchtext ([ENTER] zum Abbrechen): ");

    // check if no input was made
    if(searchString[0] != '\0'){
        // pass searchString to the search-function
        foundBooks foundBooks;
        search(books, &foundBooks, searchString);

        // loop over foundBooks
        if(foundBooks.size > 0){
            printf("\n");
            // TODO: pagination when more than 4 books
            for(int i=0; i<foundBooks.size; i++){
                printf("Autor    : %s\n", foundBooks.array[i]->author);
                printf("Titel    : %s\n", foundBooks.array[i]->title);
                printf("ISBN     : %s\n", foundBooks.array[i]->isbn);
                printf("Anzahl   : %s\n", foundBooks.array[i]->numberof);
                printf("Ausleiher: %s\n", foundBooks.array[i]->borrowlist);
                // add Line if it isn't the last found book
                if(i+1<foundBooks.size){
                    printf("---------\n");
                }
            }
            printf("\n");
            showReturnToMenu();
            // TODO: Absprünge zum Bearbeiten/Ausleihen etc. hier einbauen (switch case)?
        } else{
            // TODO: in printErrorMessage-function einbauen
            printf("Keine B%ccher mit '%s' gefunden\n", ue, searchString);
            // call itself again to search again
            actualSearchBooks(books);
        }
        printf("\n");
    } else{
        printf("Abbrechen...\n");
    }

    // free searchString allocation
    freeTempString(searchString);
}
