#include "selfHeader.h"

// select modes
void printOption(){
	int choice;
	system("cls");
	printf("\t\t\t");
	printf("=======================================================\n\n");printf("\t\t\t");
	printf("               There are two modes here...           \n\n");printf("\t\t\t");
	printf("=======================================================\n");printf("\t\t\t");
	printf("=                                                     =\n");printf("\t\t\t");
	printf("=  1. Normal Mode (Limited Movements, Limited Time)   =\n");printf("\t\t\t");
	printf("=                                                     =\n");printf("\t\t\t");
	printf("=  2. Free Mode (Unlimited Movements, Unlimited Time) =\n");printf("\t\t\t");
	printf("=                                                     =\n");printf("\t\t\t");
	printf("=======================================================\n\n");
	printf("\t\t\tInput your choice:");
	scanf("%d", &choice);
	switch(choice){
		case 1:
			startFunc();
		case 2:
			startFuncUnli();
	}
}
