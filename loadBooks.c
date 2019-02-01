#include "loadBooks.h"

loadBooks(Array *books)
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
