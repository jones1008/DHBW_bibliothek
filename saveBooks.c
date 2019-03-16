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

/*
 *  function:
 *      Converts the bib structure into a string (line) and writes them to the data.csv to save the current bib-structure
 *  params:
 *      Bib *bib
 */
void saveBooks(Bib *bib)
{
    // loop over the array
    int fileSuccess = 1;
    for(int i=0; i<bib->used; i++){
        printf("isbn  : %s\n", bib->books[i].isbn);
        printf("title : %s\n", bib->books[i].title);
        printf("author: %s\n", bib->books[i].author);
        printf("anzahl: %s\n", bib->books[i].numberof);
        printf("borrow: %s\n", bib->books[i].borrowlist);
        // skip line, if book was deleted
        if(!(bib->books[i].isbn == NULL && bib->books[i].title == NULL && bib->books[i].author == NULL && bib->books[i].numberof == NULL && bib->books[i].borrowlist == NULL)){
//            printf("in if\n");
            // get length of the line and allocate the memory for the line
            int lineSize = 6+strlen(bib->books[i].isbn)+strlen(bib->books[i].title)+strlen(bib->books[i].author)+strlen(bib->books[i].numberof)+strlen(bib->books[i].borrowlist);
//            printf("lineSize: %d\n", lineSize);
            char line[lineSize];
//            strncpy(line, )
//            char *line = (char*) malloc(lineSize*sizeof(char));
//            printf("after malloc\n");
    //        // write all entries of array into line variable
//            printf("bib->books[i].isbn: %s\n", bib->books[i].isbn);
//            sprintf(line, "%s;%s;%s;%s;%s\n", bib->books[i].isbn, bib->books[i].title, bib->books[i].author, bib->books[i].numberof, bib->books[i].borrowlist);
            snprintf(line, lineSize, "%s;%s;%s;%s;%s\n", bib->books[i].isbn, bib->books[i].title, bib->books[i].author, bib->books[i].numberof, bib->books[i].borrowlist);
            printf("line: %s\n", line);
    //        // write first line and append the following lines
            FILE *dataFile;
            printf("before opening file\n");
            if(i==0){
                printf("first time\n");
                dataFile = fopen("data.csv", "w");
            } else{
                printf("after first time\n");
                dataFile = fopen("data.csv", "a");
            }
            printf("before checking if NULL\n");
            if(dataFile == NULL){
                printf("error!");
                printf("Problem beim Öffnen der Datenbank-Datei: %s\n", strerror(errno));
                fileSuccess = 0;

                fclose(dataFile);
                break;
            } else{
                printf("line: %s\n", line);
                printf("before printing into file\n");
                fprintf(dataFile, "%s", line);
                printf("after printing into file\n");
            }
            fclose(dataFile);
//            freeTempString(line);
        }
    }
    if(fileSuccess){
        printf("Datenbank erfolgreich aktualisiert!\n");
    }
}
