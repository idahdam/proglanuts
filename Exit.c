#include "selfHeader.h"

// asking if they wanna exit or not
void printExit(){
	system("cls");
	printf("Are you sure?\n");
	printf("Enter your answer (y/n): ");
}

// entering what they choose
int chooseOptionExit(char sureness){	
	switch(sureness){
		case 'n':
			return 101;
		case 'y':
			return 110;
	}
	
}

// say goodbye to the user
void sayGoodbye(){
	system("cls");
	printf("It's good to see you.\n");
	printf("Press enter to exit.\n");
	getch();
	exit(0);
}
