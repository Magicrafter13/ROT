#include "header.h"

int gamesOption()
{
	return 0;
}

const char * isLocked(bool item)
{
	if (item)
		return "Unlocked";
	else
		return " Locked ";
}

const char * isSelectedGame(int game)
{
	if (selGame == game)
		return COLOR WHITE CEND;
	else
		return COLOR BRIGHT CSEP WHITE CEND;
}

const char * isSelectedTool(int tool)
{
	if (selTool == tool)
		return COLOR WHITE CEND;
	else
		return COLOR BRIGHT CSEP WHITE CEND;
}

int games(char userDir[30], int upperrv)
{
	int ireturnvalue = 0;
	int thing = 0, dummy11 = 0;
	char thing2[53];
	FILE *settingsFile;
	sprintf(thing2, "%s/settings.rsf", userDir);
	settingsFile = fopen(thing2, "r");
	fscanf(settingsFile, "%d %d", &dummy11, &thing);
	consoleSelect(&bottomScreen);
	if (upperrv != 1)
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
	int back, text, XP, XPEarned, lvl, Battleship, Blackjack, Chess, ConnectFour, Sudoku, DodgeFall, Minesweeper, Mastermind, War, Nanogram, Mancala, Monopoly, SlotMach, Snake;
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
	for (int i = 0; i < 14; i++)
	{
		while(true)
		{
			fscanf(userFile, "%s", dummy);
			if (strcmp(dummy, gameArray[i]) == 0)
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
				if (i == 11)
					fscanf(userFile, "%s %d", dummy, &Monopoly);
				if (i == 12)
					fscanf(userFile, "%s %d", dummy, &SlotMach);
				if (i == 13)
					fscanf(userFile, "%s %d", dummy, &Snake);
				break;
			}
		}
	}
	fclose(userFile);
	int gameMax = 13;
	int gameMin = 0;
	printf("                   -Games List-\n");
	printf("\n");
	printf(RESET " %sBattleship   = %s " RESET "| %sMinesweeper = %s\n", isSelectedGame(0), isLocked(Battleship), isSelectedGame(1), isLocked(Minesweeper));
	printf(RESET " %sBlackjack    = %s " RESET "| %sMastermind  = %s\n", isSelectedGame(2), isLocked(Blackjack), isSelectedGame(3), isLocked(Mastermind));
	printf(RESET " %sChess        = %s " RESET "| %sWar         = %s\n", isSelectedGame(4), isLocked(Chess), isSelectedGame(5), isLocked(War));
	printf(RESET " %sConnect Four = %s " RESET "| %sNanogram    = %s\n", isSelectedGame(6), isLocked(ConnectFour), isSelectedGame(7), isLocked(Nanogram));
	printf(RESET " %sSudoku       = %s " RESET "| %sMancala     = %s\n", isSelectedGame(8), isLocked(Sudoku), isSelectedGame(9), isLocked(Mancala));
	printf(RESET " %sDodge Fall   = %s " RESET "| %sMonopoly    = %s\n", isSelectedGame(10), isLocked(DodgeFall), isSelectedGame(11), isLocked(Monopoly));
	printf(RESET " %sSlotMach     = %s " RESET "| %sSnake       = %s\n", isSelectedGame(12), isLocked(SlotMach), isSelectedGame(13), isLocked(Snake));
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

int tools(char userDir[30], int upperrv)
{
	int ireturnvalue = 0;
	int thing = 0, dummy11 = 0;
	char thing2[53];
	FILE *settingsFile;
	sprintf(thing2, "%s/settings.rsf", userDir);
	settingsFile = fopen(thing2, "r");
	fscanf(settingsFile, "%d %d", &dummy11, &thing);
	consoleSelect(&bottomScreen);
	if (upperrv != 1)
		if (thing)
			printf("tools opened\n");
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
	int back, text, XP, XPEarned, lvl, Timer, Journal, Pawn, Alarm;
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
	char toolArray[4][30];
	strcpy(toolArray[0], "Timer");
	strcpy(toolArray[1], "Journal");
	strcpy(toolArray[2], "Pawn");
	strcpy(toolArray[3], "Alarm");
	for (int i = 0; i < 4; i++)
	{
		while(true)
		{
			fscanf(userFile, "%s", dummy);
			if (strcmp(dummy, toolArray[i]) == 0)
			{
				if (i == 0)
					fscanf(userFile, "%s %d", dummy, &Timer);
				if (i == 1)
					fscanf(userFile, "%s %d", dummy, &Journal);
				if (i == 2)
					fscanf(userFile, "%s %d", dummy, &Pawn);
				if (i == 3)
					fscanf(userFile, "%s %d", dummy, &Alarm);
				break;
			}
		}
	}
	fclose(userFile);
	int toolMax = 13;
	int toolMin = 0;
	printf("                   -Games List-\n");
	printf("\n");
	printf("      " RESET " %sTimer = %s " RESET "| %sJournal = %s\n", isSelectedTool(0), isLocked(Timer), isSelectedTool(1), isLocked(Journal));
	printf("      " RESET " %sPawn  = %s " RESET "| %sAlarm   = %s\n", isSelectedTool(2), isLocked(Pawn), isSelectedTool(3), isLocked(Alarm));
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
					if (selTool < toolMax)
					{
						if (selTool % 2 == 0)
							selTool += 1;
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
					if (selTool < toolMax - 1)
					{
						selTool += 2;
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
					if (selTool > toolMin)
					{
						if (selTool % 2 == 1)
							selTool -= 1;
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
					if (selTool > toolMin + 1)
					{
						selTool -= 2;
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

char storeArray[7][13];
char storeMenu[5][13];

const char * storeStrings(int frame5, int line, int direction)
{
	char * temp = new char[13];
	char * returnstr = new char[12];
	if (direction)
	{ //shift down
		
	} else { //shift up
		if (line % 2 == 0)
		{
			if (frame5 == 0)
			{
				std::copy(&storeMenu[line / 2][1], &storeMenu[line / 2][12], temp);
				sprintf(returnstr, " %s", temp);
			} else if (frame5 == 1)
			{
				std::copy(&storeMenu[line / 2][2], &storeMenu[line / 2][12], temp);
				sprintf(returnstr, "  %s", temp);
			} else if (frame5 == 2)
			{
				std::copy(&storeMenu[line / 2][3], &storeMenu[line / 2][12], temp);
				sprintf(returnstr, "   %s", temp);
			} else if (frame5 == 3)
			{
				std::copy(&storeMenu[line / 2][4], &storeMenu[line / 2][12], temp);
				sprintf(returnstr, "    %s", temp);
			} else if (frame5 == 4)
			{
				std::copy(&storeMenu[line / 2][5], &storeMenu[line / 2][12], temp);
				sprintf(returnstr, "     %s", temp);
			} else if (frame5 == 5)
			{
				std::copy(&storeMenu[line / 2][6], &storeMenu[line / 2][12], temp);
				sprintf(returnstr, "      %s", temp);
			} else if (frame5 == 6)
			{
				std::copy(&storeMenu[line / 2][7], &storeMenu[line / 2][12], temp);
				sprintf(returnstr, "       %s", temp);
			} else if (frame5 == 7)
			{
				std::copy(&storeMenu[line / 2][8], &storeMenu[line / 2][12], temp);
				sprintf(returnstr, "        %s", temp);
			} else if (frame5 == 8)
			{
				std::copy(&storeMenu[line / 2][9], &storeMenu[line / 2][12], temp);
				sprintf(returnstr, "         %s", temp);
			} else if (frame5 == 9)
			{
				std::copy(&storeMenu[line / 2][10], &storeMenu[line / 2][12], temp);
				sprintf(returnstr, "          %s", temp);
			} else if (frame5 == 10)
			{
				std::copy(&storeMenu[line / 2][11], &storeMenu[line / 2][12], temp);
				sprintf(returnstr, "           %s", temp);
			}
			return returnstr;
		} else if (line % 2 == 1)
		{
			if (frame5 == 0)
			{
				std::copy(&storeMenu[line / 2][0], &storeMenu[line / 2][1], temp);
				sprintf(returnstr, "%s           ", temp);
			} else if (frame5 == 1)
			{
				std::copy(&storeMenu[line / 2][0], &storeMenu[line / 2][2], temp);
				sprintf(returnstr, "%s          ", temp);
			} else if (frame5 == 2)
			{
				std::copy(&storeMenu[line / 2][0], &storeMenu[line / 2][3], temp);
				sprintf(returnstr, "%s         ", temp);
			} else if (frame5 == 3)
			{
				std::copy(&storeMenu[line / 2][0], &storeMenu[line / 2][4], temp);
				sprintf(returnstr, "%s        ", temp);
			} else if (frame5 == 4)
			{
				std::copy(&storeMenu[line / 2][0], &storeMenu[line / 2][5], temp);
				sprintf(returnstr, "%s       ", temp);
			} else if (frame5 == 5)
			{
				std::copy(&storeMenu[line / 2][0], &storeMenu[line / 2][6], temp);
				sprintf(returnstr, "%s      ", temp);
			} else if (frame5 == 6)
			{
				std::copy(&storeMenu[line / 2][0], &storeMenu[line / 2][7], temp);
				sprintf(returnstr, "%s     ", temp);
			} else if (frame5 == 7)
			{
				std::copy(&storeMenu[line / 2][0], &storeMenu[line / 2][8], temp);
				sprintf(returnstr, "%s    ", temp);
			} else if (frame5 == 8)
			{
				std::copy(&storeMenu[line / 2][0], &storeMenu[line / 2][9], temp);
				sprintf(returnstr, "%s   ", temp);
			} else if (frame5 == 9)
			{
				std::copy(&storeMenu[line / 2][0], &storeMenu[line / 2][10], temp);
				sprintf(returnstr, "%s  ", temp);
			} else if (frame5 == 10)
			{
				std::copy(&storeMenu[line / 2][0], &storeMenu[line / 2][11], temp);
				sprintf(returnstr, "%s ", temp);
			}
			return returnstr;
		}
	}
	return "error";
}

int storeDisplay(int method)
{
	strcpy(storeMenu[0], storeArray[selStore + 0]);
	strcpy(storeMenu[1], storeArray[selStore + 1]);
	strcpy(storeMenu[2], storeArray[selStore + 2]);
	strcpy(storeMenu[3], storeArray[selStore + 3]);
	strcpy(storeMenu[4], storeArray[selStore + 4]);
	if (method == 0)
	{
		printf(RESET "\x1b[0;20H-XP Store-");
		printf(RESET "\x1b[4;19H" COLOR BRIGHT CSEP WHITE CEND "%s", storeMenu[0]);
		printf(RESET "\x1b[6;19H" COLOR BRIGHT CSEP WHITE CEND "%s", storeMenu[1]);
		printf(RESET "\x1b[8;19H" COLOR WHITE CEND "%s", storeMenu[2]);
		printf(RESET "\x1b[10;19H" COLOR BRIGHT CSEP WHITE CEND "%s", storeMenu[3]);
		printf(RESET "\x1b[12;19H" COLOR BRIGHT CSEP WHITE CEND "%s", storeMenu[4]);
	} else if (method == 1)
	{
		for (int i = 0; i < 22; i++)
		{
			for (int n = 0; n < 5; n++)
				gspWaitForVBlank();
			printf("\x1b[4;19H" COLOR BRIGHT CSEP WHITE CEND "%s", storeStrings(i, 0, 0));
			printf("\x1b[5;19H" COLOR BRIGHT CSEP WHITE CEND "%s", storeStrings(i, 1, 0));
			printf("\x1b[6;19H" COLOR BRIGHT CSEP WHITE CEND "%s", storeStrings(i, 2, 0));
			printf("\x1b[7;19H" COLOR BRIGHT CSEP WHITE CEND "%s", storeStrings(i, 3, 0));
			printf("\x1b[8;19H" COLOR WHITE CEND "%s", storeStrings(i, 4, 0));
			printf("\x1b[9;19H" COLOR BRIGHT CSEP WHITE CEND "%s", storeStrings(i, 5, 0));
			printf("\x1b[10;19H" COLOR BRIGHT CSEP WHITE CEND "%s", storeStrings(i, 6, 0));
			printf("\x1b[11;19H" COLOR BRIGHT CSEP WHITE CEND "%s", storeStrings(i, 7, 0));
			printf("\x1b[12;19H" COLOR BRIGHT CSEP WHITE CEND "%s", storeStrings(i, 8, 0));
		}
	}
	return 0;
}

int store(char userDir[30], int upperrv)
{
	int ireturnvalue = 0;
	consoleSelect(&bottomScreen);
	if (upperrv != 1)
		if (debugTF)
			printf("store opened\n");
	consoleSelect(&topScreen);
	consoleClear();
	strcpy(storeArray[0], "            ");
	strcpy(storeArray[1], "            ");
	strcpy(storeArray[2], " Buy a Game ");
	strcpy(storeArray[3], " Buy a Tool ");
	strcpy(storeArray[4], "Reedem Code ");
	strcpy(storeArray[5], "            ");
	strcpy(storeArray[6], "            ");
	int storeMax = 2;
	int storeMin = 0;
	storeDisplay(storeDisp != 3); //0 neutral 1 Down[MovesUp] 2 Up[MovesDown]
	//supposed to be storeDisplay(storeDisp); but it crashes when trying to animate (1 or 2).
	//I don't currently know how to fix this, so if anyone can help, please go to my GitHub page, because this
	//issue should be listed there.
	storeDisp = 0;
	printf("\x1b[0;20H-XP Store-");
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
					if (selStore < storeMax)
					{
						selStore++;
						storeDisp = 1;
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
					if (selStore > storeMin)
					{
						selStore--;
						storeDisp = 2;
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

int credits()
{
	consoleSelect(&bottomScreen);
	if (debugTF)
		printf("credits opened\n");
	consoleSelect(&topScreen);
	consoleClear();
	printf("\x1b[0;21HCredits:");
	printf("\x1b[2;16H" COLOR RED CEND "-Lead Programmers-");
	printf("\x1b[3;18H" RESET "Matthew Rease");
	printf("\x1b[5;17H" COLOR YELLOW CEND "-Alpha Testing-");
	printf("\x1b[6;18H" RESET "Jared Freeman");
	printf("\x1b[8;17H" COLOR CYAN CEND "-Special Thanks-");
	printf("\x1b[9;10H" COLOR BRIGHT CSEP RED CEND "Smealum" RESET " - " COLOR BRIGHT CSEP BLUE CEND "libctru" RESET " and " COLOR BLUE CEND "homebrew");
	printf("\x1b[10;0H" RESET "Aurelio Mannara +");
	printf("\x1b[11;16H- both-screen-text " COLOR BRIGHT CSEP BLUE CEND "libctru" RESET " example");
	printf("\x1b[12;16H- colored-text " COLOR BRIGHT CSEP BLUE CEND "libctru" RESET " example");
	printf("\x1b[13;16H- read-controls " COLOR BRIGHT CSEP BLUE CEND "libctru" RESET " example");
	printf("\x1b[14;16H- touch-screen " COLOR BRIGHT CSEP BLUE CEND "libctru" RESET " example");
	printf("\x1b[15;16H- multiple-windows-text " COLOR BRIGHT CSEP BLUE CEND "libctru" RESET);
	printf("\x1b[16;43Hexample");
	printf("\x1b[17;4Hfincs - software-keyboard " COLOR BRIGHT CSEP BLUE CEND "libctru" RESET " example");
	printf("\x1b[18;14HAnd the people over at " COLOR BRIGHT CSEP YELLOW CEND "sourceforge," RESET);
	printf("\x1b[19;12Hhelping me learn " COLOR GREEN CEND "C" RESET " and " COLOR BRIGHT CSEP GREEN CEND "C++" RESET);
	for (int i = 0; i < 420; i++)
		gspWaitForVBlank();
	return 0;
}