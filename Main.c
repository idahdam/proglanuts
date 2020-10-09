#include "selfHeader.h"

int main(int argc, char const *argv[]){
    /* code */
    int opsi, exitNum;
    char exitChar;
    intro();
    MAIN:
    system("cls");
    mainMenu();
    printf("input: "), scanf("%d", &opsi);
    switch(opsi){
    	case 1:
    		//startFunc();
    		printOption();
    	case 2:
    		howToPlay();
    		goto MAIN;
    	case 3:
    		showScore();
    		goto MAIN;
    	case 4:
			printExit();
			exitChar = getch();
			exitNum = chooseOptionExit(exitChar);
			if(exitNum == 101){
				goto MAIN;
			}
			else if(exitNum == 110){
				sayGoodbye();
			}
    		
	}

    return 0;
}
