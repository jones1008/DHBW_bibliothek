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

// define book-structure inside of array
typedef struct
{
    char* isbn;
    char* title;
    char* author;
    char* numberof;
    char* borrowlist;
} book;
typedef struct
{
    book *array;
    size_t used;
    size_t size;
} Array;

void loadDataToArray(Array *books)
{
    //https://codereview.stackexchange.com/questions/44649/dynamic-array-of-structs-in-c
    // initialize array
    int initialSize = 1;
    // Allocate initial space
    books->array = (book *)calloc(initialSize * sizeof(book), sizeof(int));
    books->used = 0;           // no elements used
    books->size = initialSize; // available nr of elements

    // read every line of the csv-file and write data to the array
    char buffer[1024];
    char *line, *records;
    char delimiter[] = ";";
    FILE* dataFile = fopen("datatest.csv", "r");
    while((line=fgets(buffer,sizeof(buffer),dataFile))!=NULL)
    {
        if (books->used == books->size)
        {
            books->size *= 2;
            books->array = (book *)realloc(books->array, books->size * sizeof(book));
        }
        records = strtok(line, delimiter);

        // insert isbn
        books->array[books->used].isbn = (char*)malloc(strlen(&records[0]) + 1);
        strcpy(books->array[books->used].isbn, &records[0]);
        // insert title
        books->array[books->used].title = (char*)malloc(strlen(&records[1]) + 1);
        strcpy(books->array[books->used].title, &records[1]);
        // insert author
        books->array[books->used].author = (char*)malloc(strlen(&records[2]) + 1);
        strcpy(books->array[books->used].author, &records[2]);
        // insert numberof
        books->array[books->used].numberof = (char*)malloc(strlen(&records[3]) + 1);
        strcpy(books->array[books->used].numberof, &records[3]);
        // insert borrowlist
        books->array[books->used].borrowlist = (char*)malloc(strlen(&records[4]) + 1);
        strcpy(books->array[books->used].borrowlist, &records[4]);

        books->used++;
    }
    fclose(dataFile);
}

void freeArray(Array *books)
{
    // Free all name variables of each array element first
    for(int i=0; i<books->used; i++)
    {
        free(books->array[i].isbn);
        books->array[i].isbn=NULL;
        free(books->array[i].title);
        books->array[i].title=NULL;
        free(books->array[i].author);
        books->array[i].author=NULL;
        free(books->array[i].numberof);
        books->array[i].numberof=NULL;
        free(books->array[i].borrowlist);
        books->array[i].borrowlist=NULL;
    }

    // Now free the array
    free(books->array);
    books->array = NULL;

    books->used = 0;
    books->size = 0;
}

int main()
{
    Array books;
    loadDataToArray(&books);
    // how to access the isbn for example
    printf("%s", books.array[0].isbn);

    //freeArray(&books);

    //showHeading();
    //showMenu();
}
