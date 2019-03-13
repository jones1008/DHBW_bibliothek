#include "deleteBooks.h"

void deleteBooks(Array *books)
{
    // TODO: Abfrage, wieviel gelöscht werden soll oder ob kompletter Vorrat gelöscht werden soll
    char searchString[BUFFERSIZE];
    printf("Welches Buch soll gel%cscht werden? (Titel, Autor, ISBN) ([ENTER] zum Abbrechen): ", oe);
    // get user search, search for it and print the results
    getUserInput(searchString);
    if(!isAborted(searchString)){
        foundBooks foundBooks;
        search(books, &foundBooks, searchString);
        showFoundBooks(&foundBooks, "ati");

        // let the user choose a book
        int chosenBook = 0;
        int isNotAborted;
        chooseBook(&foundBooks, &chosenBook, &isNotAborted);
        if(isNotAborted){
            // TODO: rausfinden, wie man hier auf das gewählte Buch kommt (PointerPointer)
            printf("chosenBook: %d\n", chosenBook);
//            printf("chosenbook isbn: %d\n", *(foundBooks.array[chosenBook]));
//            printf("chosenbook isbn: %d\n", foundBooks.array[chosenBook]);



//            printf("pointer to chosenBook: %s\n", foundBooks.array[chosenBook]->author);
//            actualDeleteBooks(books, &foundBooks.array[chosenBook]);
        }
    }
}

void actualDeleteBooks(Array *books, book **book)
{
//    printf("Anzahl Exemplare von %s - %s: %s\n", book->title, book->author, book->numberof);
//    char deleteCount[BUFFERSIZE];
//    int isNotAborted;
//    // repeat input if deleteCount is not a number or above numberof
//    do{
//        printf("Anzahl zu löschender Exemplare ([ENTER] zum Abbrechen): \n");
//        getUserInput(deleteCount);
//        isNotAborted = !isAborted(deleteCount);
//        if(isNotAborted){
//            deleteCount = atoi(deleteCount);
//
//            // if number out of allowed area was chosen
//            if(deleteCount<=0 || deleteCount>book->numberof){
//                printf("ERROR: Falsche Eingabe oder eingegebene Zahl au%cerhalb des Index!\n", ss);
//            }
//        }
//    } while(isNotAborted && (deleteCount<=0 || deleteCount>book->numberof));
//
//    if(isNotAborted){
//        // lower the number of if deleteCount is lower than the existing copies, else delete book entry completely
//        if(deleteCount<book->numberof){
//            book->numberof = book->numberof-deleteCount;
//        } else{
//            // TODO: test search behaviour if book was deleted completed (siehe auch saveBooks() if statement)
//
//            // ask user if he wants is sure to delete the complete book
//            char choice[BUFFERSIZE];
//            char *allowedChars = "jn";
//            do{
//                printf("Wirklich das Buch komplett löschen? [J][N]: ");
//                getUserInput(choice);
//                choice = tolower(choice);
//            } while(wrongCharInput(choice, allowedChars));
//
//            if(choice[0] == 'j'){
//                // delete book completely
//                book->isbn = NULL;
//                book->author = NULL;
//                book->title = NULL;
//                book->numberof = NULL;
//                book->borrowlist = NULL;
//            } else if(choice[0] == 'n'){
//                // set isNotAborted to 0, so it won't save
//                isNotAborted = 0;
//            }
//        }
//        if(isNotAborted){
//            saveBooks(books);
//        }
//    }
}
