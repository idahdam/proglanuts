// Defining Preprocessor
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

// def kalau pake linux
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

// define constants
#define BARIS 4
#define KOLOM 4  
#define ANGKA_MAX 15
#define ANGKA_MIN 1
#define BANYAK_ANGKA 15

// declaring functions
void setupMatrix();
void randomizeElements();
void setMainMatrixElements();
void printWholeMainGame();
void pressStartOrEscape();
bool checkIfAbleToMove(int X, int Y, char input);
void moveTo(bool movement, int move);
void debugMode(int enableDebug);
void stopLoopArray(int stopTrigger);
void timerRefresh(char movement);

// declaring global variables
int arrayMatrix[BARIS][KOLOM], arr[BANYAK_ANGKA], arrayAcuan[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 0}};
int globalX = 3, globalY = 3, moveCounter = 0, debugTrigger, stopTrigger, timer = 300;
char areYouSure;

// main function in main.c will run this.
void startFunc(){
    randomizeElements();
    setMainMatrixElements();
    printWholeMainGame();
}

// this function will randomize each element on the block
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

// randomized element from randomizeElements will be moved here
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

// main interface
void printWholeMainGame(){
    int i, j, msec, rmsec;
    char areYouSure;
    char movement;
    char test = movement;
    bool gameLoop = true;
    clock_t before  = clock(), difference;
    pressStartOrEscape();

    while(gameLoop){
        TIMER:
        system("cls");
        difference = clock() - before;
        msec = difference * 1000/CLOCKS_PER_SEC;
        rmsec = 300 - msec/1000;
        printf("timer: %d\n\n", rmsec);
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


        // Sleep(1000);

        printf("\nMove You Take:  %d\n", moveCounter);
        printf("Where would you like to move? up/left/right/down: ");
        // scanf("%c", &movement);
        movement = getch();
        switch (movement){
        case 'w':
            /* code */
            printf("\nYou pressed up.");
            //Sleep(1000);
            moveTo(checkIfAbleToMove(globalX, globalY, movement), movement);
            break;
        case 'a':
            printf("\nYou pressed left.");
            //Sleep(1000);
            moveTo(checkIfAbleToMove(globalX, globalY, movement), movement);
            break;
        case 's':
            printf("\nYou pressed down.");
            //Sleep(1000);
            moveTo(checkIfAbleToMove(globalX, globalY, movement), movement);
            break;
        case 'd':
            printf("\nYou pressed right.");
            //Sleep(1000);
            moveTo(checkIfAbleToMove(globalX, globalY, movement), movement);
            break;
        case 'k':
            // gameLoop = false;
            printf("Are you sure? Y/N: ");
            scanf("%c", &areYouSure);
            Sleep(500);
            if(areYouSure == 'y' || areYouSure == 'Y'){
                gameLoop = false;
            }
            else{
                printf("going back");
            }
            break;
        case '/':
            printf("\ndebug mode.\n\n");
            printf("Enter debug menu: \n\n1. Finish the Game\n2. Maxout Move\n3.I don't know\n\n"), scanf("%d", &debugTrigger);
            debugMode(debugTrigger);
            Sleep(500);
            break;

        default:
            printf("Not a valid input.");
            //Sleep(500);
        }

        if(stopTrigger == 1){
            gameLoop = false;
            printf("\nWIN NOTIFICATION");
        }
        else if(msec == 290){
            stopTrigger = 1;
            printf("\nLOSE NOTIFICATION");
            gameLoop = false;
        }

        for(i = 0; i < KOLOM; i++){
            for(j = 0; j < BARIS; j++){
                if(arrayMatrix[i][j] == arrayAcuan[i][j]){
                    stopTrigger = 1;
                }
                else{
                    stopTrigger = 0;
                }
            }
        }

    }
    printf("\n\nBreak while loop");
    Sleep(2000);
}

// before playing, will be asked to press enter
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

// each input will make this function runs
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
                return false;
            }
            else{
                if(input == 'w' || input == 'd' || input == 'a'){
                    return true;
                }
            }
        }
        else if(X == 0){
            if(input == 'a' || input == 's'){
                return false;
            }
            else{
                if(input == 'w' || input == 'd'){
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
                if(input == 'w' || input == 'a' || input == 's'){
                    return true;
                }
            }

        }
        else if(X == 1 || X == 2){
            if(input == 'a' || input == 's' || input == 'w' || input == 'd'){
                return true;
            }
        }
        else if(X == 0){
            if(input == 'a'){
                return false;
            }
            else{
                if(input == 'w' || input == 'd' || input == 's'){
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
                if(input == 'a' || input == 's'){
                    return true;
                }
            }

        }
        else if(X == 1 || X == 2){
            if(input == 'w'){
                return false;
            }
            else if(input == 'a' || input == 's' || input == 'd'){
                return true;
            }
        }
        else if(X == 0){
            if(input == 'a' || input == 'w'){
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

// if checkIfAbleToMove == true, you can move to the destined location
void moveTo(bool movement, int move){
    int a, b, temp;
    if(movement == false){
        printf("\nYou can't move.");
        Sleep(1000);
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

            globalY--;
        }
        else if (move == 'a'){
            a = arrayMatrix[globalY][globalX];
            b = arrayMatrix[globalY][globalX-1];

            temp = a;
            a = b;
            b = temp;

            arrayMatrix[globalY][globalX] = a;
            arrayMatrix[globalY][globalX-1] = b;

            globalX--;
        }
        else if (move == 's'){
            a = arrayMatrix[globalY][globalX];
            b = arrayMatrix[globalY+1][globalX];

            temp = a;
            a = b;
            b = temp;

            arrayMatrix[globalY][globalX] = a;
            arrayMatrix[globalY+1][globalX] = b;  

            globalY++;          
        }
        else if (move == 'd'){
            a = arrayMatrix[globalY][globalX];
            b = arrayMatrix[globalY][globalX+1];

            temp = a;
            a = b;
            b = temp;

            arrayMatrix[globalY][globalX] = a;
            arrayMatrix[globalY][globalX+1] = b;   

            globalX++;         
        }
        printf("\nYou've succesfully moved.");
        moveCounter++;
    }
}

// this function is made to test final position, max move, timer max
void debugMode(int enableDebug){
    int i, j;
    if(enableDebug == 1){
        for(i = 0; i < KOLOM; i++){
            for(j = 0; j < BARIS; j++){
                arrayMatrix[i][j] = arrayAcuan[i][j];
            }
        }
        moveCounter = 1;
        printf("\nTransferred.");
    }
    else if(enableDebug == 2){
        debugMode(1);
        moveCounter = 500;
        printf("\nCounter maxed out");
    }
}

// asking if they're sure to quit
void areYouSureQuit(){
    printf("Are you sure? Y/N: ");
    scanf("%c", &areYouSure);
}