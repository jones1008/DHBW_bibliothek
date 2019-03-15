#include "deleteBooks.h"

void deleteBooks(Bib *bib)
{
    char searchString[BUFFERSIZE];
    printf("Welches Buch soll gel%cscht werden? (Titel, Autor, ISBN) ([ENTER] zum Abbrechen): ", oe);
    // get user search, search for it and print the results
    getUserInput(searchString);
    if(!isAborted(searchString)){
        foundBooks foundBooks;
        search(bib, &foundBooks, searchString);
        showFoundBooks(&foundBooks, "atin");

        // if only one result choose this book automatically
        if(foundBooks.size>1){
            // let the user choose a book
            int chosenBook = 0;
            int isNotAborted;
            chooseBook(&foundBooks, &chosenBook, &isNotAborted);

            if(isNotAborted){
                chosenBook--;
                printf("---> gew%chltes Buch: [%d] - %s - %s\n", ae, chosenBook+1, foundBooks.books[chosenBook]->author, foundBooks.books[chosenBook]->title);
    //            printf("chosenbook pointer: %d\n", **foundBooks.books[chosenBook]);
                actualDeleteBooks(bib, foundBooks.books[chosenBook], chosenBook);
    //            printf("nach actualDeleteBooks: book->numberof: %s\n", bib->books[5].numberof);
            }
        } else if(foundBooks.size == 1){
            printf("---> gew%chltes Buch: [%d] - %s - %s\n", ae, 1, foundBooks.books[0]->author, foundBooks.books[0]->title);
            actualDeleteBooks(bib, foundBooks.books[0], 1);
        }
        freeFoundBooks(&foundBooks);
    }
}

void actualDeleteBooks(Bib *bib, book *book, int chosenBook)
{
    // TODO: Success-Meldung: Ausleihe wurde erfolgreich eingetragen
//    printf("author: %s\n", book->author);
    char deleteCountString[BUFFERSIZE];
    int deleteCount;
    int numberof = atoi(book->numberof);
    int isNotAborted;
    // repeat input if deleteCount is not a number or above numberof
    do{
        printf("Anzahl zu l%cschender Exemplare ([ENTER] zum Abbrechen): ", oe);
        getUserInput(deleteCountString);
        isNotAborted = !isAborted(deleteCountString);
        if(isNotAborted){
            deleteCount = atoi(deleteCountString);

            // if number out of allowed area was chosen
            if(deleteCount<=0 || deleteCount>numberof){
                printf("ERROR: Falsche Eingabe oder eingegebene Zahl au%cerhalb des Index!\n", ss);
            }
        }
    } while(isNotAborted && (deleteCount<=0 || deleteCount>numberof));

    if(isNotAborted){
        // lower the number of if deleteCount is lower than the existing copies, else delete book entry completely
        if(deleteCount<numberof){
            int newNumberof = numberof-deleteCount;
            char newNumberofString[12];
            sprintf(newNumberofString, "%d", newNumberof);
//            printf("last char of newString: %d\n", newNumberofString[strlen(newNumberofString)]);
//            newNumberofString[strlen(newNumberofString)] = '\0';
//            printf("newNumberofString: %s\n", newNumberofString);
            book->numberof = newNumberofString;
        } else{
            // TODO: in array steht falscher wert nach dem Ändern (siehe printfs in main() vor und nach getUserInput
            // TODO: Buch aus der Mitte komplett rauslöschen und danach Verhalten überprüfen, wenn interaktionen mit Büchern danach ausgeführt werden

            // ask user if he wants is sure to delete the complete book
            char choice[BUFFERSIZE];
            char *allowedChars = "jn";
            do{
                printf("Wirklich das Buch komplett l%cschen? [J][N]: ", oe);
                getUserInput(choice);
                *choice = tolower(*choice);
            } while(wrongCharInput(choice, allowedChars));

            if(choice[0] == 'j'){
                // delete book completely
                book->isbn = NULL;
                book->author = NULL;
                book->title = NULL;
                book->numberof = NULL;
                book->borrowlist = NULL;
            } else if(choice[0] == 'n'){
                // set isNotAborted to 0, so it won't save
                isNotAborted = 0;
                // show "Abbrechen"
                isAborted("");
            }
        }
        if(isNotAborted){
//            printf("vor dem Speichern: book->numberof: %s\n", bib->books[5].numberof);
            saveBooks(bib);
//            printf("nach dem Speichern: book->numberof: %s\n", bib->books[5].numberof);
        }
    }
}
