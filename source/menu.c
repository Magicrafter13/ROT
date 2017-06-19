#include "header.h"

PrintConsole topScreen, bottomScreen;

int gamesOption()
{
	return 0;
}
int games(char userDir[30])
{
	consoleInit(GFX_TOP, &topScreen);
	consoleInit(GFX_BOTTOM, &bottomScreen);
	int ireturnvalue = 0;
	int thing = 0, dummy11 = 0;
	char thing2[53];
	FILE *settingsFile;
	sprintf(thing2, "%s/settings.rsf", userDir);
	settingsFile = fopen(thing2, "r");
	fscanf(settingsFile, "%d %d", &dummy11, &thing);
	consoleSelect(&bottomScreen);
	if (thing)
		printf("games opened\n");
	fclose(settingsFile);
	consoleSelect(&topScreen);
	consoleClear();
	FILE *userFile;
	char sf[53], uf[53];
	sprintf(uf, "%s/userdata.ruf", userDir);
	sprintf(sf, "%s/settings.rsf", userDir);
	userFile = fopen(uf, "r");
	settingsFile = fopen(sf, "r");
	char dummy[30], userName[30];
	int back, text, XP, XPEarned, lvl, Battleship, Blackjack, Chess, ConnectFour, Sudoku, DodgeFall, Minesweeper, Mastermind, War, Nanogram, Timer, Mancala, Monopoly, Journal, Pawn, SlotMach, Snake, Alarm, msg;
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
	char returnvalue[30];
	while(true)
	{
		hidScanInput();
		u32 kDown = hidKeysDown();
		u32 kDownOld = hidKeysDown();
		u32 kHeldOld = hidKeysHeld();
		u32 kUpOld = hidKeysHeld();
		if (kDown & KEY_RIGHT)
		{
			
			sprintf(returnvalue, "RIGHT");
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
						if (selGame % 2 == 0)
							selGame += 1;
					}
					break;
				}
			}
			break;
		}
		if (kDown & KEY_DOWN)
		{
			
			sprintf(returnvalue, "DOWN");
			while(true)
			{
				hidScanInput();
				u32 kDown = hidKeysDown();
				u32 kHeld = hidKeysHeld();
				u32 kUp = hidKeysUp();
				if (kDown != kDownOld && kHeld != kHeldOld && kUp != kUpOld)
				{
					if (selGame < gameMax - 1)
					{
						selGame += 2;
					}
					break;
				}
			}
			break;
		}
		if (kDown & KEY_LEFT)
		{
			sprintf(returnvalue, "LEFT");
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
						if (selGame % 2 == 1)
							selGame -= 1;
					}
					break;
				}
			}
			break;
		}
		if (kDown & KEY_UP)
		{
			sprintf(returnvalue, "UP");
			while(true)
			{
				hidScanInput();
				u32 kDown = hidKeysDown();
				u32 kHeld = hidKeysHeld();
				u32 kUp = hidKeysUp();
				if (kDown != kDownOld && kHeld != kHeldOld && kUp != kUpOld)
				{
					if (selGame > gameMin + 1)
					{
						selGame -= 2;
					}
					break;
				}
			}
			break;
		}
		if (kDown & KEY_START)
		{
			sprintf(returnvalue, "START");
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
			sprintf(returnvalue, "A");
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
						int result = gamesOption();
						if (result == 0)
							break;
						if (result == 1)
						{
							sprintf(returnvalue, "START");
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
			sprintf(returnvalue, "B");
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
	if (strcmp(returnvalue, "START") == 0)
	{
		gfxFlushBuffers();
		gfxSwapBuffers();
		gspWaitForVBlank();
		ireturnvalue = 2;
	}
	if (strcmp(returnvalue, "LEFT") == 0)
	{
		gfxFlushBuffers();
		gfxSwapBuffers();
		gspWaitForVBlank();
		ireturnvalue = 1;
	}
	if (strcmp(returnvalue, "UP") == 0)
	{
		gfxFlushBuffers();
		gfxSwapBuffers();
		gspWaitForVBlank();
		ireturnvalue = 1;
	}
	if (strcmp(returnvalue, "RIGHT") == 0)
	{
		gfxFlushBuffers();
		gfxSwapBuffers();
		gspWaitForVBlank();
		ireturnvalue = 1;
	}
	if (strcmp(returnvalue, "DOWN") == 0)
	{
		gfxFlushBuffers();
		gfxSwapBuffers();
		gspWaitForVBlank();
		ireturnvalue = 1;
	}
	if (strcmp(returnvalue, "A") == 0)
	{
		gfxFlushBuffers();
		gfxSwapBuffers();
		gspWaitForVBlank();
		ireturnvalue = 1;
	}
	if (strcmp(returnvalue, "B") == 0)
	{
		gfxFlushBuffers();
		gfxSwapBuffers();
		gspWaitForVBlank();
		ireturnvalue = 0;
	}
	return ireturnvalue;
}

int toolsOption()
{
	return 0;
}

int tools(char userDir[30])
{
	consoleInit(GFX_TOP, &topScreen);
	consoleInit(GFX_BOTTOM, &bottomScreen);
	int ireturnvalue = 0;
	int thing = 0, dummy = 0;
	char thing2[53];
	FILE *settingsFile;
	sprintf(thing2, "%s/settings.rsf", userDir);
	settingsFile = fopen(thing2, "r");
	fscanf(settingsFile, "%d %d", &dummy, &thing);
	consoleSelect(&bottomScreen);
	if (thing)
		printf("tools opened\n");
	fclose(settingsFile);
	consoleSelect(&topScreen);
	consoleClear();
	char returnvalue[30];
	while(true)
	{
		hidScanInput();
		u32 kDown = hidKeysDown();
		u32 kDownOld = hidKeysDown();
		u32 kHeldOld = hidKeysHeld();
		u32 kUpOld = hidKeysHeld();
		if (kDown & KEY_DOWN)
		{
			
			sprintf(returnvalue, "DOWN");
			while(true)
			{
				hidScanInput();
				u32 kDown = hidKeysDown();
				u32 kHeld = hidKeysHeld();
				u32 kUp = hidKeysUp();
				if (kDown != kDownOld && kHeld != kHeldOld && kUp != kUpOld)
				{
					int TMAX = 4;
					if (toolsel < TMAX)
					{
						toolsel += 1;
					}
					break;
				}
			}
			break;
		}
		if (kDown & KEY_UP)
		{
			sprintf(returnvalue, "UP");
			while(true)
			{
				hidScanInput();
				u32 kDown = hidKeysDown();
				u32 kHeld = hidKeysHeld();
				u32 kUp = hidKeysUp();
				if (kDown != kDownOld && kHeld != kHeldOld && kUp != kUpOld)
				{
					int TMIN = 0;
					if (toolsel > TMIN)
					{
						toolsel -= 1;
					}
					break;
				}
			}
			break;
		}
		if (kDown & KEY_START)
		{
			sprintf(returnvalue, "START");
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
			sprintf(returnvalue, "A");
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
						int result = toolsOption();
						if (result == 0)
							break;
						if (result == 1)
						{
							sprintf(returnvalue, "START");
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
			sprintf(returnvalue, "B");
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
	if (strcmp(returnvalue, "START") == 0)
	{
		gfxFlushBuffers();
		gfxSwapBuffers();
		gspWaitForVBlank();
		ireturnvalue = 2;
	}
	if (strcmp(returnvalue, "UP") == 0)
	{
		gfxFlushBuffers();
		gfxSwapBuffers();
		gspWaitForVBlank();
		ireturnvalue = 1;
	}
	if (strcmp(returnvalue, "DOWN") == 0)
	{
		gfxFlushBuffers();
		gfxSwapBuffers();
		gspWaitForVBlank();
		ireturnvalue = 1;
	}
	if (strcmp(returnvalue, "A") == 0)
	{
		gfxFlushBuffers();
		gfxSwapBuffers();
		gspWaitForVBlank();
		ireturnvalue = 1;
	}
	if (strcmp(returnvalue, "B") == 0)
	{
		gfxFlushBuffers();
		gfxSwapBuffers();
		gspWaitForVBlank();
		ireturnvalue = 0;
	}
	return ireturnvalue;
}