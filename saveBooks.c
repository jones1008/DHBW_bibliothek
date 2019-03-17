#include "saveBooks.h"

/*
 *  function:
 *      Converts the bib structure into a string (line) and writes them to the data.csv to save the current bib-structure
 *  params:
 *      Bib *bib
 */
void saveBooks(Bib *bib)
{
//    printf("before calloc\n");
    char *content = (char *)calloc(1, sizeof(char));
//    printf("after calloc\n");
    int lineSize = 0;
    for(int i=0; i<bib->used; i++){
        // content zusammenbauen
        printf("before lineSize\n");
        lineSize = 6+strlen(bib->books[i].isbn)+strlen(bib->books[i].title)+strlen(bib->books[i].author)+strlen(bib->books[i].numberof)+strlen(bib->books[i].borrowlist);
        printf("before oldPointer\n");
//        char *oldPointer = content;
        printf("before realloc %d\n", lineSize);
        content = (char *)realloc(content, (strlen(content)+lineSize)*sizeof(char));
        printf("after realloc\n");
        //free(oldPointer);
        strcat(content, bib->books[i].isbn);
        strcat(content, ";");
        strcat(content, bib->books[i].title);
        strcat(content, ";");
        strcat(content, bib->books[i].author);
        strcat(content, ";");
        strcat(content, bib->books[i].numberof);
        strcat(content, ";");
        strcat(content, bib->books[i].borrowlist);
        strcat(content, "\n");

        printf("Cont: %s\n", content);
    }

//    printf("bib-> used: %d\n", bib->used);
//    // loop over the structure
////    int fileSuccess = 1;
////    int firstTimeOpened = 1;
////    char *line = calloc(10000, 1);
////    char content[BUFFERSIZE*100];
////    char *content = calloc(1, sizeof(char));
////    printf("before memset\n");
////    memset(line, 0, 10000*sizeof(char));
//    // get size of content to allocate right amount of memory
//    int contentSize = 0;
//    for(int i=0; i<bib->used; i++){
//        contentSize = contentSize+6+strlen(bib->books[i].isbn)+strlen(bib->books[i].title)+strlen(bib->books[i].author)+strlen(bib->books[i].numberof)+strlen(bib->books[i].borrowlist);
//    }
//    printf("before calloc\n");
////    char *content = calloc(contentSize, sizeof(char));
//    printf("contentSize: %d\n", contentSize);
//    char content[contentSize];
//    printf("after calloc\n");
////    strcpy(content, "");
////    content = "";
//    content[0] = '\0';
//    printf("after strcpy\n");
//
//    for(int i=0; i<bib->used; i++){
//        printf("loop\n");
//        // skip line, if book was deleted
//        if(!(bib->books[i].isbn == NULL && bib->books[i].title == NULL && bib->books[i].author == NULL && bib->books[i].numberof == NULL && bib->books[i].borrowlist == NULL)){
//            // get length of the line and concatenate the attributes to the line
////            int lineSize = 6+strlen(bib->books[i].isbn)+strlen(bib->books[i].title)+strlen(bib->books[i].author)+strlen(bib->books[i].numberof)+strlen(bib->books[i].borrowlist);
////            char line[lineSize];
////            char line[lineSize];
////            printf("beofre realloc\n");
////            printf("strlen(content)\n")
////            memcpy(newPointer, oldPointer, sizeOfDataType * oldNum);
//            strcat(content, bib->books[i].isbn);
//            strcat(content, ";");
//            strcat(content, bib->books[i].title);
//            strcat(content, ";");
//            strcat(content, bib->books[i].author);
//            strcat(content, ";");
//            strcat(content, bib->books[i].numberof);
//            strcat(content, ";");
//            strcat(content, bib->books[i].borrowlist);
//            strcat(content, "\n");
////            if(firstTimeOpened){
////                printf("before first realloc\n");
//////                content = realloc(content, lineSize*sizeof(char));
////                printf("before first snprintf\n");
//////                snprintf(content, lineSize, "%s;%s;%s;%s;%s\n", bib->books[i].isbn, bib->books[i].title, bib->books[i].author, bib->books[i].numberof, bib->books[i].borrowlist);
////                sprintf(content, "%s;%s;%s;%s;%s\n", bib->books[i].isbn, bib->books[i].title, bib->books[i].author, bib->books[i].numberof, bib->books[i].borrowlist);
////                printf("after first snprintf\n");
////                firstTimeOpened = 0;
////            } else{
////                char line[BUFFERSIZE];
//////                snprintf(line, lineSize, "%s;%s;%s;%s;%s\n", bib->books[i].isbn, bib->books[i].title, bib->books[i].author, bib->books[i].numberof, bib->books[i].borrowlist);
////                sprintf(line, "%s;%s;%s;%s;%s\n", bib->books[i].isbn, bib->books[i].title, bib->books[i].author, bib->books[i].numberof, bib->books[i].borrowlist);
////                printf("line: %s\n", line);
//////                content = realloc(content, strlen(content)*sizeof(char)+lineSize*sizeof(char));
////                strcat(content, line);
////            }
//            printf("line: %s\n", content);
//        }
//    }
//    content[strlen(content)-1] = 0;
//    // write first line and append the following lines
//    FILE *dataFile;
////    if(firstTimeOpened){
//        dataFile = fopen("data.csv", "wt");
////        firstTimeOpened = 0;
////    } else{
////        dataFile = fopen("data.csv", "a");
////    }
//    printf("finalLine: %s\n", content);
//    if(dataFile == NULL){
//        printf("ERROR: Problem beim Öffnen der Datenbank-Datei: %s\n", strerror(errno));
////        fileSuccess = 0;
////        if(fileSuccess){
////    }
//        fclose(dataFile);
////        break;
//    } else{
//        // TODO: stürzt hier bei fprintf ab (test ob saveBooks allgemein abstürzt oder nur bei borrowbook) -> wenns tut, dann ein Video machen von allen Funktionen
//        // TODO: auch Fehler beim Ausleihen: newBorrowList ist nur letzter Buchstabe
////        printf("line: %s\n", line);
////                fflush(dataFile);
//        printf("before fwrite\n");
////        fprintf(dataFile, "%s", content);
//        fwrite(content, sizeof(char), sizeof(content), dataFile);
////        printf("before freeing content\n");
////        freeTempString(content);
//        printf("before closing file\n");
//        fclose(dataFile);
////        fwrite(content, sizeof(content), sizeof(char), dataFile);
//        printf("after closing file\n");
//
//        printf("---> Datenbank erfolgreich aktualisiert!\n");
//
//        // reload bib structure from file after saving
//        printf("before loadingBooks\n");
//        loadBooks(bib);
//    }
//    fclose(dataFile);
}
//
//#include "saveBooks.h"
////void strreplace(char s[], char chr, char repl_chr)
////{
////    for(char* p=s; (p=strchr(p, chr)) != NULL; ++p){
////        printf("%c\n", repl_chr);
////        *p=repl_chr;
////    }
////}
////char *replaceUmlauts(char* string)
////{
////    strreplace(string, 'ä', (unsigned char)132);
////    strreplace(string, 'ö', (unsigned char)148);
////    strreplace(string, 'ü', (unsigned char)129);
////    strreplace(string, 'ß', (unsigned char)225);
////    strreplace(string, 'Ä', (unsigned char)142);
////    strreplace(string, 'Ö', (unsigned char)153);
////    strreplace(string, 'Ü', (unsigned char)154);
////    return string;
////}
//
/*
// *  function:
// *      Converts the bib structure into a string (line) and writes them to the data.csv to save the current bib-structure
// *  params:
// *      Bib *bib
// */
//void saveBooks(Bib *bib)
//{
//    // loop over the array
//    int fileSuccess = 1;
//    int firstTime = 1;
//    printf("bib->used: %d", bib->used);
//    for(int i=0; i<bib->used; i++){
//        printf("isbn  : %s\n", bib->books[i].isbn);
//        printf("title : %s\n", bib->books[i].title);
//        printf("author: %s\n", bib->books[i].author);
//        printf("anzahl: %s\n", bib->books[i].numberof);
//        printf("borrow: %s\n", bib->books[i].borrowlist);
//        // skip line, if book was deleted
//        if(!(bib->books[i].isbn == NULL && bib->books[i].title == NULL && bib->books[i].author == NULL && bib->books[i].numberof == NULL && bib->books[i].borrowlist == NULL)){
////            printf("in if\n");
//            // get length of the line and allocate the memory for the line
//            int lineSize = 6+strlen(bib->books[i].isbn)+strlen(bib->books[i].title)+strlen(bib->books[i].author)+strlen(bib->books[i].numberof)+strlen(bib->books[i].borrowlist);
//            printf("lineSize: %d\n", lineSize);
//            char line[lineSize];
////            strncpy(line, )
////            char *line = (char*) malloc(lineSize*sizeof(char));
////            printf("after malloc\n");
//    //        // write all entries of array into line variable
//            printf("bib->books[i].isbn: %s\n", bib->books[i].isbn);
////            sprintf(line, "%s;%s;%s;%s;%s\n", bib->books[i].isbn, bib->books[i].title, bib->books[i].author, bib->books[i].numberof, bib->books[i].borrowlist);
//            snprintf(line, lineSize, "%s;%s;%s;%s;%s\n", bib->books[i].isbn, bib->books[i].title, bib->books[i].author, bib->books[i].numberof, bib->books[i].borrowlist);
//            printf("line: %s\n", line);
//    //        // write first line and append the following lines
//            FILE *dataFile;
//            printf("before opening file\n");
//            if(firstTime){
//                printf("first time\n");
//                dataFile = fopen("data.csv", "w");
//                firstTime = 0;
//            } else{
//                printf("after first time\n");
//                dataFile = fopen("data.csv", "a");
//            }
//            printf("before checking if NULL\n");
//            if(dataFile == NULL){
//                printf("error!");
//                printf("Problem beim Öffnen der Datenbank-Datei: %s\n", strerror(errno));
//                fileSuccess = 0;
//
//                fclose(dataFile);
//                break;
//            } else{
//                printf("line: %s\n", line);
//                printf("before printing into file\n");
//                fprintf(dataFile, "%s", line);
//                printf("after printing into file\n");
//            }
//            printf("before closing file\n");
//            fclose(dataFile);
//            printf("after closing file\n");
////            freeTempString(line);
//        }
//    }
//    if(fileSuccess){
//        printf("Datenbank erfolgreich aktualisiert!\n");
//
//        // reload bib structure from file after saving
//        loadBooks(bib);
//    } else{
//        printf("file not success\n");
//    }
//}
