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
void moveTo(bool movement, int move);

int arrayMatrix[BARIS][KOLOM], arr[BANYAK_ANGKA];
int globalX = 3, globalY = 3, moveCounter = 0;

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
    int i, j;
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

        printf("Move You Take:  %d\n", moveCounter);
        printf("Where would you like to move? up/left/right/down: ");
        scanf("%c", &movement);
        switch (movement){
        case 'w':
            /* code */
            printf("You pressed up.");
            Sleep(1000);
            moveTo(checkIfAbleToMove(globalX, globalY, movement), movement);
            break;
        case 'a':
            printf("You pressed left.");
            Sleep(1000);
            break;
        case 's':
            printf("You pressed down.");
            Sleep(1000);
            break;
        case 'd':
            printf("You pressed right.");
            Sleep(1000);
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
    system("cls");
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
    int moveToWhere;
    // checking corners
    // last row (Y =)
    if(Y == 3){
        if(X == 3){
            if(input == 'd' || input == 's'){
                return false;
            }
            else{
                if(input == 'w'){
                    return true;
                }
                else if(input == 'a'){
                    return true;
                }
            }

        }
        else if(X == 1 || X == 2){
            if(input == 's'){
                printf("You can't move.");
                return false;
            }
            else{
                if(input == 'w'){
                    return true;
                }
                else if(input == 'd'){
                    return true;
                }
                else if(input == 'a'){
                    return true;
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
                    return true;
                }
                else if(input == 'd'){
                    return true;
                }
            }
        }
    }
    else if(Y == 2 || Y == 1){
        if(X == 3){
            if(input == 'd'){
                return false;
            }
            else{
                if(input == 'w'){
                    return true;
                }
                else if(input == 'a'){
                    return true;
                }
                else if(input == 's'){
                    return true;
                }
            }

        }
        else if(X == 1 || X == 2){
            if(input == 'a' || input == 's' || input == 'w' || input == 'd'){
                printf("You can't move.");
                return false;
            }
        }
        else if(X == 0){
            if(input == 'a'){
                printf("You can't move.");
                return false;
            }
            else{
                if(input == 'w'){
                    return true;
                }
                else if(input == 'd'){
                    return true;
                }
                else if(input == 's'){
                    return true;
                }
            }
        }
    }
    else if(Y == 0){
        if(X == 3){
            if(input == 'd' || input == 'w'){
                return false;
            }
            else{
                if(input == 'a'){
                    return true;
                }
                else if(input == 's'){
                    return true;
                }
            }

        }
        else if(X == 1 || X == 2){
            if(input == 'w'){
                printf("You can't move.");
                return false;
            }
            else if(input == 'a' || input == 's' || input == 'd'){
                return true;
            }
        }
        else if(X == 0){
            if(input == 'a' || input == 'w'){
                printf("You can't move.");
                return false;
            }
            else{
                if(input == 'd'){
                    return true;
                }
                else if(input == 's'){
                    return true;
                }
            }
        }
    }
}

void moveTo(bool movement, int move){
    int a, b, temp;
    if(movement == false){
        printf("You can't move.");
    }
    else{
        if(move == 'w'){
            a = arrayMatrix[globalY][globalX];
            b = arrayMatrix[globalY-1][globalX];

            temp = a;
            a = b;
            b = temp;

            arrayMatrix[globalY][globalX] = a;
            arrayMatrix[globalY-1][globalX] = b;

            globalY -= 1;
        }
        else if (move == 'a'){
            a = arrayMatrix[globalY][globalX];
            b = arrayMatrix[globalY][globalX-1];

            temp = a;
            a = b;
            b = temp;

            arrayMatrix[globalY][globalX] = a;
            arrayMatrix[globalY][globalX-1] = b;

            globalX-=1;
        }
        else if (move == 's'){
            a = arrayMatrix[globalY][globalX];
            b = arrayMatrix[globalY+1][globalX];

            temp = a;
            a = b;
            b = temp;

            arrayMatrix[globalY][globalX] = a;
            arrayMatrix[globalY-1][globalX] = b;  

            globalY+=1;          
        }
        else if (move == 'd'){
            a = arrayMatrix[globalY][globalX];
            b = arrayMatrix[globalY][globalX+1];

            temp = a;
            a = b;
            b = temp;

            arrayMatrix[globalY][globalX] = a;
            arrayMatrix[globalY-1][globalX] = b;   

            globalX+=1;         
        }
        printf("You've succesfully moved.");
        moveCounter++;
    }

}