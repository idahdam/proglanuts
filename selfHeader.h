#ifndef SELF_HEADER_H
	
	#define SELF_HEADER_H
		
	#include <stdio.h>
	#include <stdbool.h>
	#include <stdlib.h>
	#include <conio.h>
	#include <time.h>
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
	
	// for the playunlimited.c
	void startFuncUnli();
	void setupMatrixUnli();
	void randomizeElementsUnli();
	void setMainMatrixElementsUnli();
	void printWholeMainGameUnli();
	void pressStartOrEscapeUnli();
	void askPlayOrMainUnli();
	bool checkIfAbleToMoveUnli(int X, int Y, char input);
	void moveToUnli(bool movement, int move);
	void debugModeUnli(int enableDebug);
	void stopLoopArrayUnli(int stopTrigger);
	void timerRefreshUnli(char movement);
	int formattingSecondsUnli(int seconds);
	int formattingMinutesUnli(int seconds);
	
	// for the playoptions.c
	void printOption();
	
	// for the result.c
	void printWin();
	void printLose();
	void enterScore(int score, int minutes, int seconds);
	void showScore();
	
	// for the mainmenu.c
	void intro();
	void mainMenu();
	
	// for the howtoplay.c
	void howToPlay();	
	
	// for exit
	void printExit();
	int chooseOptionExit(char sureness);
	void sayGoodbye();

#endif

