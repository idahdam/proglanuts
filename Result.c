#include "selfHeader.h"

void printWin(){
    system("cls");
    printf("WIN");
    printf("WIN");
    printf("WIN");
    printf("WIN");
    printf("WIN");
    printf("WIN");
    printf("WIN");
    printf("WIN");
    printf("WIN");
    printf("WIN");
    printf("WIN");
    printf("WIN");
    printf("WIN");
    printf("WIN");
    printf("WIN");
    printf("WIN");
    printf("WIN");
    printf("WIN");
    printf("WIN");
    printf("WIN");
    printf("WIN");
    printf("WIN");
    printf("WIN");
    printf("WIN");
    printf("WIN");
    Sleep(3000);
    system("cls");
}

void printLose(){
    system("cls");
    printf("LOSE");
    printf("LOSE");
    printf("LOSE");
    printf("LOSE");
    printf("LOSE");
    printf("LOSE");
    printf("LOSE");
    printf("LOSE");
    printf("LOSE");
    printf("LOSE");
    printf("LOSE");
    printf("LOSE");
    printf("LOSE");
    printf("LOSE");
    printf("LOSE");
    printf("LOSE");
    printf("LOSE");
    printf("LOSE");
    printf("LOSE");
    Sleep(3000);
    system("cls");
}

void enterScore(int score){
    FILE *fp;
    char nama[50];
    int i;
    fp = fopen("savefile.txt", "w");
    printf("Masukkan namamu: ");
    scanf("%s", &nama);
    fprintf(fp, "%s - %d", nama, score);
    fclose(fp);
}

void showScore(){
    FILE *fp;
    char str[MAXCHAR];
    char filename[] = "savefile.txt";
    
    printf("Scoreboard: ");
    fp = fopen(filename, "r");
    if (fp == NULL){
        // printf("Could not open file %s", filename);
        // return 1;
        printf("Scoreboard is empty.");
    }
    while (fgets(str, MAXCHAR, fp) != NULL)
        printf("%s", str);
    fclose(fp);
}
