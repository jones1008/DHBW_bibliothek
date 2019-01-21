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
    printf("searchBook");
}
void borrowBook(){
    printf("borrowBook");
}
void returnBook(){
    printf("returnBook");
}
void addBook(){
    // add a new copy of an existing book
    printf("addBook");
}
void newBook(){
    printf("newBook");
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

void showMenu(){
    char input;
    printf("[S]: B%ccher suchen\n", ue);
    printf("[A]: Buch ausleihen\n");
    printf("[Z]: Buch zur%cckgeben\n", ue);
    printf("[H]: Buch hinzuf%cgen\n", ue);
    printf("[L]: Buch l%cschen\n", oe);
    printf("Bitte w%chle eine Aktion von oben: ", ae);
    scanf("%c", &input);
    input = tolower(input);
    switch(input){
        case 's':
            searchBook();
            break;
        case 'a':
            addBook();
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
        default:
            printf("Falsche Eingabe!\n");
            showMenu();
            break;
    }
}

int main()
{
    showMenu();
}
