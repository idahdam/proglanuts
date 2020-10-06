#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#include "selfHeader.h"

int main(int argc, char const *argv[]){
    /* code */
    int opsi;
    MAIN:
    mainMenu();
    printf("input: "), scanf("%d", &opsi);
    switch(opsi){
    	case 1:
    		startFunc();
    	case 2:
    		howToPlay();
    		goto MAIN;
    	case 3:
    		showScore();
    		goto MAIN;
    	case 0:
    		printf("Belum diset");
    		
	}

    return 0;
}
