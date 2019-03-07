#include "searchBooks.h"

void searchBooks(Array *books)
{
    // get user search input
    char *searchString = calloc(1, 1);

//    getUserInput(searchString, "Suchtext ([ENTER] zum Abbrechen): ");
    printf("Suchtext ([ENTER] zum Abbrechen): ");
    getUserInput(searchString);

    // check if the input was aborted
    if(!isAborted(searchString)){
        // pass searchString to the search-function
        foundBooks foundBooks;
        search(books, &foundBooks, searchString);

        // loop over foundBooks
        if(foundBooks.size > 0){
            printf("\n");
            for(int i=0; i<foundBooks.size; i++){
                printf("[%d]\n", i+1);
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

            // let the user choose a book to borrow/return/delete/addCopy the chosen book
            int chosenBook = 0;
            char *userNumber = calloc(1,1);
            int isNotAborted;

            do{
//                getUserInput(userInput, "Buch waehlen [NUMMER] ([ENTER] zum Abbrechen): ");
                printf("Buch w%chlen [NUMMER] ([ENTER] zum Abbrechen): ", ae);
                getUserInput(userNumber);
                chosenBook = atoi(userNumber);

                // if number out of index was chosen
                if(chosenBook<=0 || chosenBook>foundBooks.size){
                    // TODO: in printErrorMessage reinpacken
                    printf("Falsche Eingabe oder eingegebene Zahl au%cerhalb des Index!\n", ss);
                }

                // check for Abortion through user (pressed ENTER)
                isNotAborted = !isAborted(userNumber);

//            } while((chosenBook<=0 || chosenBook>foundBooks.size) && chosenBook != '\0');
            } while( (chosenBook<=0 || chosenBook>foundBooks.size) && isNotAborted);

            // when a number was chosen: ask user what he wants to do with that book
            if(isNotAborted) {
                printf("---> gew%chltes Buch: [%d] - %s - %s\n", ae, chosenBook, foundBooks.array[chosenBook-1]->author, foundBooks.array[chosenBook-1]->title);

                char *allowedChars = "azlc";
                char *menuPoint = calloc(1,1);
                int isNotAborted;

                // repeat user input if the input was wrong or not Aborted
                do{
                    // check if menuPoint is longer than one character or not the first loop
                    if((strlen(menuPoint)-1)>1 && strlen(menuPoint)!=0){
                        // TODO: an printErrorMessage schicken, wenn diese geschrieben ist
                        printf("Bitte nur einen Buchstaben eingeben!\n");
                    }

                    // write menu if user input was wrong
                    if(strlen(menuPoint)==0 || strlen(menuPoint)>1){
                        printf("[A]: Buch ausleihen\n");
                        printf("[Z]: Buch zur%cckgeben\n", ue);
                        printf("[L]: Buch l%cschen\n", oe);
                        printf("[C]: Buchexemplar hinzuf%cgen\n", ue);
                    }

                    // get user input and write tolower-variable so comparison is
                    printf("Aktion w%chlen ([ENTER] zum Abbrechen): ", ae);
                    getUserInput(menuPoint);
                    *menuPoint = tolower(*menuPoint);

                    // check for allowed chars and if more than one input char
                    if(strchr(allowedChars, menuPoint[0]) == NULL && (strlen(menuPoint)-1)<=1){
                        // TODO: an printErrorMessage schicken, wenn diese geschrieben ist
                        printf("Falsche Eingabe!\n");
                    }

                    // check for Abortion through user (pressed ENTER)
                    isNotAborted = !isAborted(menuPoint);

                } while ( ((strlen(menuPoint)-1)>1 || strchr(allowedChars, menuPoint[0]) == NULL) && isNotAborted);

                // if user chose a number and did not hit ENTER
                if(isNotAborted){
                    printf("\n");
                    // run the corresponding function with a pointer to the chosen book
                    // TODO: add feedback to the user that the action was performed
                    switch(menuPoint[0]){
                        case 'a':
                            actualBorrowBook(books, foundBooks.array[chosenBook-1]);
                            break;
                        case 'z':
                            actualReturnBook(books, foundBooks.array[chosenBook-1]);
                            break;
                        case 'l':
                            actualDeleteBooks(books, foundBooks.array[chosenBook-1]);
                            break;
                        case 'c':
                            actualAddCopies(books, foundBooks.array[chosenBook-1]);
                            break;
                        default:
                            printf("Falsche Eingabe!\n");
                            break;
                    }
                }
                freeTempString(menuPoint);
            }
            freeTempString(userNumber);
        } else{
            // TODO: in printErrorMessage-function einbauen
            printf("Keine B%ccher mit '%s' gefunden!\n", ue, searchString);

            // call itself again to search again
            searchBooks(books);
        }
    }
    freeTempString(searchString);
}
