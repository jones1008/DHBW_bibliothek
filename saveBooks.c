#include "saveBooks.h"
void strreplace(char s[], char chr, char repl_chr)
{
    for(char* p=s; (p=strchr(p, chr)) != NULL; ++p){
        printf("%c\n", repl_chr);
        *p=repl_chr;
    }
}
char *replaceUmlauts(char* string)
{
    strreplace(string, '�', (unsigned char)132);
    strreplace(string, '�', (unsigned char)148);
    strreplace(string, '�', (unsigned char)129);
    strreplace(string, '�', (unsigned char)225);
    strreplace(string, '�', (unsigned char)142);
    strreplace(string, '�', (unsigned char)153);
    strreplace(string, '�', (unsigned char)154);
    return string;
}
void saveBooks(Array *books)
{
    //TODO: vor dem Speichern alle Umlaute zu oe, ae, ss usw. machen
}
