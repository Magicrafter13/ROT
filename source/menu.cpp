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
		return ANSI WHITE CEND;
	else
		return ANSI BRIGHT ASEP WHITE CEND;
}

const char * isSelectedTool(int tool)
{
	if (selTool == tool)
		return ANSI WHITE CEND;
	else
		return ANSI BRIGHT ASEP WHITE CEND;
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
			std::cout << "games opened\n";
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
	char otherArray[5][30];
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
	std::cout << CRESET "                   -Games List-\n\n";
	std::cout << CRESET " " << isSelectedGame(0) << "Battleship   = " << isLocked(Battleship) << " " CRESET "| " << isSelectedGame(1) << "Minesweeper = " << isLocked(Minesweeper) << "\n";
	std::cout << CRESET " " << isSelectedGame(2) << "Blackjack    = " << isLocked(Blackjack) << " " CRESET "| " << isSelectedGame(3) << "Mastermind  = " << isLocked(Mastermind) << "\n";
	std::cout << CRESET " " << isSelectedGame(4) << "Chess        = " << isLocked(Chess) << " " CRESET "| " << isSelectedGame(5) << "War         = " << isLocked(War) << "\n";
	std::cout << CRESET " " << isSelectedGame(6) << "Connect Four = " << isLocked(ConnectFour) << " " CRESET "| " << isSelectedGame(7) << "Nanogram    = " << isLocked(Nanogram) << "\n";
	std::cout << CRESET " " << isSelectedGame(8) << "Sudoku       = " << isLocked(Sudoku) << " " CRESET "| " << isSelectedGame(9) << "Mancala     = " << isLocked(Mancala) << "\n";
	std::cout << CRESET " " << isSelectedGame(10) << "Dodge Fall   = " << isLocked(DodgeFall) << " " CRESET "| " << isSelectedGame(11) << "Monopoly    = " << isLocked(Monopoly) << "\n";
	std::cout << CRESET " " << isSelectedGame(12) << "SlotMach     = " << isLocked(SlotMach) << " " CRESET "| " << isSelectedGame(13) << "Snake       = " << isLocked(Snake) << "\n";
	char returnvalue[30];
	while(true)
	{
		hidScanInput();
		u32 kDown = hidKeysDown();
		if (selGame < gameMax)
		{
			if (selGame % 2 == 0)
			{
				if (kDown & KEY_RIGHT)
				{
					
					sprintf(returnvalue, "RIGHT");
					selGame += 1;
					break;
				}
			}
		}
		if (selGame < gameMax - 1)
		{
			if (kDown & KEY_DOWN)
			{
				
				sprintf(returnvalue, "DOWN");
				selGame += 2;
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
					selGame -= 1;
					break;
				}
			}
		}
		if (selGame > gameMin + 1)
		{
			if (kDown & KEY_UP)
			{
				sprintf(returnvalue, "UP");
				selGame -= 2;
				break;
			}
		}
		if (kDown & KEY_START)
		{
			sprintf(returnvalue, "START");
			break;
		}
		if (strcmp(listArray[selTool], "Unlocked") == 0)
		{
			if (kDown & KEY_A)
			{
				sprintf(returnvalue, "A");
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
		if (kDown & KEY_B)
		{
			sprintf(returnvalue, "B");
			break;
		}
		gfxFlushBuffers();
		gfxSwapBuffers();
		gspWaitForVBlank();
	}
	if (strcmp(returnvalue, "START") == 0)
	{
		ireturnvalue = 2;
	}
	if (strcmp(returnvalue, "LEFT") == 0)
	{
		ireturnvalue = 1;
	}
	if (strcmp(returnvalue, "UP") == 0)
	{
		ireturnvalue = 1;
	}
	if (strcmp(returnvalue, "RIGHT") == 0)
	{
		ireturnvalue = 1;
	}
	if (strcmp(returnvalue, "DOWN") == 0)
	{
		ireturnvalue = 1;
	}
	if (strcmp(returnvalue, "A") == 0)
	{
		ireturnvalue = 1;
	}
	if (strcmp(returnvalue, "B") == 0)
	{
		ireturnvalue = 0;
	}
	gfxFlushBuffers();
	gfxSwapBuffers();
	gspWaitForVBlank();
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
			std::cout << "tools opened\n";
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
	std::cout << CRESET "                   -Tools List-\n\n";
	std::cout << "      " CRESET " " << isSelectedTool(0) << "Timer = " << isLocked(Timer) << " " CRESET "| " << isSelectedTool(1) << "Journal = " << isLocked(Journal) << "\n";
	std::cout << "      " CRESET " " << isSelectedTool(2) << "Pawn  = " << isLocked(Pawn) << " " CRESET "| " << isSelectedTool(3) << "Alarm   = " << isLocked(Alarm) << "\n";
	std::cout << "      " CRESET " " << isSelectedTool(4) << "Media = " << isLocked(Media) << "\n";
	char returnvalue[30];
	while(true)
	{
		hidScanInput();
		u32 kDown = hidKeysDown();
		if (selTool < toolMax)
		{
			if (selTool % 2 == 0)
			{
				if (kDown & KEY_RIGHT)
				{
					
					sprintf(returnvalue, "RIGHT");
					selTool += 1;
					break;
				}
			}
		}
		if (selTool < toolMax - 1)
		{
			if (kDown & KEY_DOWN)
			{
				
				sprintf(returnvalue, "DOWN");				
				selTool += 2;
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
					selTool -= 1;
					break;
				}
			}
		}
		if (selTool > toolMin + 1)
		{
			if (kDown & KEY_UP)
			{
				sprintf(returnvalue, "UP");
				selTool -= 2;
				break;
			}
		}
		if (kDown & KEY_START)
		{
			sprintf(returnvalue, "START");
			break;
		}
		if(strcmp(listArray[selTool], "Unlocked") == 0)
		{
			if (kDown & KEY_A)
			{
				sprintf(returnvalue, "A");
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
		if (kDown & KEY_B)
		{
			sprintf(returnvalue, "B");
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
			{
				std::cout << ANSI "0;20" PEND;
				printf("-" ANSI "%d" CEND "X" ANSI "%d" CEND "P " ANSI "%d" CEND "S" ANSI "%d" CEND "t" ANSI "%d" CEND "o" ANSI "%d" CEND "r" ANSI "%d" CEND "e" CRESET "-", iRandom1, iRandom2, iRandom3, iRandom4, iRandom5, iRandom6, iRandom7);
			}
			for(int n = 0; n < 4; n++)
			{
				printf(ANSI "%d;19" PEND ANSI BRIGHT ASEP WHITE CEND "%s", (n + 4), storeStrings(i, (n + 2), 0).c_str());
				printf(ANSI "%d;19" PEND ANSI BRIGHT ASEP WHITE CEND "%s", (n + 9), storeStrings(i, (n + 7), 0).c_str());
			}
			std::cout << ANSI "8;19" PEND CRESET << storeStrings(i, 6, 0).c_str();
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
			{
				std::cout << ANSI "0;20" PEND;
				printf("-" ANSI "%d" CEND "X" ANSI "%d" CEND "P " ANSI "%d" CEND "S" ANSI "%d" CEND "t" ANSI "%d" CEND "o" ANSI "%d" CEND "r" ANSI "%d" CEND "e" CRESET "-", iRandom1, iRandom2, iRandom3, iRandom4, iRandom5, iRandom6, iRandom7);
			}
			for(int n = 0; n < 4; n++)
			{
				printf(ANSI "%d;19" PEND ANSI BRIGHT ASEP WHITE CEND "%s", (n + 4), storeStrings(i, (n + 2), 1).c_str());
				printf(ANSI "%d;19" PEND ANSI BRIGHT ASEP WHITE CEND "%s", (n + 9), storeStrings(i, (n + 7), 1).c_str());
			}
			std::cout << ANSI "8;19" PEND CRESET << storeStrings(i, 6, 1).c_str();
			gspWaitForVBlank();
		}
		method = 0;
		selStore -= 2;
	}
	for(int i = 0; i < 13; i++)
		strcpy(storeMenu[i], storeArray[selStore + i - 2]);
	if (method == 0)
	{
		iRandom1 = rand() % 6 + 31;
		iRandom2 = rand() % 6 + 31;
		iRandom3 = rand() % 6 + 31;
		iRandom4 = rand() % 6 + 31;
		iRandom5 = rand() % 6 + 31;
		iRandom6 = rand() % 6 + 31;
		iRandom7 = rand() % 6 + 31;
		std::cout << ANSI "0;20" PEND;
		printf("-" ANSI "%d" CEND "X" CRESET ANSI "%d" CEND "P" CRESET " " ANSI "%d" CEND "S" CRESET ANSI "%d" CEND "t" CRESET ANSI "%d" CEND "o" CRESET ANSI "%d" CEND "r" CRESET ANSI "%d" CEND "e" CRESET "-", iRandom1, iRandom2, iRandom3, iRandom4, iRandom5, iRandom6, iRandom7);
		std::cout << CRESET ANSI "4;19" PEND ANSI BRIGHT ASEP WHITE CEND << storeMenu[2];
		std::cout << CRESET ANSI "5;19" PEND ANSI BRIGHT ASEP WHITE CEND << storeMenu[3];
		std::cout << CRESET ANSI "6;19" PEND ANSI BRIGHT ASEP WHITE CEND << storeMenu[4];
		std::cout << CRESET ANSI "7;19" PEND ANSI BRIGHT ASEP WHITE CEND << storeMenu[5];
		std::cout << CRESET ANSI "8;19" PEND ANSI WHITE CEND << storeMenu[6];
		std::cout << CRESET ANSI "9;19" PEND ANSI BRIGHT ASEP WHITE CEND << storeMenu[7];
		std::cout << CRESET ANSI "10;19" PEND ANSI BRIGHT ASEP WHITE CEND << storeMenu[8];
		std::cout << CRESET ANSI "11;19" PEND ANSI BRIGHT ASEP WHITE CEND << storeMenu[9];
		std::cout << CRESET ANSI "12;19" PEND ANSI BRIGHT ASEP WHITE CEND << storeMenu[10];
	}
	return 0;
}

int store(char userDir[30], int upperrv)
{
	int ireturnvalue = 0;
	consoleSelect(&bottomScreen);
	if (upperrv != 1)
		if (debugTF)
			std::cout << "store opened\n";
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
		if (selStore < storeMax)
		{
			if (kDown & KEY_DOWN)
			{
				
				sprintf(returnvalue, "DOWN");
				storeDisp = 1;
				break;
			}
		}
		if (selStore > storeMin)
		{
			if (kDown & KEY_UP)
			{
				sprintf(returnvalue, "UP");
				storeDisp = 2;
				break;
			}
		}
		if (kDown & KEY_START)
		{
			sprintf(returnvalue, "START");
			break;
		}
		if (kDown & KEY_A)
		{
			sprintf(returnvalue, "A");
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
		if (kDown & KEY_B)
		{
			sprintf(returnvalue, "B");
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
		std::cout << "credits opened\n";
	consoleSelect(&topScreen);
	consoleClear();
	std::cout << ANSI "0;21" PEND "Credits:";
	std::cout << ANSI "2;16" PEND ANSI RED CEND "-Lead Programmers-";
	std::cout << ANSI "3;18" PEND CRESET "Matthew Rease";
	std::cout << ANSI "5;17" PEND ANSI YELLOW CEND "-Alpha Testing-";
	std::cout << ANSI "6;18" PEND CRESET "Jared Freeman";
	std::cout << ANSI "8;17" PEND ANSI CYAN CEND "-Special Thanks-";
	std::cout << ANSI "9;10" PEND ANSI BRIGHT ASEP RED CEND "Smealum" CRESET " - " ANSI BRIGHT ASEP BLUE CEND "libctru" CRESET " and " ANSI BLUE CEND "homebrew";
	std::cout << ANSI "10;0" PEND CRESET "Aurelio Mannara +";
	std::cout << ANSI "11;16" PEND "- both-screen-text " ANSI BRIGHT ASEP BLUE CEND "libctru" CRESET " example";
	std::cout << ANSI "12;16" PEND "- colored-text " ANSI BRIGHT ASEP BLUE CEND "libctru" CRESET " example";
	std::cout << ANSI "13;16" PEND "- read-controls " ANSI BRIGHT ASEP BLUE CEND "libctru" CRESET " example";
	std::cout << ANSI "14;16" PEND "- touch-screen " ANSI BRIGHT ASEP BLUE CEND "libctru" CRESET " example";
	std::cout << ANSI "15;16" PEND "- multiple-windows-text " ANSI BRIGHT ASEP BLUE CEND "libctru" CRESET;
	std::cout << ANSI "16;43" PEND "example";
	std::cout << ANSI "17;4" PEND "fincs - software-keyboard " ANSI BRIGHT ASEP BLUE CEND "libctru" CRESET " example";
	std::cout << ANSI "18;14" PEND "And the people over at " ANSI BRIGHT ASEP YELLOW CEND "sourceforge," CRESET;
	std::cout << ANSI "19;12" PEND "helping me learn " ANSI GREEN CEND "C" CRESET " and " ANSI BRIGHT ASEP GREEN CEND "C++" CRESET;
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
		gfxFlushBuffers();
		gfxSwapBuffers();
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
				printf(ANSI "%d;19" PEND, (n + 4));
				std::cout << ANSI BRIGHT ASEP WHITE CEND << aboutStrings(i, (n + 2), 0).c_str();
				printf(ANSI "%d;19" PEND, (n + 9));
				std::cout << ANSI BRIGHT ASEP WHITE CEND << aboutStrings(i, (n + 7), 0).c_str();
			}
			std::cout << ANSI "8;19" PEND CRESET << aboutStrings(i, 6, 0).c_str();
			gspWaitForVBlank();
		}
		method = 0;
		selAbout += 2;
	}
	if (method == 2)
	{
		for (int i = 0; i < 22; i++)
		{
			std::cout << ANSI "0;21" PEND "-About-";
			for(int n = 0; n < 4; n++)
			{
				printf(ANSI "%d;19" PEND, (n + 4));
				std::cout << ANSI BRIGHT ASEP WHITE CEND << aboutStrings(i, (n + 2), 1).c_str();
				printf(ANSI "%d;19" PEND, (n + 9));
				std::cout << ANSI BRIGHT ASEP WHITE CEND << aboutStrings(i, (n + 7), 1).c_str();
			}
			std::cout << ANSI "8;19" PEND CRESET << aboutStrings(i, 6, 1).c_str();
			gspWaitForVBlank();
		}
		method = 0;
		selAbout -= 2;
	}
	for(int i = 0; i < 13; i++)
		strcpy(aboutMenu[i], aboutArray[selAbout + i - 2]);
	if (method == 0)
	{
		std::cout << ANSI "0;21" PEND "-About-";
		std::cout << CRESET ANSI "4;19" PEND ANSI BRIGHT ASEP WHITE CEND << aboutMenu[2];
		std::cout << CRESET ANSI "5;19" PEND ANSI BRIGHT ASEP WHITE CEND << aboutMenu[3];
		std::cout << CRESET ANSI "6;19" PEND ANSI BRIGHT ASEP WHITE CEND << aboutMenu[4];
		std::cout << CRESET ANSI "7;19" PEND ANSI BRIGHT ASEP WHITE CEND << aboutMenu[5];
		std::cout << CRESET ANSI "8;19" PEND ANSI WHITE CEND << aboutMenu[6];
		std::cout << CRESET ANSI "9;19" PEND ANSI BRIGHT ASEP WHITE CEND << aboutMenu[7];
		std::cout << CRESET ANSI "10;19" PEND ANSI BRIGHT ASEP WHITE CEND << aboutMenu[8];
		std::cout << CRESET ANSI "11;19" PEND ANSI BRIGHT ASEP WHITE CEND << aboutMenu[9];
		std::cout << CRESET ANSI "12;19" PEND ANSI BRIGHT ASEP WHITE CEND << aboutMenu[10];
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
	if (selAbout == 2)
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
	if (selAbout == 4)
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
			std::cout << "about opened\n";
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
		if (selAbout < aboutMax)
		{
			if (kDown & KEY_DOWN)
			{
				
				sprintf(returnvalue, "DOWN");
				aboutDisp = 1;
				break;
			}
		}
		if (selAbout > aboutMin)
		{
			if (kDown & KEY_UP)
			{
				sprintf(returnvalue, "UP");
				aboutDisp = 2;
				break;
			}
		}
		if (kDown & KEY_START)
		{
			sprintf(returnvalue, "START");
			break;
		}
		if (kDown & KEY_A)
		{
			sprintf(returnvalue, "A");
			while(true)
			{
				int result = aboutOption();
				if (result == 0)
					break;
				if (result == 2)
				{
					sprintf(returnvalue, "START");
					break;
				}
			}
			break;
		}
		if (kDown & KEY_B)
		{
			sprintf(returnvalue, "B");
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