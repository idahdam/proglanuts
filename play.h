#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#define BARIS 4
#define KOLOM 4  
#define ANGKA_MAX 15
#define ANGKA_MIN 1
#define BANYAK_ANGKA 15

void setupMatrix();
void randomizeElements();
void setMainMatrixElements();
void printWholeMainGame();
void pressStartOrEscape();
bool checkIfAbleToMove(int X, int Y, char input);

int arrayMatrix[BARIS][KOLOM], arr[BANYAK_ANGKA];
int globalX = 3, globalY = 3;

void startFunc(){
    randomizeElements();
    setMainMatrixElements();
    printWholeMainGame();
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

void printWholeMainGame(){
    int i, j, move = 0;
    char movement;
    bool gameLoop = true;
    pressStartOrEscape();
    while(gameLoop){
        system("cls");
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

        printf("Move You Take:  %d\n", move);
        printf("Where would you like to move? up/left/right/down: ");
        scanf("%c", &movement);
        switch (movement){
        case 'w':
            /* code */
            printf("You pressed up.");
            Sleep(1000);
            move++;
            break;
        case 'a':
            printf("You pressed left.");
            Sleep(1000);
            move++;
            break;
        case 's':
            printf("You pressed down.");
            Sleep(1000);
            move++;
            break;
        case 'd':
            printf("You pressed right.");
            Sleep(1000);
            move++;
            break;
        case 'k':
            gameLoop = false;
            break;
        default:
            printf("Not a valid input.");
            Sleep(2000);
        }
    }

    printf("Break while loop");
    Sleep(2000);
}

void pressStartOrEscape(){
    int i, j;
    printf("=====================================\n");

    for(i = 0; i < BARIS; i++){
            for(j = 0; j < KOLOM; j++){
                if(j == 2 && i == 2){
                        printf("========Press Enter To Start========\n");
                }
            }
            if(i >= 0 && i < BARIS - 1){
                //printf("\n-------------------------------------");
            }
            else{
                printf("\n=====================================\n");
            }
            printf("\n");
        }

    getch();
    
}

bool checkIfAbleToMove(int X, int Y, char input){
    // checking corners
    // bottom right
    if(Y == 3){
        if(X == 3){
            if(input == 'd' || input == 's'){
                printf("You can't move.");
                return false;
            }
            else{
                if(input == 'w'){
                    //swap
                }
                else if(input == 'a'){
                    //swap
                }
            }

        }
        else if(X == 0){
            if(input == 'a' || input == 's'){
                printf("You can't move.");
                return false;
            }
            else{
                if(input == 'w'){
                    //swap
                }
                else if(input == 'd'){
                    //swap
                }
            }
        }
    }
}