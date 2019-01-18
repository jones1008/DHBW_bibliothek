#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>

void searchBook(){
}
void borrowBook(){
}
void givebackBook(){
}
void addBook(){
    // add a new copy of an existing book
}
void newBook(){
    // initialize variables
    char isbn[256], newisbn[256], bookTitle[256], bookAuthor[256];
    int bookCount;

    // get ISBN number
    printf("ISBN-Nummer eingeben: ");
    fgets(isbn, sizeof(isbn), stdin);
    printf("\n");

    // get book title
    printf("Buch-Titel eingeben: ");
    fgets(bookTitle, sizeof(bookTitle), stdin);
    printf("\n");

    // get book author
    printf("Buch-Autor eingeben: ");
    fgets(bookAuthor, sizeof(bookAuthor), stdin);
    printf("\n");

    // get number of copies
    printf("Anzahl Exemplare eingeben: ");
    scanf("%d", &bookCount);
    printf("\n");

    // delete all other characters not being a digit from isbn
    int j=0;
    for(int i=0; i<strlen(isbn); i++){
        if(isdigit(isbn[i])){
            newisbn[j] = isbn[i];
            j++;
        }
    }
    printf("%s", newisbn);
    printf("%s", bookTitle);
    printf("%s", bookAuthor);
    printf("%d", bookCount);
}
void deleteBook(){
}

int main()
{
    newBook();
}
