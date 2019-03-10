#include "addBook.h"
void addBook(Array *books)
{
    // TODO: ENTER zum Abbrechen
    char *isbn = calloc(1, 1);

    printf("ISBN eingeben ([ENTER] zum Abbrechen): ");
    getUserInput(isbn);

    if(!isAborted(isbn)){
        char *title = calloc(1, 1);
        printf("Titel eingeben ([ENTER] zum Abbrechen): ");
        getUserInput(title);
        // TODO: verify isbn-pattern (repeat while wrong)

        if(!isAborted(title)){
            char *author = calloc(1, 1);
            printf("Autor eingeben ([ENTER] zum Abbrechen): ");
            getUserInput(author);

            if(!isAborted(author)){
                char *numberOfString = calloc(1, 1);
                printf("Anzahl Exemplare eingeben ([ENTER] zum Abbrechen): ");
                getUserInput(numberOfString);

                // TODO: verify number input (repeat while wrong)
                int numberOf = atoi(numberOfString);

                if(!isAborted(numberOfString)){
                    printf("Sind die folgenden Angaben korrekt?\n");
                    printf("ISBN  : %s\n", isbn);
                    printf("Titel : %s\n", title);
                    printf("Autor : %s\n", author);
                    printf("Anzahl: %d\n", numberOf);
                }
                freeTempString(numberOfString);
            }
            freeTempString(author);
        }
        freeTempString(title);
    }
    freeTempString(isbn);

//    while(!isUserInputAborted(isbn, "ISBN eingeben ([ENTER] Abbrechen):") &&
//          !isUserInputAborted(title, "Buchtitel eingeben ([ENTER] Abbrechen):") &&
//          !isUserInputAborted(author, "Buchautor eingeben ([ENTER] Abbrechen):") &&
//          !isUserInputAborted(numberofString, "Anzahl Exemplare eingeben ([ENTER] Abbrechen):")){
//
//        int numberof = atoi(numberofString);
//
//        // TODO: ISBN Logik einfügen
//        printf("Sind die folgenden Angaben korrekt?\n");
//        printf("ISBN  : %s\n", isbn);
//        printf("Titel : %s\n", title);
//        printf("Autor : %s\n", author);
//        printf("Anzahl: %d\n", numberof);
//
//    }




//    while(!isUserInputAborted(isbn, "ISBN eingeben:"))
    // TODO: INT-Overflow checken -> zu long ändern?
    // TODO: don't allow negative numbers



//    printf("newBook\n");
    // initialize variables
//    char isbn[256], newisbn[256], bookTitle[256], bookAuthor[256];
//    int bookCount;
//
//    // get ISBN number
//    printf("ISBN-Nummer eingeben: ");
//    fgets(isbn, sizeof(isbn), stdin);
//    printf("\n");
//
//    // get book title
//    printf("Buch-Titel eingeben: ");
//    fgets(bookTitle, sizeof(bookTitle), stdin);
//    printf("\n");
//
//    // get book author
//    printf("Buch-Autor eingeben: ");
//    fgets(bookAuthor, sizeof(bookAuthor), stdin);
//    printf("\n");
//
//    // get number of copies
//    printf("Anzahl Exemplare eingeben: ");
//    scanf("%d", &bookCount);
//    printf("\n");
//
//    // delete all other characters not being a digit from isbn
//    int j=0;
//    for(int i=0; i<strlen(isbn); i++){
//        if(isdigit(isbn[i])){
//            newisbn[j] = isbn[i];
//            j++;
//        }
//    }
//    printf("%s", newisbn);
//    printf("%s", bookTitle);
//    printf("%s", bookAuthor);
//    printf("%d", bookCount);

    saveBooks(books);
}
