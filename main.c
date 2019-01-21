#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>

#define AE (unsigned char)142
#define ae (unsigned char)132
#define OE (unsigned char)153
#define oe (unsigned char)148
#define UE (unsigned char)154
#define ue (unsigned char)129
#define ss (unsigned char)225

void searchBook(){
    printf("searchBook\n");
}
void borrowBook(){
    printf("borrowBook\n");
}
void returnBook(){
    printf("returnBook\n");
}
void addBook(){
    printf("newBook\n");
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
    printf("deleteBook\n");
}

void showMenu(){
    char menuPoint;
    printf("[S]: B%ccher suchen\n", ue);
    printf("[A]: Buch ausleihen\n");
    printf("[Z]: Buch zur%cckgeben\n", ue);
    printf("[H]: Buch hinzuf%cgen\n", ue);
    printf("[L]: Buch l%cschen\n", oe);
    printf("[E]: Bibliotheksverwaltung verlassen\n");
    printf("Aktion w%chlen: ", ae);
    scanf(" %c", &menuPoint);
    menuPoint = tolower(menuPoint);
    //printf("%c\n", menuPoint);
    printf("\n");
    switch(menuPoint){
        case 's':
            searchBook();
            break;
        case 'a':
            borrowBook();
            break;
        case 'z':
            returnBook();
            break;
        case 'h':
            addBook();
            break;
        case 'l':
            deleteBook();
            break;
        case 'e':
            printf("Schlie%ce Bibliothek...", ss);
            exit(0);
            break;
        default:
            printf("Falsche Eingabe!\n");
            break;
    }
    printf("\n");
    showMenu();
}
void showHeading(){
    printf(" _______  ___   _______  ___      ___   _______  _______  __   __  _______  ___   _ \n|  _    ||   | |  _    ||   |    |   | |       ||       ||  | |  ||       ||   | | |\n| |_|   ||   | | |_|   ||   |    |   | |   _   ||_     _||  |_|  ||    ___||   |_| |\n|       ||   | |       ||   |    |   | |  | |  |  |   |  |       ||   |___ |      _|\n|  _   | |   | |  _   | |   |___ |   | |  |_|  |  |   |  |       ||    ___||     |_ \n| |_|   ||   | | |_|   ||       ||   | |       |  |   |  |   _   ||   |___ |    _  |\n|_______||___| |_______||_______||___| |_______|  |___|  |__| |__||_______||___| |_|\n\n");
}
int main()
{
    showHeading();
    showMenu();
}
