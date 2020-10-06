#include "selfHeader.h"

int number = 1;

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

void enterScore(int score, int minutes, int seconds){
    FILE *fp;
    char nama[3];
    int i;
    fp = fopen("savefile.txt", "a");
    printf("Masukkan 3 huruf inisialmu: ");
    scanf("%s", &nama);
    fprintf(fp, "%s \t %d \t %d:%d\n", nama, score, minutes, seconds);
	fclose(fp);
}

void showScore(){
    FILE *fp;
    char str[MAXCHAR];
    char filename[] = "savefile.txt";
    system("cls");
	number = 1;
    fp = fopen(filename, "r");
    if (fp == NULL){
        // printf("Could not open file %s", filename);
        // return 1;
        printf("Scoreboard is empty.\n");
    }
    else{
    	printf("\t\tScoreBoard\t\t\n");
    	printf("No. \t Name \t Move \t Minutes:Seconds\n\n");
	}
	
    while (fgets(str, MAXCHAR, fp) != NULL){
		printf("%d \t %s", number, str);
        number++;
	}

    fclose(fp);
    printf("\n\nEnter to go to main.");
    getch();
}
