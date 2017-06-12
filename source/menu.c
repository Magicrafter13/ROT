#include <3ds.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "header.h"

PrintConsole topScreen, bottomScreen;

char returnValue[30];
int ireturnValue = 0;

int games(char userDir[30])
{
	consoleInit(GFX_TOP, &topScreen);
	consoleInit(GFX_BOTTOM, &bottomScreen);
	consoleSelect(&bottomScreen);
	printf("games opened\n");
	consoleSelect(&topScreen);
	consoleClear();
	//printf("Feature will be added in future release.\n");
	//printf("Will return to settings menu in 5 seconds.\n");
	//for(int I = 0; I < 300; I++)
		//gspWaitForVBlank();
	FILE *userFile, *settingsFile;
	char sf[53], uf[53];
	sprintf(uf, "%s/userdata.ruf", userDir);
	sprintf(sf, "%s/settings.rsf", userDir);
	userFile = fopen(uf, "r");
	settingsFile = fopen(sf, "r");
	char dummy[30], userName[30];
	int back, text, XP, XPEarned, lvl, Battleship, Blackjack, Chess, ConnectFour, DOND, FakeVirus, GTA, Sudoku, DodgeFall, Stress, Minesweeper, Mastermind, War, Nanogram, TTT, RC, RPS, Timer, WorkLock, Mancala, Monopoly, NGG, Journal, Pawn, SlotMach, Snake, Trivia, Alarm, msg;
	char otherArray[6][30];
	strcpy(otherArray[0], "name");
	strcpy(otherArray[1], "pass");
	strcpy(otherArray[2], "color");
	strcpy(otherArray[3], "XP");
	strcpy(otherArray[4], "XPEarned");
	strcpy(otherArray[5], "lvl");
	for (int i = 0; i < 6; i++)
	{
		while(true)
		{
			fscanf(userFile, "%s", dummy);
			if (strcmp(dummy, otherArray[i]) == 0)
			{
				if (i == 0)
					fscanf(userFile, "%s %s", dummy, userName);
				if (i == 2)
					fscanf(userFile, "%s %d %d", dummy, &back, &text);
				if (i == 3)
					fscanf(userFile, "%s %d", dummy, &XP);
				if (i == 4)
					fscanf(userFile, "%s %d", dummy, &XPEarned);
				if (i == 5)
					fscanf(userFile, "%s %d", dummy, &lvl);
				break;
			}
		}
	}
	//fscanf(userFile, "%s %s %s %s %s %s %s %s %d %d %s %s %d %s %s %d %s %s %d", dummy, dummy, userName, dummy, dummy, dummy, dummy, dummy, &back, &text, dummy, dummy, &XP, dummy, dummy, &XPEarned, dummy, dummy, &lvl);
	char gameArray[14][30];
	strcpy(gameArray[0], "Battleship");
	strcpy(gameArray[1], "Blackjack");
	strcpy(gameArray[2], "Chess");
	strcpy(gameArray[3], "ConnectFour");
	strcpy(gameArray[4], "Sudoku");
	strcpy(gameArray[5], "DodgeFall");
	strcpy(gameArray[6], "Minesweeper");
	strcpy(gameArray[7], "Mastermind");
	strcpy(gameArray[8], "War");
	strcpy(gameArray[9], "Nanogram");
	strcpy(gameArray[10], "Mancala");
	strcpy(gameArray[11], "Monopoly");
	strcpy(gameArray[12], "SlotMach");
	strcpy(gameArray[13], "Snake");
	for (int i = 0; i < 11; i++)
	{
		while(true)
		{
			fscanf(userFile, "%s", dummy);
			int part = i + 1;
			if (strcmp(dummy, gameArray[part]) == 0)
			{
				if (i == 0)
					fscanf(userFile, "%s %d", dummy, &Battleship);
				if (i == 1)
					fscanf(userFile, "%s %d", dummy, &Blackjack);
				if (i == 2)
					fscanf(userFile, "%s %d", dummy, &Chess);
				if (i == 3)
					fscanf(userFile, "%s %d", dummy, &ConnectFour);
				if (i == 4)
					fscanf(userFile, "%s %d", dummy, &Sudoku);
				if (i == 5)
					fscanf(userFile, "%s %d", dummy, &DodgeFall);
				if (i == 6)
					fscanf(userFile, "%s %d", dummy, &Minesweeper);
				if (i == 7)
					fscanf(userFile, "%s %d", dummy, &Mastermind);
				if (i == 8)
					fscanf(userFile, "%s %d", dummy, &War);
				if (i == 9)
					fscanf(userFile, "%s %d", dummy, &Nanogram);
				if (i == 10)
					fscanf(userFile, "%s %d", dummy, &Mancala);
				break;
			}
		}
	}
	fclose(userFile);
	int gameMax = 10;
	int gameMin = 0;
	const char * isLocked(bool game)
	{
		if (game)
			return "Unlocked";
		else
			return " Locked ";
	}
	const char * isSelected(int game)
	{
		if (selGame == game)
			return COLOR WHITE CEND;
		else
			return COLOR BRIGHT CSEP WHITE CEND;
	}
	printf("                   -Games List-\n");
	printf("\n");
	printf(RESET " %sBattleship   = %s " RESET "| %sMinesweeper = %s\n", isSelected(0), isLocked(Battleship), isSelected(1), isLocked(Minesweeper));
	printf(RESET " %sBlackjack    = %s " RESET "| %sMastermind  = %s\n", isSelected(2), isLocked(Blackjack), isSelected(3), isLocked(Mastermind));
	printf(RESET " %sChess        = %s " RESET "| %sWar         = %s\n", isSelected(4), isLocked(Chess), isSelected(5), isLocked(War));
	printf(RESET " %sConnect Four = %s " RESET "| %sNanogram    = %s\n", isSelected(6), isLocked(ConnectFour), isSelected(7), isLocked(Nanogram));
	printf(RESET " %sSudoku       = %s " RESET "| %sMancala     = %s\n", isSelected(8), isLocked(Sudoku), isSelected(9), isLocked(Mancala));
	printf(RESET " %sDodge Fall   = %s", isSelected(10), isLocked(DodgeFall));
	while(true)
	{
		hidScanInput();
		u32 kDown = hidKeysDown();
		u32 kDownOld = hidKeysDown();
		u32 kHeldOld = hidKeysHeld();
		u32 kUpOld = hidKeysHeld();
		if (kDown & KEY_DOWN)
		{
			
			sprintf(returnValue, "DOWN");
			while(true)
			{
				hidScanInput();
				u32 kDown = hidKeysDown();
				u32 kHeld = hidKeysHeld();
				u32 kUp = hidKeysUp();
				if (kDown != kDownOld && kHeld != kHeldOld && kUp != kUpOld)
				{
					if (selGame < gameMax)
					{
						selGame += 1;
					}
					break;
				}
			}
			break;
		}
		if (kDown & KEY_UP)
		{
			sprintf(returnValue, "UP");
			while(true)
			{
				hidScanInput();
				u32 kDown = hidKeysDown();
				u32 kHeld = hidKeysHeld();
				u32 kUp = hidKeysUp();
				if (kDown != kDownOld && kHeld != kHeldOld && kUp != kUpOld)
				{
					if (selGame > gameMin)
					{
						selGame -= 1;
					}
					break;
				}
			}
			break;
		}
		if (kDown & KEY_START)
		{
			sprintf(returnValue, "START");
			while(true)
			{
				hidScanInput();
				u32 kDown = hidKeysDown();
				u32 kHeld = hidKeysHeld();
				u32 kUp = hidKeysUp();
				if (kDown != kDownOld && kHeld != kHeldOld && kUp != kUpOld)
				{
					break;
				}
			}
			break;
		}
		if (kDown & KEY_A)
		{
			sprintf(returnValue, "A");
			while(true)
			{
				hidScanInput();
				u32 kDown = hidKeysDown();
				u32 kHeld = hidKeysHeld();
				u32 kUp = hidKeysUp();
				if (kDown != kDownOld && kHeld != kHeldOld && kUp != kUpOld)
				{
					while(true)
					{
						int result = settingsOption();
						if (result == 0)
							break;
						if (result == 1)
						{
							sprintf(returnValue, "START");
							break;
						}
					}
					break;
				}
			}
			break;
		}
		if (kDown & KEY_B)
		{
			sprintf(returnValue, "B");
			while(true)
			{
				hidScanInput();
				u32 kDown = hidKeysDown();
				u32 kHeld = hidKeysHeld();
				u32 kUp = hidKeysUp();
				if (kDown != kDownOld && kHeld != kHeldOld && kUp != kUpOld)
				{
					break;
				}
			}
			break;
		}
	}
	if (strcmp(returnValue, "START") == 0)
	{
		gfxFlushBuffers();
		gfxSwapBuffers();
		gspWaitForVBlank();
		ireturnValue = 2;
	}
	if (strcmp(returnValue, "A") == 0)
	{
		gfxFlushBuffers();
		gfxSwapBuffers();
		gspWaitForVBlank();

		ireturnValue = 1;
	}
	if (strcmp(returnValue, "UP") == 0)
	{
		gfxFlushBuffers();
		gfxSwapBuffers();
		gspWaitForVBlank();

		ireturnValue = 1;
	}
	if (strcmp(returnValue, "DOWN") == 0)
	{
		gfxFlushBuffers();
		gfxSwapBuffers();
		gspWaitForVBlank();
		ireturnValue = 1;
	}
	if (strcmp(returnValue, "B") == 0)
	{
		gfxFlushBuffers();
		gfxSwapBuffers();
		gspWaitForVBlank();
		ireturnValue = 0;
	}
	return ireturnValue;
}

int tools(char userDir[30])
{
	consoleInit(GFX_TOP, &topScreen);
	consoleInit(GFX_BOTTOM, &bottomScreen);
	{
		consoleSelect(&bottomScreen);
		printf("tools opened\n");
		consoleSelect(&topScreen);
		consoleClear();
		printf("Feature will be added in future release.\n");
		printf("Will return to settings menu in 5 seconds.\n");
		for(int I = 0; I < 300; I++)
			gspWaitForVBlank();
	}
	return 0;
}