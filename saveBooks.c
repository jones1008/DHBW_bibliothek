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

void saveBooks(Bib *bib)
{
    // TODO: nur saven, wenn was verändert wurde?
    // loop over the array
    int fileSuccess = 1;
    for(int i=0; i<bib->used; i++){
//        printf("isbn  : %s\n", bib->array[i].isbn);
//        printf("title : %s\n", bib->array[i].title);
//        printf("author: %s\n", bib->array[i].author);
//        printf("anzahl: %s\n", bib->array[i].numberof);
//        printf("borrow: %s\n", bib->array[i].borrowlist);
        // skip line, if book was deleted
        if(!(bib->array[i].isbn == NULL && bib->array[i].title == NULL && bib->array[i].author == NULL && bib->array[i].numberof == NULL && bib->array[i].borrowlist == NULL)){
            // get length of the line and allocate the memory for the line
            int lineSize = 5+strlen(bib->array[i].isbn)+strlen(bib->array[i].title)+strlen(bib->array[i].author)+strlen(bib->array[i].numberof)+strlen(bib->array[i].borrowlist);
    //        printf("lineSize: %d\n", lineSize);
            char *line = malloc(lineSize*sizeof(char));
    //        printf("after malloc\n");
    //        // write all entries of array into line variable
            snprintf(line, lineSize, "%s;%s;%s;%s;%s\n", bib->array[i].isbn, bib->array[i].title, bib->array[i].author, bib->array[i].numberof, bib->array[i].borrowlist);
    //        printf("line: %s", line);
    //        // write first line and append the following lines
            FILE *dataFile;
            if(i==0){
                dataFile = fopen("data.csv", "w");
            } else{
                dataFile = fopen("data.csv", "a");
            }
            // TODO: skip line if it is the same as before (only write new lines)
            if(dataFile == NULL){
                printf("Problem beim Öffnen der Datenbank-Datei: %s\n", strerror(errno));
                fileSuccess = 0;

                fclose(dataFile);
                break;
            }
    //        printf("before printing into file");
            fprintf(dataFile, "%s\n", line);
    //        printf("after printing into file");
            fclose(dataFile);
            freeTempString(line);
        }
    }
    if(fileSuccess){
        printf("Erfolgreich gespeichert!\n");
    }
}
