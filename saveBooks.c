#include "saveBooks.h"
//void strreplace(char s[], char chr, char repl_chr)
//{
//    for(char* p=s; (p=strchr(p, chr)) != NULL; ++p){
//        printf("%c\n", repl_chr);
//        *p=repl_chr;
//    }
//}
//char *replaceUmlauts(char* string)
//{
//    strreplace(string, 'ä', (unsigned char)132);
//    strreplace(string, 'ö', (unsigned char)148);
//    strreplace(string, 'ü', (unsigned char)129);
//    strreplace(string, 'ß', (unsigned char)225);
//    strreplace(string, 'Ä', (unsigned char)142);
//    strreplace(string, 'Ö', (unsigned char)153);
//    strreplace(string, 'Ü', (unsigned char)154);
//    return string;
//}

void saveBooks(Array *books)
{
    // TODO: nur saven, wenn was verändert wurde?
    // loop over the array
    for(int i=0; i<books->used; i++){
        printf("isbn  : %s\n", books->array[i].isbn);
        printf("title : %s\n", books->array[i].title);
        printf("author: %s\n", books->array[i].author);
        printf("anzahl: %s\n", books->array[i].numberof);
        printf("borrow: %s\n", books->array[i].borrowlist);
        // get length of the line and allocate the memory for the line
        int lineSize = strlen(books->array[i].isbn)+strlen(books->array[i].title)+strlen(books->array[i].author)+strlen(books->array[i].numberof)+strlen(books->array[i].borrowlist);
        char *line = calloc(lineSize+5, lineSize+5);
        // write all entries of array into line variable
        snprintf(line, lineSize+5, "%s;%s;%s;%s;%s\n", books->array[i].isbn, books->array[i].title, books->array[i].author, books->array[i].numberof, books->array[i].borrowlist);
        // write first line and append the following lines
        FILE *dataFile;
        if(i==0){
            dataFile = fopen("data.csv", "w");
        } else{
            dataFile = fopen("data.csv", "a");
        }
        // TODO: Fehlermeldung, wenn Datei nicht geöffnet werden kann!
        fprintf(dataFile, "%s\n", line);
        fclose(dataFile);
        freeTempString(line);
    }
}
