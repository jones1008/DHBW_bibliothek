#include "searchBooks.h"

void searchBooks(Array *books)
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
//    printf("isAborted: %d\n", isAborted(searchString));
    if(!isAborted(searchString)){
        // pass searchString to the search-function
        foundBooks foundBooks;
//        printf("before search\n");
        search(books, &foundBooks, searchString);
//        printf("after search\n");

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
            char userNumber[BUFFERSIZE];
            int isNotAborted;
            chooseBook(userNumber, &foundBooks, &chosenBook, &isNotAborted);

//            do{
//                printf("Buch w%chlen [NUMMER] ([ENTER] zum Abbrechen): ", ae);
//                getUserInput(userNumber);
//                chosenBook = atoi(userNumber);
//
//                // if number out of index was chosen
//                if(chosenBook<=0 || chosenBook>foundBooks.size){
//                    printf("ERROR: Falsche Eingabe oder eingegebene Zahl au%cerhalb des Index!\n", ss);
//                }
//
//                // check for Abortion through user (pressed ENTER)
//                isNotAborted = !isAborted(userNumber);
//
//                printf("isNotAborted: %d\n", isNotAborted);
//
////            } while((chosenBook<=0 || chosenBook>foundBooks.size) && chosenBook != '\0');
//            } while(isNotAborted && (chosenBook<=0 || chosenBook>foundBooks.size));

            // when a number was chosen: ask user what he wants to do with that book
            if(isNotAborted) {
                printf("---> gew%chltes Buch: [%d] - %s - %s\n", ae, chosenBook, foundBooks.array[chosenBook-1]->author, foundBooks.array[chosenBook-1]->title);

                char *allowedChars = "azlc";
                char userChar[BUFFERSIZE];
                int isNotAborted;

                printf("[A]: Buch ausleihen\n");
                printf("[Z]: Buch zur%cckgeben\n", ue);
                printf("[L]: Buch l%cschen\n", oe);
                printf("[C]: Buchexemplar hinzuf%cgen\n", ue);

                // repeat user input if the input was wrong or not Aborted
                do{
                    // get user input and write tolower-variable so comparison is
                    printf("Aktion w%chlen ([ENTER] zum Abbrechen): ", ae);
                    getUserInput(userChar);
                    *userChar = tolower(*userChar);

//                    verifyCharInput(userChar, allowedChars);

                    // check for Abortion through user (pressed ENTER)
                    isNotAborted = !isAborted(userChar);

                } while(isNotAborted && wrongCharInput(userChar, allowedChars));

                // if user chose a number and did not hit ENTER
                if(isNotAborted){
                    printf("\n");
                    // run the corresponding function with a pointer to the chosen book
                    // TODO: add feedback to the user that the action was performed
                    switch(userChar[0]){
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
//                freeTempString(userChar);
            }
//            freeTempString(userNumber);
        } else{
            searchBooks(books);
        }
    }
//    freeTempString(searchString);
//    printf("end of searchBooks()\n");
}
