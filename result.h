// Defining Preprocessor
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

int score;

void printWin();
void printLost();
void enterScore(int score);
void showScore();

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
    Sleep(1000);
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
    Sleep(1000);
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

}