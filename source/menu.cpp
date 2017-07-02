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
	char listArray[14][12];
	sprintf(listArray[0], "%s", isLocked(Battleship));
	sprintf(listArray[1], "%s", isLocked(Minesweeper));
	sprintf(listArray[2], "%s", isLocked(Blackjack));
	sprintf(listArray[3], "%s", isLocked(Mastermind));
	sprintf(listArray[4], "%s", isLocked(Chess));
	sprintf(listArray[5], "%s", isLocked(War));
	sprintf(listArray[6], "%s", isLocked(ConnectFour));
	sprintf(listArray[7], "%s", isLocked(Nanogram));
	sprintf(listArray[8], "%s", isLocked(Sudoku));
	sprintf(listArray[9], "%s", isLocked(Mancala));
	sprintf(listArray[10], "%s", isLocked(DodgeFall));
	sprintf(listArray[11], "%s", isLocked(Monopoly));
	sprintf(listArray[12], "%s", isLocked(SlotMach));
	sprintf(listArray[13], "%s", isLocked(Snake));
	printf(RESET "                   -Games List-\n");
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
		if (selGame < gameMax)
		{
			if (selGame % 2 == 0)
			{
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
							selGame += 1;
							break;
						}
					}
					break;
				}
			}
		}
		if (selGame < gameMax - 1)
		{
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
						selGame += 2;
						break;
					}
				}
				break;
			}
		}
		if (selGame > gameMin)
		{
			if (selGame % 2 == 1)
			{
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
							selGame -= 1;
							break;
						}
					}
					break;
				}
			}
		}
		if (selGame > gameMin + 1)
		{
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
						selGame -= 2;
						break;
					}
				}
				break;
			}
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
		if (strcmp(listArray[selTool], "Unlocked") == 0)
		{
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
	int back, text, XP, XPEarned, lvl, Timer, Journal, Pawn, Alarm, Media;
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
	strcpy(toolArray[4], "Media");
	for (int i = 0; i < 5; i++)
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
				if (i == 4)
					fscanf(userFile, "%s %d", dummy, &Media);
				break;
			}
		}
	}
	fclose(userFile);
	int toolMax = 4;
	int toolMin = 0;
	char listArray[5][12];
	sprintf(listArray[0], "%s", isLocked(Timer));
	sprintf(listArray[1], "%s", isLocked(Journal));
	sprintf(listArray[2], "%s", isLocked(Pawn));
	sprintf(listArray[3], "%s", isLocked(Alarm));
	sprintf(listArray[4], "%s", isLocked(Media));
	printf(RESET "                   -Tools List-\n");
	printf("\n");
	printf("      " RESET " %sTimer = %s " RESET "| %sJournal = %s\n", isSelectedTool(0), isLocked(Timer), isSelectedTool(1), isLocked(Journal));
	printf("      " RESET " %sPawn  = %s " RESET "| %sAlarm   = %s\n", isSelectedTool(2), isLocked(Pawn), isSelectedTool(3), isLocked(Alarm));
	printf("      " RESET " %sMedia = %s \n", isSelectedTool(4), isLocked(Media));
	char returnvalue[30];
	while(true)
	{
		hidScanInput();
		u32 kDown = hidKeysDown();
		u32 kDownOld = hidKeysDown();
		u32 kHeldOld = hidKeysHeld();
		u32 kUpOld = hidKeysHeld();
		if (selTool < toolMax)
		{
			if (selTool % 2 == 0)
			{
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
							selTool += 1;
							break;
						}
					}
					break;
				}
			}
		}
		if (selTool < toolMax - 1)
		{
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
						selTool += 2;
						break;
					}
				}
				break;
			}
		}
		if (selTool > toolMin)
		{
			if (selTool % 2 == 1)
			{
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
							selTool -= 1;
							break;
						}
					}
					break;
				}
			}
		}
		if (selTool > toolMin + 1)
		{
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
						selTool -= 2;
						break;
					}
				}
				break;
			}
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
		if(strcmp(listArray[selTool], "Unlocked") == 0)
		{
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

char storeArray[14][13] = {"            ", "            ", "            ", "            ", " Buy a Game ", "            ", " Buy a Tool ", "            ", "Reedem Code ", "            ", "            ", "            ", "            ", "            "};
char storeMenu[14][13] = {"            ", "            ", "            ", "            ", "            ", "            ", "            ", "            ", "            ", "            ", "            ", "            ", "            ", "            "};

std::string storeStrings(int frame5, int line, int direction)
{
	//char * temp1 = new char[12];
	//char * temp2 = new char[12];
	//char * returnstr = new char[12];
	std::string temp1;
	std::string temp2;
	std::string returnstr;
	returnstr.clear();
	if (direction)
	{ //shift down
		if (frame5 < 11)
		{
			std::copy(&storeMenu[line][0], &storeMenu[line][11-frame5], back_inserter(temp1));
			std::copy(&storeMenu[line-1][11-frame5], &storeMenu[line-1][12], back_inserter(temp2));
			returnstr.append(temp1);
			returnstr.append(temp2);
		} else {
			std::copy(&storeMenu[line-1][0], &storeMenu[line-1][22-frame5], back_inserter(temp1));
			std::copy(&storeMenu[line-2][22-frame5], &storeMenu[line-2][12], back_inserter(temp2));
			returnstr.append(temp1);
			returnstr.append(temp2);
		}
	} else { //shift up
		if (frame5 < 11)
		{
			std::copy(&storeMenu[line+1][0], &storeMenu[line+1][frame5+1], back_inserter(temp1));
			std::copy(&storeMenu[line][frame5+1], &storeMenu[line][12], back_inserter(temp2));
			//sprintf(returnstr, "%s%s", temp1.c_str(), temp2.c_str());
			returnstr.append(temp1);
			returnstr.append(temp2);
		} else {
			std::copy(&storeMenu[line+2][0], &storeMenu[line+2][frame5-10], back_inserter(temp1));
			std::copy(&storeMenu[line+1][frame5-10], &storeMenu[line+1][12], back_inserter(temp2));
			//sprintf(returnstr, "%s%s", temp1.c_str(), temp2.c_str());
			returnstr.append(temp1);
			returnstr.append(temp2);
		}
	}
	consoleSelect(&bottomScreen);
	//printf("%s", returnstr.c_str());
	consoleSelect(&topScreen);
	return returnstr;
}

int storeDisplay(int method)
{
	int iRandom1, iRandom2, iRandom3, iRandom4, iRandom5, iRandom6, iRandom7;
	srand(time(NULL));
	for(int i = 0; i < 13; i++)
		strcpy(storeMenu[i], storeArray[selStore + i - 2]);
	if (method == 1)
	{
		for (int i = 0; i < 22; i++)
		{
			iRandom1 = rand() % 6 + 31;
			iRandom2 = rand() % 6 + 31;
			iRandom3 = rand() % 6 + 31;
			iRandom4 = rand() % 6 + 31;
			iRandom5 = rand() % 6 + 31;
			iRandom6 = rand() % 6 + 31;
			iRandom7 = rand() % 6 + 31;
			if (i % 4 == 1)
				printf("\x1b[0;20H-\x1b[%dmX\x1b[%dmP \x1b[%dmS\x1b[%dmt\x1b[%dmo\x1b[%dmr\x1b[%dme\x1b[0m-", iRandom1, iRandom2, iRandom3, iRandom4, iRandom5, iRandom6, iRandom7);
			for(int n = 0; n < 4; n++)
			{
				printf("\x1b[%d;19H" COLOR BRIGHT CSEP WHITE CEND "%s", (n + 4), storeStrings(i, (n + 2), 0).c_str());
				printf("\x1b[%d;19H" COLOR BRIGHT CSEP WHITE CEND "%s", (n + 9), storeStrings(i, (n + 7), 0).c_str());
			}
			printf("\x1b[8;19H" RESET "%s", storeStrings(i, 6, 0).c_str());
			gspWaitForVBlank();
		}
		method = 0;
		selStore += 2;
	}
	if (method == 2)
	{
		for (int i = 0; i < 22; i++)
		{
			iRandom1 = rand() % 6 + 31;
			iRandom2 = rand() % 6 + 31;
			iRandom3 = rand() % 6 + 31;
			iRandom4 = rand() % 6 + 31;
			iRandom5 = rand() % 6 + 31;
			iRandom6 = rand() % 6 + 31;
			iRandom7 = rand() % 6 + 31;
			if (i % 4 == 1)
				printf("\x1b[0;20H-\x1b[%dmX\x1b[%dmP \x1b[%dmS\x1b[%dmt\x1b[%dmo\x1b[%dmr\x1b[%dme\x1b[0m-", iRandom1, iRandom2, iRandom3, iRandom4, iRandom5, iRandom6, iRandom7);
			for(int n = 0; n < 4; n++)
			{
				printf("\x1b[%d;19H" COLOR BRIGHT CSEP WHITE CEND "%s", (n + 4), storeStrings(i, (n + 2), 1).c_str());
				printf("\x1b[%d;19H" COLOR BRIGHT CSEP WHITE CEND "%s", (n + 9), storeStrings(i, (n + 7), 1).c_str());
			}
			printf("\x1b[8;19H" RESET "%s", storeStrings(i, 6, 1).c_str());
			gspWaitForVBlank();
		}
		method = 0;
		selStore -= 2;
	}
	for(int i = 0; i < 13; i++)
		strcpy(storeMenu[i], storeArray[selStore + i - 2]);
	if (method == 0)
	{
		iRandom1 = rand() % 6 + 1;
		iRandom2 = rand() % 6 + 1;
		iRandom3 = rand() % 6 + 1;
		iRandom4 = rand() % 6 + 1;
		iRandom5 = rand() % 6 + 1;
		iRandom6 = rand() % 6 + 1;
		iRandom7 = rand() % 6 + 1;
		printf("\x1b[0;20H-\x1b[3%dmX" RESET "\x1b[3%dmP" RESET " \x1b[3%dmS" RESET "\x1b[3%dmt" RESET "\x1b[3%dmo" RESET "\x1b[3%dmr" RESET "\x1b[3%dme" RESET "-", iRandom1, iRandom2, iRandom3, iRandom4, iRandom5, iRandom6, iRandom7);
		printf(RESET "\x1b[4;19H" COLOR BRIGHT CSEP WHITE CEND "%s", storeMenu[2]);
		printf(RESET "\x1b[5;19H" COLOR BRIGHT CSEP WHITE CEND "%s", storeMenu[3]);
		printf(RESET "\x1b[6;19H" COLOR BRIGHT CSEP WHITE CEND "%s", storeMenu[4]);
		printf(RESET "\x1b[7;19H" COLOR BRIGHT CSEP WHITE CEND "%s", storeMenu[5]);
		printf(RESET "\x1b[8;19H" COLOR WHITE CEND "%s", storeMenu[6]);
		printf(RESET "\x1b[9;19H" COLOR BRIGHT CSEP WHITE CEND "%s", storeMenu[7]);
		printf(RESET "\x1b[10;19H" COLOR BRIGHT CSEP WHITE CEND "%s", storeMenu[8]);
		printf(RESET "\x1b[11;19H" COLOR BRIGHT CSEP WHITE CEND "%s", storeMenu[9]);
		printf(RESET "\x1b[12;19H" COLOR BRIGHT CSEP WHITE CEND "%s", storeMenu[10]);
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
	int storeMax = 4;
	int storeMin = 0;
	storeDisplay(storeDisp); //0 neutral 1 Down[MovesUp] 2 Up[MovesDown]
	storeDisp = 0;
	char returnvalue[30];
	while(true)
	{
		hidScanInput();
		hidWaitForEvent(HIDEVENT_PAD0, false);
		u32 kDown = hidKeysDown();
		u32 kDownOld = hidKeysDown();
		u32 kHeldOld = hidKeysHeld();
		u32 kUpOld = hidKeysHeld();
		if (selStore < storeMax)
		{
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
						storeDisp = 1;
						break;
					}
				}
				break;
			}
		}
		if (selStore > storeMin)
		{
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
						storeDisp = 2;
						break;
					}
				}
				break;
			}
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

/*bool inputEval(int step)
{
	hidScanInput();
	u32 kDown = hidKeysDown();
	bool bStep[11] = {(kDown & KEY_UP), (kDown & KEY_UP), (kDown & KEY_DOWN), (kDown & KEY_DOWN), (kDown & KEY_LEFT), (kDown & KEY_RIGHT), (kDown & KEY_LEFT), (kDown & KEY_RIGHT), (kDown & KEY_B), (kDown & KEY_A), (kDown & KEY_START)};
	if(bStep[step])
		return true;
	return false;
}*/

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
	//int step = 0;
	//int buttonDown = false;
	for (int i = 0; i < 420; i++)
	{
		/*hidScanInput();
		u32 kHeld = hidKeysHeld();
		bool bStep[11] = {(kHeld & KEY_UP), (kHeld & KEY_UP), (kHeld & KEY_DOWN), (kHeld & KEY_DOWN), (kHeld & KEY_LEFT), (kHeld & KEY_RIGHT), (kHeld & KEY_LEFT), (kHeld & KEY_RIGHT), (kHeld & KEY_B), (kHeld & KEY_A), (kHeld & KEY_START)};
		if(buttonDown)
		{
			printf("%d", step);
			if(!bStep[step])
			{
				buttonDown = false;
				step++;
			}
		}else{
			printf("%d", step);
			if(inputEval(step))
			{
				buttonDown = true;
			}
		}*/
		gspWaitForVBlank();
	}
	return 0;
}

char aboutArray[14][13] = {"            ", "            ", "            ", "            ", "  Matthew   ", "            ", "    ROT     ", "            ", "  History   ", "            ", "            ", "            ", "            ", "            "};
char aboutMenu[14][13] = {"            ", "            ", "            ", "            ", "            ", "            ", "            ", "            ", "            ", "            ", "            ", "            ", "            ", "            "};

std::string aboutStrings(int frame5, int line, int direction)
{
	//char * temp1 = new char[12];
	//char * temp2 = new char[12];
	//char * returnstr = new char[12];
	std::string temp1;
	std::string temp2;
	std::string returnstr;
	returnstr.clear();
	if (direction)
	{ //shift down
		if (frame5 < 11)
		{
			std::copy(&aboutMenu[line][0], &aboutMenu[line][11-frame5], back_inserter(temp1));
			std::copy(&aboutMenu[line-1][11-frame5], &aboutMenu[line-1][12], back_inserter(temp2));
			returnstr.append(temp1);
			returnstr.append(temp2);
		} else {
			std::copy(&aboutMenu[line-1][0], &aboutMenu[line-1][22-frame5], back_inserter(temp1));
			std::copy(&aboutMenu[line-2][22-frame5], &aboutMenu[line-2][12], back_inserter(temp2));
			returnstr.append(temp1);
			returnstr.append(temp2);
		}
	} else { //shift up
		if (frame5 < 11)
		{
			std::copy(&aboutMenu[line+1][0], &aboutMenu[line+1][frame5+1], back_inserter(temp1));
			std::copy(&aboutMenu[line][frame5+1], &aboutMenu[line][12], back_inserter(temp2));
			//sprintf(returnstr, "%s%s", temp1.c_str(), temp2.c_str());
			returnstr.append(temp1);
			returnstr.append(temp2);
		} else {
			std::copy(&aboutMenu[line+2][0], &aboutMenu[line+2][frame5-10], back_inserter(temp1));
			std::copy(&aboutMenu[line+1][frame5-10], &aboutMenu[line+1][12], back_inserter(temp2));
			//sprintf(returnstr, "%s%s", temp1.c_str(), temp2.c_str());
			returnstr.append(temp1);
			returnstr.append(temp2);
		}
	}
	consoleSelect(&bottomScreen);
	//printf("%s", returnstr.c_str());
	consoleSelect(&topScreen);
	return returnstr;
}

int aboutDisplay(int method)
{
	for(int i = 0; i < 13; i++)
		strcpy(aboutMenu[i], aboutArray[selAbout + i - 2]);
	if (method == 1)
	{
		for (int i = 0; i < 22; i++)
		{
			printf("\x1b[0;21H-About-");
			for(int n = 0; n < 4; n++)
			{
				printf("\x1b[%d;19H" COLOR BRIGHT CSEP WHITE CEND "%s", (n + 4), aboutStrings(i, (n + 2), 0).c_str());
				printf("\x1b[%d;19H" COLOR BRIGHT CSEP WHITE CEND "%s", (n + 9), aboutStrings(i, (n + 7), 0).c_str());
			}
			printf("\x1b[8;19H" RESET "%s", aboutStrings(i, 6, 0).c_str());
			gspWaitForVBlank();
		}
		method = 0;
		selAbout += 2;
	}
	if (method == 2)
	{
		for (int i = 0; i < 22; i++)
		{
			printf("\x1b[0;21H-About-");
			for(int n = 0; n < 4; n++)
			{
				printf("\x1b[%d;19H" COLOR BRIGHT CSEP WHITE CEND "%s", (n + 4), aboutStrings(i, (n + 2), 1).c_str());
				printf("\x1b[%d;19H" COLOR BRIGHT CSEP WHITE CEND "%s", (n + 9), aboutStrings(i, (n + 7), 1).c_str());
			}
			printf("\x1b[8;19H" RESET "%s", aboutStrings(i, 6, 1).c_str());
			gspWaitForVBlank();
		}
		method = 0;
		selAbout -= 2;
	}
	for(int i = 0; i < 13; i++)
		strcpy(aboutMenu[i], aboutArray[selAbout + i - 2]);
	if (method == 0)
	{
		printf("\x1b[0;21H-About-");
		printf(RESET "\x1b[4;19H" COLOR BRIGHT CSEP WHITE CEND "%s", aboutMenu[2]);
		printf(RESET "\x1b[5;19H" COLOR BRIGHT CSEP WHITE CEND "%s", aboutMenu[3]);
		printf(RESET "\x1b[6;19H" COLOR BRIGHT CSEP WHITE CEND "%s", aboutMenu[4]);
		printf(RESET "\x1b[7;19H" COLOR BRIGHT CSEP WHITE CEND "%s", aboutMenu[5]);
		printf(RESET "\x1b[8;19H" COLOR WHITE CEND "%s", aboutMenu[6]);
		printf(RESET "\x1b[9;19H" COLOR BRIGHT CSEP WHITE CEND "%s", aboutMenu[7]);
		printf(RESET "\x1b[10;19H" COLOR BRIGHT CSEP WHITE CEND "%s", aboutMenu[8]);
		printf(RESET "\x1b[11;19H" COLOR BRIGHT CSEP WHITE CEND "%s", aboutMenu[9]);
		printf(RESET "\x1b[12;19H" COLOR BRIGHT CSEP WHITE CEND "%s", aboutMenu[10]);
	}
	return 0;
}

int aboutOption()
{
	int result = 0;
	int returnvalue = 3;
	if (selAbout == 0)
	{
		while(true)
		{
			result = matthew();
			if (result == 0)
			{
				returnvalue = 0;
				break;
			}
			if (result == 2)
			{
				returnvalue = 2;
				break;
			}
		}
	}
	if (selAbout == 1)
	{
		while(true)
		{
			result = rot();
			if (result == 0)
			{
				returnvalue = 0;
				break;
			}
			if (result == 2)
			{
				returnvalue = 2;
				break;
			}
		}
	}
	if (selAbout == 2)
	{
		while(true)
		{
			result = timeline(result);
			if (result == 0)
			{
				returnvalue = 0;
				break;
			}
			if (result == 2)
			{
				returnvalue = 2;
				break;
			}
		}
	}
	return returnvalue;
}

int about(int upperrv)
{
	consoleClear();
	gspWaitForVBlank();
	int ireturnvalue = 0;
	consoleSelect(&bottomScreen);
	if (upperrv != 1)
		if (debugTF)
			printf("about opened\n");
	consoleSelect(&topScreen);
	consoleClear();
	int aboutMax = 4;
	int aboutMin = 0;
	aboutDisplay(aboutDisp); //0 neutral 1 Down[MovesUp] 2 Up[MovesDown]
	aboutDisp = 0;
	char returnvalue[30];
	while(true)
	{
		hidScanInput();
		hidWaitForEvent(HIDEVENT_PAD0, false);
		u32 kDown = hidKeysDown();
		u32 kDownOld = hidKeysDown();
		u32 kHeldOld = hidKeysHeld();
		u32 kUpOld = hidKeysHeld();
		if (selAbout < aboutMax)
		{
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
						aboutDisp = 1;
						break;
					}
				}
				break;
			}
		}
		if (selAbout > aboutMin)
		{
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
						aboutDisp = 2;
						break;
					}
				}
				break;
			}
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
						int result = aboutOption();
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