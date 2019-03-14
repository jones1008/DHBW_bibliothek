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
            if(isNotAborted){
                actualReturnBook(bib, foundBooks.books[chosenBook]);
            }
        } else if(foundBooks.size == 1){
            actualReturnBook(bib, foundBooks.books[0]);
        }
    }
}
//void newBorrower(foundBorrowers *foundBorrowers)
//{
//    foundBorrowers->size = foundBorrowers->size+1;
//    foundBorrowers->borrowers = realloc(foundBorrowers->borrowers, foundBorrowers->size*sizeof(borrower));
//}

void actualReturnBook(Bib *bib, book *book)
{
    // TODO: convert umlaute beim Suchen
    // TODO: show errormessage if borrowlist empty
    // TODO: testen!!! ist bisher ungetestet

    char name[BUFFERSIZE];
    printf("Titel    : %s\n", book->title);
    printf("Autor    : %s\n", book->author);
    printf("Ausleiher: %s\n", book->borrowlist);

    int isNotAborted;
//    char *namePointer = NULL;
    do{
        printf("Name Zur%cckgebender ([ENTER] zum Abbrechen): ", ue);
        getUserInput(name);
        isNotAborted = !isAborted(name);
        if(isNotAborted){
            // remove commas from user input
            removeChar(name, ',');
//            stringToLower(name);
            char delimiter[] = ",";

//            foundBorrowers foundBorrowers;
//            foundBorrowers.borrowers = malloc(0);
//            foundBorrowers.size = 0;
            // TODO: evtl in function?
            // create copy to work with
            char borrowListCopy[strlen(book->borrowlist)];
            strncpy(borrowListCopy, book->borrowlist, strlen(book->borrowlist));
            borrowListCopy[strlen(book->borrowlist)] = '\0';

            int i=0;
            char *ptr = strtok(borrowListCopy, delimiter);
            while(ptr != NULL){
                // copy ptr
//                char borrower[strlen(ptr)];
//                strncpy(borrower, ptr, strlen(ptr));
//                borrower[strlen(ptr)] = '\0';
//                stringToLower(borrower);
                char *newPtr = trimwhitespace(ptr);
                printf("newPtr: %s\n", newPtr);
                printf("strlen(newPtr): %d\n", strlen(newPtr));
                printf("name: %s\n", name);
                printf("strlen(name): %d\n", strlen(name));
                if(newPtr == name){
                    // TODO: get string from ptr to next comma or \0
                    printf("FOUND: %s\n", ptr);
                    // TODO: ask user if he wants to remove this borrower

                    break;
                    // add ptr to ptrarray
//                    newBorrower(&foundBorrowers);
//                    foundBorrowers.borrowers[i] = &ptr;
                }
                ptr = strtok(NULL, delimiter);
                i++;
            }

            printf("index: %d\n", ptr-borrowListCopy);
            borrowListCopy[ptr-borrowListCopy] = '\0';
            printf("borrowListCopy: %s\n", borrowListCopy);

//            for(int j=0; j<foundBorrowers.size; j++){
//                printf("borrower: %s", foundBorrowers.borrowers[j]);
//                // ask user which one to choose
//            }

            // copy borrowlist to newBorrowList
//            printf("strlen(book->borrowlist): %d\n", strlen(book->borrowlist));

//            char newBorrowList[strlen(book->borrowlist)];
//            strncpy(newBorrowList, book->borrowlist, strlen(book->borrowlist));
//            newBorrowList[strlen(book->borrowlist)] = '\0';
//            printf("newBorrowList: %s\n", newBorrowList);

            // TODO: in function? copyString()? (überall, wo strncpy verwendet wird
            // create lowercase copy to compare string
//            char borrowListCompareCopy[strlen(book->borrowlist)];
//            strncpy(borrowListCompareCopy, book->borrowlist, strlen(book->borrowlist));
//            borrowListCompareCopy[strlen(book->borrowlist)] = '\0';
//            stringToLower(borrowListCompareCopy);
//            stringToLower(name);
//            namePointer = strstr(borrowListCompareCopy, name);

            // create copy to work with
//            char borrowListCopy[strlen(book->borrowlist)];
//            strncpy(borrowListCopy, book->borrowlist, strlen(book->borrowlist));
//            borrowListCopy[strlen(book->borrowlist)] = '\0';

//            printf("borrowListCopy: %s\n", borrowListCopy);
            // check if name occurs in borrowlist
//            if(namePointer != NULL){
                // TODO: doesnt work yet for people to be the first one
                // find the first comma occurence or start of string before namePointer and take this pointer then to cut the string
//                while(namePointer != borrowListCompareCopy && namePointer[0] != ','){
//                    printf("namePointer:%s\n", namePointer);
////                    printf("namePointerChar:%c\n", namePointer[0]);
//                    namePointer--;
//                }
//                printf("namePointer:%s\n", namePointer);
////                borrowListCopy[namePointer-borrowListCompareCopy] = '\0';
////                printf("borrowlistCopy: %s\n", borrowListCopy);
//                // copy first part to newBorrowList
//                int index = namePointer-borrowListCompareCopy;
//                printf("index: %d\n", index);
//                if(index != 0){
//                    printf("is not null\n");
//                    strncpy(newBorrowList, borrowListCopy, index);
//                    newBorrowList[index] = '\0';
//                } else{
//                    newBorrowList[0] = '\0';
//                }
////                borrowListCopy[namePointer-borrowListCompareCopy] = ',';
//
//                printf("after finding first comma: %s\n", newBorrowList);
//
//                namePointer++;
//                // TODO: find next comma occurence or end of string after namePointer
//                while(namePointer[0] != '\0' && namePointer[0] != ','){
//                    printf("namePointer: %s\n", namePointer);
//                    namePointer++;
//                }
//                printf("namePointer: %s\n", namePointer);
//                // ad the last part to newBorrowList
////                borrowListCopy[namePointer-borrowListCompareCopy] = '\0';
//                printf("borrowlistCopy: %s\n", borrowListCopy);
//                int index2 = namePointer-borrowListCompareCopy+2;
//                printf("index2: %d\n", index2);
//                printf("borrowListCopy[index2]: %c\n", borrowListCopy[index2]);
////                if(index2 != 0){
////                    printf("is not 0\n");
////                    strcat(newBorrowList, &borrowListCopy[index2+2]);
////                } else{
//                    strcat(newBorrowList, &borrowListCopy[index2]);
////                }
//                printf("newBorrowList: %s\n", newBorrowList);


                // TODO: get substring from "',' or start of string" to "next ',' or end of string" (wenn zu schwer: dann einfach nur rauslöschen, ohne Überprüfung und User Nachfrage und danach unnötige spaces und Kommas rauslöschen)
                // TODO: ask user if he really wants to remove X
                // TODO: remove name from book->borrowlist

//                saveBooks(bib);
//            } else{
//                printf("ERROR: Name '%s' in Ausleihliste nicht gefunden!\n", name);
//            }
        }
    } while(isNotAborted);
}
