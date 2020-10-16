#include "selfHeader.h"

void printExit(){
	system("cls");
	printf("Are you sure?\n");
	printf("Enter your answer (y/n): ");
}

int chooseOptionExit(char sureness){	
	switch(sureness){
		case 'n':
			return 101;
		case 'y':
			return 110;
	}
	
}

void sayGoodbye(){
	system("cls");
	printf("It's good to see you.\n");
	printf("Press enter to exit.\n");
	getch();
	exit(0);
}
