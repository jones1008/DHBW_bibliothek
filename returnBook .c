#include "returnBook.h"
void returnBook(Bib *bib)
{
    char searchString[BUFFERSIZE];
    printf("Welches Buch soll zur%cckgegeben werden? (Titel, Autor, ISBN) ([ENTER] zum Abbrechen): ", ue);
    // get user search, search for it and print the results
    getUserInput(searchString);
    if(!isAborted(searchString)){
        foundBooks foundBooks;
        // TODO: repeat if foundBooks.size = 0 (auch in anderen funktionen borrowBooks and deleteBooks)
        search(bib, &foundBooks, searchString);

        // if only one result choose this book automatically
        if(foundBooks.size>1){
            // print the results and let the user choose a book
            showFoundBooks(&foundBooks, "atib");
            int chosenBook = 0;
            int isNotAborted;
            chooseBook(&foundBooks, &chosenBook, &isNotAborted);
            // decrease chosenBook since arrays start at 0
            chosenBook--;
            printf("---> gew%chltes Buch: [%d] - %s - %s\n", ae, chosenBook+1, foundBooks.books[chosenBook]->author, foundBooks.books[chosenBook]->title);

            if(isNotAborted){
                actualReturnBook(bib, foundBooks.books[chosenBook]);
            }
        } else if(foundBooks.size == 1){
            actualReturnBook(bib, foundBooks.books[0]);
        }
        freeFoundBooks(&foundBooks);
    }
}

void actualReturnBook(Bib *bib, book *book)
{
    // print error message if borrowlist is empty
    if(book->borrowlist[0] != '\0'){
        char name[BUFFERSIZE];

        printf("\n");
        printf("Titel    : %s\n", book->title);
        printf("Autor    : %s\n", book->author);
        printf("Ausleiher: %s\n", book->borrowlist);
        printf("\n");

        // repeat user input if nothing was found
        int isNotAborted;
        int firstUnmatch = 1;
        int found = 0;
        do{
            printf("Name Zur%cckgebender ([ENTER] zum Abbrechen): ", ue);
            getUserInput(name);
            isNotAborted = !isAborted(name);
            if(isNotAborted){
                // remove commas from user input
                removeChar(name, ',');
                replaceUmlauts(name);

                // initialize newBorrowList
                char *newBorrowList = malloc(strlen(book->borrowlist)*sizeof(char));
                memset(newBorrowList, 0, strlen(book->borrowlist));

                // split borrowlist into its borrowers
                char delimiter[] = ",";
                char *ptr = strtok(book->borrowlist, delimiter);

                int i=0;
                while(ptr != NULL){
                    // create a temporary copy of the current string with trimmed spaces
//                    char *tmpPtr = trimWhitespace(ptr);
                    char *tmpPtr = trim(ptr);
//                    char tmpPtr[strlen(ptr)];
//                    trimWhitespace(tmpPtr, strlen(ptr), ptr);

                    // check if current string doesn't match the user input
                    if(strcmp(tmpPtr, name) != 0){
                        // check if this is the first loop it doesn't match the user input and change what should be written to newBorrowList
                        if(firstUnmatch){
                            snprintf(newBorrowList, strlen(tmpPtr)+1, "%s", tmpPtr);
                        } else{
                            snprintf(newBorrowList, strlen(newBorrowList)+3+strlen(tmpPtr), "%s, %s", newBorrowList, tmpPtr);
                        }
                        firstUnmatch = 0;
                    } else{
                        found = 1;
                    }
                    ptr = strtok(NULL, delimiter);
                    i++;
                }

                // save new borrowlist only if something was found
                if(found){
                    book->borrowlist = newBorrowList;
                    printf("---> '%s' wurde von der Ausleihliste entfernt.\n", name);
                    saveBooks(bib);
                } else{
                    printf("ERROR: '%s' nicht in der Ausleihliste gefunden!\n", name);
                }

                freeTempString(newBorrowList);
            }
        } while(isNotAborted && !found);
    } else{
        printf("ERROR: Das gew%chlte Buch wurde bisher noch nicht ausgeliehen!\n", ae);
    }
}
