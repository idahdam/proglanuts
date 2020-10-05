#include <stdio.h>

#include "result.h"

#define MAXCHAR 1000

int main() {
    enterScore(3);
    FILE *fp;
    char str[MAXCHAR];
    char* filename = "savefile.txt";
 
    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }
    while (fgets(str, MAXCHAR, fp) != NULL)
        printf("%s", str);
    fclose(fp);
    return 0;
}