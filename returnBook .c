#include "returnBook.h"
void returnBook(Array *books)
{
    char searchString[BUFFERSIZE];
    printf("Welches Buch soll zurückgegeben werden? (Titel, Autor, ISBN) ([ENTER] zum Abbrechen): ");
    // get user search, search for it and print the results
    getUserInput(searchString);
    if(!isAborted(searchString)){
        // TODO: evtl in function (wird auch in delte und borrowBooks verwendet)
        foundBooks foundBooks;
        search(books, &foundBooks, searchString);
        showFoundBooks(&foundBooks, "atib");

        // let the user choose a book
        int chosenBook = 0;
        int isNotAborted;
        chooseBook(&foundBooks, &chosenBook, &isNotAborted);
        if(isNotAborted){
            // TODO: rausfinden, wie man hier auf das gewählte Buch kommt (PointerPointer)
            printf("chosenBook: %d\n", chosenBook);
//            printf("chosenbook isbn: %d\n", *foundBooks.array[chosenBook]);


//            printf("pointer to chosenBook: %s\n", foundBooks.array[chosenBook]->author);
//            actualReturnBook(books, &foundBooks.array[chosenBook]);
        }
    }
}

void actualReturnBook(Array *books, book *book)
{
    // TODO: testen!!! ist bisher ungetestet

//    char name[BUFFERSIZE];
//    printf("Aktuelle Ausleiher des Buchs: %s\n", book->borrowlist);
//
//    int isNotAborted;
//    char *namePointer = NULL;
//    do{
//        printf("Name Zurückgebender ([ENTER] zum Abbrechen): \n");
//        getUserInput(name);
//        isNotAborted = !isAborted(name);
//        if(isNotAborted){
//            // remove commas from user input
//            removeChar(name, ',');
//
//            // copy borrowlist to newBorrowList
//            char newBorrowList[strlen(book->borrowlist)+1];
//            strncpy(book->borrowlist, newBorrowList, strlen(book->borrowlist));
//            newBorrowList[strlen(book->borrowlist)-1] = '\0';
//
//            namePointer = strstr(newBorrowList, name);
//            // check if name occurs in borrowlist
//            if(namePointer != NULL){
//
//                // TODO: get substring from "',' or start of string" to "next ',' or end of string" (wenn zu schwer: dann einfach nur rauslöschen, ohne Überprüfung und User Nachfrage und danach unnötige spaces und Kommas rauslöschen)
//                // TODO: ask user if he really wants to remove X
//                // TODO: remove name from book->borrowlist
//
////                saveBooks(books);
//            } else{
//                printf("ERROR: Name '%s' in Ausleihliste nicht gefunden!\n");
//            }
//        }
//    } while(isNotAborted && namePointer == NULL);
}
