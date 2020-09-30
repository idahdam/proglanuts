// Track me 

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define BARIS 4
#define KOLOM 4  
#define ANGKA_MAX 15
#define ANGKA_MIN 1
#define BANYAK_ANGKA 15

void setupMatrix();
void randomizeElements();
void setMainMatrixElements();
void printMatrixToScreen();

int arrayMatrix[BARIS][KOLOM], arr[BANYAK_ANGKA];

void startFunc(){
    randomizeElements();
    setMainMatrixElements();
    printMatrixToScreen();
}

void randomizeElements(){
    int get, c, i, j, k =0, chk, x;
    c = i = 0;
    srand(time(NULL)); // this will ensure that every time, program will generate different set of numbers. If you remove this, same set of numbers will generated every time you run the program.
    while(c < ANGKA_MAX)
    {
        get = ((rand() % (ANGKA_MAX-ANGKA_MIN+1)) + ANGKA_MIN); // generate random number.
        //After generating that number check if it is already in array.
        for(i=0; i<=c; i++)
        {
            if(arr[i] == get)
            {
                chk = 0;
                break;
            }
            else if(arr[i] != get)
            {
                chk = 1;
            }
        }
        if(chk==1)
        {
            arr[c]=get;
            //printf("%d\n",arr[c]);
            c++;
        }
    }
}

void setMainMatrixElements(){
    int i, j, k = 0;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            if(j == 3 && i == 3){
                arrayMatrix[i][j] = 0;
            }
            arrayMatrix[i][j] = arr[k];
            k++;
        }  
    }
}

void printMatrixToScreen(){
    int i, j;
    printf("=====================================\n");
    for(i = 0; i < BARIS; i++){
        for(j = 0; j < KOLOM; j++){
            if(j == 0){
                printf("|| %-5d||", arrayMatrix[i][j]);
            }
            // else if(j == KOLOM - 1){
            //     printf(" %-5d||", arrayMatrix[i][j]);
            // }
            else{
                printf("  %-5d||", arrayMatrix[i][j]);
            }
        }
        if(i >= 0 && i < BARIS - 1){
            printf("\n-------------------------------------");
        }
        else{
            printf("\n=====================================\n");
        }
        printf("\n");

    }
}
