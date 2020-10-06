#ifndef SELF_HEADER_H
	
	#define SELF_HEADER_H
		
	#include <stdio.h>
	#include <stdlib.h>
	#include <conio.h>
	#include <stdbool.h>
	#include <windows.h>
	
	// for the play.c
	void startFunc();
	void setupMatrix();
	void randomizeElements();
	void setMainMatrixElements();
	void printWholeMainGame();
	void pressStartOrEscape();
	void askPlayOrMain();
	bool checkIfAbleToMove(int X, int Y, char input);
	void moveTo(bool movement, int move);
	void debugMode(int enableDebug);
	void stopLoopArray(int stopTrigger);
	void timerRefresh(char movement);
	int formattingSeconds(int seconds);
	int formattingMinutes(int seconds);
	
	// for the result.c
	void printWin();
	void printLose();
	void enterScore(int score);
	void showScore();
	
	// for the mainmenu.c
	void intro();
	void mainMenu();
	
	// for the howtoplay.c
	void howToPlay();	

#endif

