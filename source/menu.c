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

int games(char userDir[30], int selGame)
{
	consoleInit(GFX_TOP, &topScreen);
	consoleInit(GFX_BOTTOM, &bottomScreen);
	{
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
		fscanf(userFile, "%s %s %s %s %s %s %s %s %d %d %s %s %d %s %s %d %s %s %d", dummy, dummy, userName, dummy, dummy, dummy, dummy, dummy, &back, &text, dummy, dummy, &XP, dummy, dummy, &XPEarned, dummy, dummy, &lvl);
		fscanf(userFile, "%s %s %d %s %s %d %s %s %d %s %s %d %s %s %d %s %s %d %s %s %d %s %s %d %s %s %d %s %s %d %s %s %d %s %s %d %s %s %d %s %s %d %s %s %d %s %s %d %s %s %d %s %s %d %s %s %d %s %s %d %s %s %d %s %s %d %s %s %d %s %s %d %s %s %d %s %s %d %s %s %d %s %s %d %s %s %d", dummy, dummy, &Battleship, dummy, dummy, &Blackjack, dummy, dummy, &Chess, dummy, dummy, &ConnectFour, dummy, dummy, &DOND, dummy, dummy, &FakeVirus, dummy, dummy, &GTA, dummy, dummy, &Sudoku, dummy, dummy, &DodgeFall, dummy, dummy, &Stress, dummy, dummy, &Minesweeper, dummy, dummy, &Mastermind, dummy, dummy, &War, dummy, dummy, &Nanogram, dummy, dummy, &TTT, dummy, dummy, &RC, dummy, dummy, &RPS, dummy, dummy, &Timer, dummy, dummy, &WorkLock, dummy, dummy, &Mancala, dummy, dummy, &Monopoly, dummy, dummy, &NGG, dummy, dummy, &Journal, dummy, dummy, &Pawn, dummy, dummy, &SlotMach, dummy, dummy, &Snake, dummy, dummy, &Trivia, dummy, dummy, &Alarm, dummy, dummy, &msg);
		fclose(userFile);
		int gameMax = 11;
		int gameMin = 0;
		int gsMax = gameMax + 1;
		int gs[gsMax];
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
				return "37";
			else
				return "2;37";
		}
		printf("                   -Games List-\n");
		printf("\n");
		printf(" \x1b[%smBattleship   = %s \x1b[0m| \x1b[%smMinesweeper = %s\n", isSelected(0), isLocked(Battleship), isSelected(7), isLocked(Minesweeper));
		printf(" \x1b[%smBlackjack    = %s \x1b[0m| \x1b[%smMastermind  = %s\n", isSelected(1), isLocked(Blackjack), isSelected(8), isLocked(Mastermind));
		printf(" \x1b[%smChess        = %s \x1b[0m| \x1b[%smWar         = %s\n", isSelected(2), isLocked(Chess), isSelected(9), isLocked(War));
		printf(" \x1b[%smConnect Four = %s \x1b[0m| \x1b[%smNanogram    = %s\n", isSelected(3), isLocked(ConnectFour), isSelected(10), isLocked(Nanogram));
		printf(" \x1b[%smSudoku       = %s \x1b[0m| \x1b[%smTic Tac Toe = %s\n", isSelected(4), isLocked(Sudoku), isSelected(11), isLocked(TTT));
		printf(" \x1b[%smDodge Fall   = %s", isSelected(5), isLocked(DodgeFall));
		while (true)
		{
			hidScanInput();
			u32 kDownOld = hidKeysDown();
			u32 kUpOld = hidKeysUp();
			u32 kHeldOld = hidKeysHeld();
			u32 kDown = hidKeysDown();
			if (kDown & KEY_A)
			{
				while(true)
				{
					hidScanInput();
					u32 kDown = hidKeysDown();
					u32 kHeld = hidKeysHeld();
					u32 kUp = hidKeysUp();
					if (kDown != kDownOld && kHeld != kHeldOld && kUp != kUpOld)
					{
						int result = 0;//do a thing
						if (result == 0)
						{
							strcpy(returnValue, "A");
							break;
						}
						if (result == 2)
						{
							strcpy(returnValue, "START");
							break;
						}
					}
				}
				break;
			}
			if (kDown & KEY_B)
			{
				while(true)
				{
					hidScanInput();
					u32 kDown = hidKeysDown();
					u32 kHeld = hidKeysHeld();
					u32 kUp = hidKeysUp();
					if (kDown != kDownOld && kHeld != kHeldOld && kUp != kUpOld)
					{
						strcpy(returnValue, "B");
						break;
					}
				}
				break;
			}
			if (kDown & KEY_START)
			{
				strcpy(returnValue, "START");
				break;
			}
		}
	}
	if (strcmp(returnValue, "START") == 0)
		ireturnValue = 2;
	if (strcmp(returnValue, "A") == 0)
		ireturnValue = 1;
	if (strcmp(returnValue, "B") == 0)
		ireturnValue = 0;
	
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