#include "searchBooks.h"

void searchBooks(Array *books)
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
            char *userInput = calloc(1,1);
            do{
                getUserInput(userInput, "Buch waehlen [NUMMER] ([ENTER] zum Abbrechen): ");
                chosenBook = atoi(userInput);

                // if number out of index was chosen
                if(chosenBook<0 || chosenBook>foundBooks.size){
                    // TODO: in printErrorMessage reinpacken
                    printf("Buch ausserhalb des Index\n");
                }
            } while((chosenBook<0 || chosenBook>foundBooks.size) && chosenBook != '\0');

            // when a number was chosen: ask user what he wants to do with that book
            if(chosenBook != '\0') {
                printf("---> gew%chltes Buch: [%d] - %s - %s\n", ae, chosenBook, foundBooks.array[chosenBook-1]->author, foundBooks.array[chosenBook-1]->title);

                // initialize buffer with zeros
                char buffer[BUFFERSIZE];
                memset(buffer, 0, BUFFERSIZE);

                // some more variables
                char *buf = buffer;
                char menuPoint;
                char *allowedChars = "azlc";
                // repeat user input if the input was wrong
                do{
                    // check if userInput is longer than one character or not the first loop
                    if((strlen(buffer)-1)>1 && strlen(buffer)!=0){
                        // TODO: an printErrorMessage schicken, wenn diese geschrieben ist
                        printf("Bitte nur einen Buchstaben eingeben\n");
                    }

                    // write menu if user input was wrong
                    if(strlen(buffer)==0 || strlen(buffer)>1 || buffer[0]=='\n'){
//                        printf("Was m%cchtest du mit dem Buch machen?\n", oe);
                        printf("[A]: Buch ausleihen\n");
                        printf("[Z]: Buch zur%cckgeben\n", ue);
                        printf("[L]: Buch l%cschen\n", oe);
                        printf("[C]: Buchexemplar hinzuf%cgen\n", ue);
                    }

                    printf("Aktion w%chlen ([ENTER] zum Abbrechen): ", ae);
                    fgets(buf, BUFFERSIZE, stdin);
                    strncpy(&menuPoint, buf, 1);
                    menuPoint = tolower(menuPoint);

                    // check if user input is an allowed char
                    if(strchr(allowedChars, menuPoint) == NULL && menuPoint == '\0'){
                        // TODO: an printErrorMessage schicken, wenn diese geschrieben ist
                        printf("Falsche Eingabe!\n");
                    }
                } while (((strlen(buffer)-1)>1 || strchr(allowedChars, menuPoint) == NULL) && menuPoint == '\0');

                // if user chose a number and did not hit ENTER
                if(menuPoint != '\n'){
                    printf("\n");
                    // run the corresponding function with a pointer to the chosen book
                    // TODO: add feedback to the user that the action was performed
                    switch(menuPoint){
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
                } else{
                    // TODO: isUserInputAborted einbauen?
                    printf("Abbrechen...\n");
                }
            } else{
                // TODO: isUserInputAborted einbauen?
                printf("Abbrechen...\n");
            }

            freeTempString(userInput);

//            showReturnToMenu();
        } else{
            // TODO: in printErrorMessage-function einbauen
            printf("Keine B%ccher mit '%s' gefunden\n", ue, searchString);
            // call itself again to search again
            searchBooks(books);
        }
    } else{
        printf("Abbrechen...\n");
    }

    // free searchString allocation
    freeTempString(searchString);
}
