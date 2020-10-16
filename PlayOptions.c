#include "selfHeader.h"

void printOption(){
	int choice;
	system("cls");
	printf("There are two modes here...\n");
	printf("1. Normal Mode (Limited Movements, Limited Time)\n");
	printf("2. Free Mode (Unlimited Movements, Unlimited Time)\n");
	printf("Input your choice: \n\n");
	scanf("%d", &choice);
	switch(choice){
		case 1:
			startFunc();
		case 2:
			startFuncUnli();
	}
}
