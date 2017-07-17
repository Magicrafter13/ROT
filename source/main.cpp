#include "header.h"

//init
FS_Archive sdmcArchive;

void openSD()
{
	FSUSER_OpenArchive(&sdmcArchive, ARCHIVE_SDMC, fsMakePath(PATH_EMPTY, ""));
}

void closeSD()
{
	FSUSER_CloseArchive(sdmcArchive);
}

int selTool = 0;
int selGame = 0;
int selStore = 0;
int selAbout = 0;
int selTimeline = 0;
int debugTF = 1;
int storeDisp = 0;
int aboutDisp = 0;
char versiontxtt[6] = " Beta";
char versiontxtn[9] = " 1.04.6 ";
int versionnum = 0;
int vernumqik = 2;
int settingsVersion = 5;

int rotError()
{
	consoleSelect(&bottomScreen);
	std::cout << "ROT Error!\n" << "Check logs.\n";
	consoleSelect(&topScreen);
	consoleClear();
	std::cout << ANSI B_BLUE CEND;
	for(int i = 0; i < 1500; i++)
		std::cout << " ";
	std::cout << ANSI "2;11" PEND "ROT HAS ENCOUNTERED AN ERROR";
	std::cout << ANSI "5;16" PEND "Due to unknown circumstances:";
	std::cout << ANSI "6;5" PEND "One of ROT's subroutines returned with";
	std::cout << ANSI "7;5" PEND "an error code.";
	std::cout << ANSI "9;5" PEND "Common Questions:";
	std::cout << ANSI "10;5" PEND "What now? Either restart ROT, or submit";
	std::cout << ANSI "11;27" PEND "the log file.";
	std::cout << ANSI "12;5" PEND "Why did this happen? We have not yet";
	std::cout << ANSI "13;16" PEND "implemented an error handler.";
	std::cout << ANSI "14;5" PEND "Where is the log file? We have not yet";
	std::cout << ANSI "15;15" PEND "implemented a log file system.";
	std::cout << ANSI "27;14" PEND "Press any key to exit.";
	while(true)
	{
		hidScanInput();
		u32 kDown = hidKeysDown();
		if (kDown & KEY_START || kDown & KEY_SELECT || kDown & KEY_A || kDown & KEY_B || kDown & KEY_X || kDown & KEY_Y || kDown & KEY_UP || kDown & KEY_DOWN || kDown & KEY_LEFT || kDown & KEY_RIGHT || kDown & KEY_L || kDown & KEY_R || kDown & KEY_ZL || kDown & KEY_ZR || kDown & KEY_CSTICK_UP || kDown & KEY_CSTICK_DOWN || kDown & KEY_CSTICK_LEFT || kDown & KEY_CSTICK_RIGHT)
			break;
		gfxFlushBuffers();
		gfxSwapBuffers();
		gspWaitForVBlank();
	}
	return 0;
}

char menOption[5][25] = {"         Games          ", "        Tool Box        ", "        XP Store        ", "        Credits         ", "         About          "};
char setArray[9][17] = {"                ", "                ", "Change Password ", "Change Username ", "Delete Save Data", "      DLC       ", "  Toggle Debug  ", "                ", "                "};

bool touchInBox(touchPosition touch, int x, int y, int w, int h)
{
	int tx=touch.px;
	int ty=touch.py;
	u32 kDown = hidKeysDown();
	if (kDown & KEY_TOUCH && tx > x && tx < x+w && ty > y && ty < y+h) {
		return true;
	} else {
		return false;
	}
}

touchPosition touch;
bool logged = false, multiuser = false, killROT = false;
char sendusername[21];
int setsel = 0, mensel = 0, result = 0, returnvalue = 0;
int SMAX, SMIN, MMAX, MMIN;
FILE *userFile, *settingsFile;
char setfil[53], usrfil[53];
FILE *userfile;
FILE *fp;
char userdir[30];
char tempvar[30], dummy[5], username[21];
//sdmc:/3ds/ROT_Data/01234567890123456789/userdata.ruf max username length 20

PrintConsole topScreen, bottomScreen, versionWin;

int menuOption()
{
	returnvalue = 0;
	if (mensel == 0)
	{
		selGame = 0;
		while (true)
		{
			result = games(userdir, result);
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
	if (mensel == 1)
	{
		selTool = 0;
		while (true)
		{
			result = tools(userdir, result);
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
	if (mensel == 2)
	{
		while(true)
		{
			result = store(userdir, result);
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
	if (mensel == 3)
	{
		while (true)
		{
			result = credits();
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
	if (mensel == 4)
	{
		while (true)
		{
			result = about(result);
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
	std::cout << RESET "\n";
	consoleClear();
	gfxFlushBuffers();
	gfxSwapBuffers();
	gspWaitForVBlank();
	return returnvalue;
}

int settingsOption()
{
	returnvalue = 0;
	if (setsel == 0)
	{
		while (true)
		{
			result = changePassword(userdir);
			if (result == 0)
			{
				returnvalue = 0;
				break;
			}
			if (result == 2)
			{
				returnvalue = 1;
				break;
			}
		}
	}
	if (setsel == 1)
	{
		while (true)
		{
			result = changeUsername(userdir);
			if (result == 0)
			{
				returnvalue = 0;
				break;
			}
			if (result == 2)
			{
				returnvalue = 1;
				break;
			}
		}
	}
	if (setsel == 2)
	{
		while (true)
		{
			result = deleteData(userdir);
			if (result == 0)
			{
				returnvalue = 0;
				break;
			}
			if (result == 2)
			{
				returnvalue = 1;
				break;
			}
			if (result == 3)
			{
				returnvalue = 2;
				break;
			}
		}
	}
	if (setsel == 3)
	{
		while(true)
		{
			result = DLC(userdir);
			if (result == 0)
			{
				returnvalue = 0;
				break;
			}
			if (result == 2)
			{
				returnvalue = 1;
				break;
			}
		}
	}
	if (setsel == 4)
	{
		while(true)
		{
			result = debugView(userdir);
			if (result == 0)
			{
				returnvalue = 0;
				break;
			}
			if (result == 2)
			{
				returnvalue = 1;
				break;
			}
		}
	}
	return returnvalue;
}

int newSettingsFile(int hasEOF)
{
	if (hasEOF)
	{
		char dummyc[10];
		sprintf(setfil, "%s/settings.rsf", userdir);
		settingsFile = fopen(setfil, "r");
		fscanf(settingsFile, "%s %s %s %s", dummyc, dummyc, dummyc, dummyc);
		if (strcmp(dummyc, "-EOF") == 0)
			updateSF(userdir, false);
		else
			updateSF(userdir, true);
		fclose(settingsFile);
	} else {
		sprintf(setfil, "%s/settings.rsf", userdir);
		settingsFile = fopen(setfil, "w");
		fprintf(settingsFile, "%d\n", settingsVersion);
		fprintf(settingsFile, "%d\n", 1); //debugTrueOrFalse
		fprintf(settingsFile, "1\n-EOF-");
		fclose(settingsFile);
	}
	return 0;
}

int settings(int upperrv)
{
	int ireturnvalue;
	consoleSelect(&topScreen);
	FILE *fp, *userFile;
	sprintf(setfil, "%s/settings.rsf", userdir);
	if ((fp = fopen(setfil, "r")) == NULL)
	{
		newSettingsFile(0);
		return 1;
	}
	int oldversion, hasEOF;
	fscanf(fp, "%d %d %d", &oldversion, &debugTF, &hasEOF);
	fclose(fp);
	userFile = fopen(usrfil, "r");
	if (oldversion != settingsVersion)
	{
		newSettingsFile(hasEOF);
		return 1;
	}
	char dummy[30], username[30];
	fscanf(userFile, "%s %s %s", dummy, dummy, username);
	fclose(userFile);
	consoleSelect(&bottomScreen);
	if (upperrv != 1)
		if (debugTF)
			std::cout << username << " Opened Settings\n";
	char setOption[5][17];
	for (int i = 0; i < 5; i++)
		strcpy(setOption[i], setArray[setsel + i]);
	consoleSelect(&topScreen);
	consoleClear();
	std::cout << "\n\n\n\n\n\n\n\n";
	std::cout << "                 " ANSI BRIGHT ASEP WHITE CEND << setOption[0] << CRESET "\n\n";
	std::cout << "                 " << setOption[1] << "\n\n";
	std::cout << "        [A] Select   [B] Back to mainmenu         \n";
	std::cout << "               " ANSI B_WHITE ASEP BLACK CEND "                    " CRESET "               ";
	std::cout << "===============" ANSI B_WHITE ASEP BLACK CEND "  " << setOption[2] << "  " CRESET "===============";
	std::cout << "               " ANSI B_WHITE ASEP BLACK CEND "                    " CRESET "               ";
	std::cout << "                   [Start] Exit                   \n";
	std::cout << "                 " << setOption[3] << "\n\n";
	std::cout << "                 " ANSI BRIGHT ASEP WHITE CEND << setOption[4] << CRESET "\n\n";
	char returnvalue[30];
	while(true)
	{
		hidScanInput();
		u32 kDown = hidKeysDown();
		SMAX = 4;
		if (setsel < SMAX)
		{
			if (kDown & KEY_DOWN)
			{
				sprintf(returnvalue, "DOWN");
				setsel += 1;
				break;
			}
		}
		SMIN = 0;
		if (setsel > SMIN)
		{
			if (kDown & KEY_UP)
			{
				sprintf(returnvalue, "UP");
				setsel -= 1;
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
				result = settingsOption();
				if (result == 0)
					break;
				if (result == 1)
				{
					sprintf(returnvalue, "START");
					break;
				}
				if (result == 2)
				{
					sprintf(returnvalue, "ERROR");
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
		gfxFlushBuffers();
		gfxSwapBuffers();
		gspWaitForVBlank();
	}
	if (strcmp(returnvalue, "ERROR") == 0)
	{
		gfxFlushBuffers();
		gfxSwapBuffers();
		gspWaitForVBlank();
		ireturnvalue = 3;
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

int main(int argc, char **argv)
{
	std::ofstream testFile("sdmc:/3ds/testFile.txt");
	testFile << "test 2\n";
	testFile.close();
	hidInit();
	gfxInitDefault();
	fsInit();
	sdmcInit();
	consoleInit(GFX_TOP, &topScreen);
	consoleInit(GFX_BOTTOM, &bottomScreen);
	consoleInit(GFX_BOTTOM, &versionWin);
	
	consoleSetWindow(&versionWin, 13, 29, 27, 1);

	consoleSelect(&topScreen);
	std::cout << "ROT\n";

	consoleSelect(&bottomScreen);
	std::cout << "Loading...\n";
	
	consoleSelect(&versionWin);
	std::cout << "ROT Version: " ANSI GREEN CEND << versiontxtt << CRESET " " ANSI YELLOW CEND << versiontxtn;

	consoleSelect(&topScreen);
	std::cout << ANSI "29;15" PEND "by Matthew Rease\n";
	
	if(access("sdmc:/3ds/ROT_Data/isset.rvf", F_OK) == -1)
	{
		fclose(fp);
		bool usepass = false;
		char mybuf[21];
		consoleSelect(&bottomScreen);
		std::cout << "First Time Setup is Running\n";
		consoleSelect(&topScreen);
		consoleClear();
		std::cout << "Welcome to ROT!\n";
		std::cout << "Welcome, user\n";
		std::cout << "ROT is a hub of sorts, it will contain games,\ntools, etc. ";
		std::cout << "ROT stands for RFGEP On ThreeDS\n";
		std::cout << "RFGEP was a program I used to work on for Windows,if you want to check it out, go search it on\n";
		std::cout << "sourceforge. However I no longer update it,\n";
		std::cout << "because I got bored, and I lost my flashdrive containing all the code :/\n";
		std::cout << "You will now be guided through the setup process.\n";
		std::cout << "Press A to continue with setup.";
		while (true)
		{
			hidScanInput();
			u32 kDown = hidKeysDown();
			if (kDown & KEY_A) break;
			gfxFlushBuffers();
			gfxSwapBuffers();
			gspWaitForVBlank();
		}
		consoleClear();
		std::cout << "You are using ROT version: " << versiontxtt << versiontxtn << "\n";
		std::cout << "Would you like a password?\n";
		std::cout << "A - Yes | B - No\n";
		while (true)
		{
			hidScanInput();
			u32 kDown = hidKeysDown();
			if (kDown & KEY_START)
				break;
			bool didit = false;
			if (kDown & KEY_A)
			{
				didit = true;
				usepass = true;
				std::string tempss = "password";
				char * tempcs = new char[tempss.size() + 1];
				std::copy(tempss.begin(), tempss.end(), tempcs);
				tempcs[tempss.size()] = '\0';
				strcpy(mybuf, keyBoard(tempcs, 0, false));
				delete[] tempcs;
			}
			if (kDown & KEY_B)
			{
				didit = true;
				usepass = false;
			}

			if (didit)
			{
				if (usepass)
				{
					consoleSelect(&bottomScreen);
					std::cout << "Password set to: " << mybuf << "\n";
					consoleSelect(&topScreen);
				}
				break;
			}

			gfxFlushBuffers();
			gfxSwapBuffers();
			gspWaitForVBlank();
		}
		mkdir("sdmc:/3ds/ROT_Data/", 0777);
		fp = fopen("sdmc:/3ds/ROT_Data/userdata.ruf", "w");
		fputs("name = User\n", fp);
		fclose(fp);
		fp = fopen("sdmc:/3ds/ROT_Data/userdata.ruf", "a");
		if (usepass)
		{
			fprintf(fp, "%s %s %s \n", "pass", "=", mybuf);
		}else{
			fprintf(fp, "%s %s %s \n", "pass", "=", "none");
		}
		fprintf(fp, "version = %d \n", vernumqik);
		fprintf(fp, "color = 40 37 \n");
		fprintf(fp, "XP = 100 \n");
		fprintf(fp, "XPEarned = 100 \n");
		fprintf(fp, "lvl = 1 \n");
		fprintf(fp, "Battleship = 0 \n");
		fprintf(fp, "Blackjack = 0 \n");
		fprintf(fp, "Chess = 0 \n");
		fprintf(fp, "ConnectFour = 0 \n");
		fprintf(fp, "Sudoku = 0 \n");
		fprintf(fp, "DodgeFall = 0 \n");
		fprintf(fp, "Minesweeper = 0 \n");
		fprintf(fp, "Mastermind = 0 \n");
		fprintf(fp, "War = 0 \n");
		fprintf(fp, "Nanogram = 0 \n");
		fprintf(fp, "TTT = 0 \n");
		fprintf(fp, "Timer = 0 \n");
		fprintf(fp, "Mancala = 0 \n");
		fprintf(fp, "Monopoly = 0 \n");
		fprintf(fp, "Journal = 0 \n");
		fprintf(fp, "Pawn = 0 \n");
		fprintf(fp, "SlotMach = 0 \n");
		fprintf(fp, "Snake = 0 \n");
		fprintf(fp, "Alarm = 0 \n");
		fprintf(fp, "msg = 0 \n");
		fprintf(fp, "Media = 1 \n");
		fprintf(fp, "-EOF-");
		fclose(fp);
		fp = fopen("sdmc:/3ds/ROT_Data/isset.rvf", "w");
		fprintf(fp, "c");
		fclose(fp);
		consoleClear();
		consoleSelect(&bottomScreen);
		std::cout << "Option: ";
		consoleSelect(&topScreen);
		std::cout << "Press " ANSI RED CEND "A " RESET "to begin the walkthrough. Not added yet.\n";
		std::cout << "Press " ANSI YELLOW CEND "B " RESET "to continue to program.\n";
		bool walkthrough;
		while(true)
		{
			hidScanInput();
			u32 kDown = hidKeysDown();
			if (kDown & KEY_A)
			{
				walkthrough = true;
				consoleSelect(&bottomScreen);
				std::cout << "A\n";
				consoleSelect(&topScreen);
				gfxFlushBuffers();
				gfxSwapBuffers();
				gspWaitForVBlank();
				break;
			}
			if (kDown & KEY_B)
			{
				walkthrough = false;
				consoleSelect(&bottomScreen);
				std::cout << "B\n";
				consoleSelect(&topScreen);
				gfxFlushBuffers();
				gfxSwapBuffers();
				gspWaitForVBlank();
				break;
			}
		}
		if (walkthrough)
		{
			std::cout << "NOT ADDED YET\n";
		}
	}
	
	// Main loop
	while (aptMainLoop())
	{
		hidScanInput();
		hidTouchRead(&touch);
		u32 kDown = hidKeysDown();
		if (logged == false)
		{
			if ((fp = fopen("sdmc:/3ds/ROT_Data/userdata.ruf", "r")) == NULL)
			{
				fclose(fp);
				std::cout << "USER DATA NOT FOUND :(\n";
				std::cout << "Multi User Feature not added yet.\n";
				break;
			} else {
				std::cout << "Data found\n";
				userFile = fopen("sdmc:/3ds/ROT_Data/userdata.ruf", "r");
				char t1[4], t2[1], t3[30], t4[4], t5[1], t6[30];
				fscanf(userFile, "%s %s %s %s %s %s", t1, t2, username, t4, t5, t6);
				sprintf(sendusername, "%s", t3);
				bool incorrect = true;
				std::cout << "Press A to open keyboard to enter password\n";
				static char mybuf[21];
				bool didit = false;
				while (incorrect)
				{
					hidScanInput();
					u32 kDown = hidKeysDown();
					if (didit)
					{
						logged = true;
						consoleSelect(&bottomScreen);
						std::cout << t3 << " Logged in\n";
						incorrect = false;
						break;
					}
					if (kDown & KEY_A)
					{
						std::string tempss = "password";
						char * tempcs = new char[tempss.size() + 1];
						std::copy(tempss.begin(), tempss.end(), tempcs);
						tempcs[tempss.size()] = '\0';
						strcpy(mybuf, keyBoard(tempcs, 0, false));
						delete[] tempcs;
						if (strcmp(mybuf, t6) == 0)
						{
							didit = true;
						}
						gfxFlushBuffers();
						gfxSwapBuffers();
						gspWaitForVBlank();
					}
				}
			}
		}else{
			
			//Main Program
			if (multiuser)
			{
				sprintf(userdir, "sdmc:/3ds/ROT_Data/%s", sendusername);
			}else{
				sprintf(userdir, "sdmc:/3ds/ROT_Data");
			}
			sprintf(setfil, "%s/settings.rsf", userdir);
			sprintf(usrfil, "%s/userdata.ruf", userdir);
			settingsFile = fopen(setfil, "r");
			userFile = fopen(usrfil, "r");
			consoleSelect(&bottomScreen);
			sprintf(tempvar, "%s/userdata.ruf", userdir);
			userfile = fopen(tempvar, "r");
			fscanf(userfile, "%s %s %s", dummy, dummy, username);
			int initFindUpdt = 0;
			int idummy;
			for(int i = 0; i < 100; i++)
			{
				fscanf(userfile, "%s", dummy);
				if(strcmp(dummy, "version") == 0)
					initFindUpdt = 1;
			}
			if(!initFindUpdt)
				updateUF(userdir, 0);
			if(initFindUpdt)
			{
				fscanf(userfile, "%s %d", dummy, &idummy);
				if(idummy != vernumqik)
					updateUF(userdir, idummy);
			}
			fclose(settingsFile);
			fclose(userFile);
			fclose(userfile);
			consoleSelect(&topScreen);
			consoleClear();
			gspWaitForVBlank();
			std::cout << "###                                            ###";
			std::cout << " ###                                          ### ";
			std::cout << "  ###            [Select] Log-off            ###  ";
			std::cout << "   ###                                      ###   ";
			std::cout << "    ###                                    ###    ";
			std::cout << "     ###                                  ###     ";
			std::cout << "      ###                                ###      ";
			std::cout << "       ###         [X] Settings         ###       ";
			std::cout << "        ###                            ###        ";
			std::cout << "         ###                          ###         ";
			std::cout << "          ###                        ###          ";
			std::cout << "           ############################           ";
			std::cout << "           ##                        ##           ";
			std::cout << "           ##                        ##           ";
			std::cout << " [<] Left  ##";
			printf("\x1b[%dm", mensel + 31);
			std::cout << menOption[mensel] << CRESET "## Right [>] ";
			std::cout << "           ##                        ##           ";
			std::cout << "           ##                        ##           ";
			std::cout << "           ############################           ";
			std::cout << "          ###                        ###          ";
			std::cout << "         ###        [A] Select        ###         ";
			std::cout << "        ###                            ###        ";
			std::cout << "       ###                              ###       ";
			std::cout << "      ###                                ###      ";
			std::cout << "     ###             Messages             ###     ";
			std::cout << "    ###                [00]                ###    ";
			std::cout << "   ###               [Y] View               ###   ";
			std::cout << "  ###                                        ###  ";
			std::cout << " ###                                          ### ";
			std::cout << "###                                            ###";
			std::cout << username << " Logged in:";
			gspWaitForVBlank();
			//hidWaitForEvent(HIDEVENT_PAD0, false);
			while(true)
			{
				hidScanInput();
				u32 kDown = hidKeysDown();
				if (kDown & KEY_Y)
				{
					while(true)
					{
						result = mail(userdir);
						if (result == 2)
						{
							killROT = true;
							break;
						}
						if (result == 0)
						{
							break;
						}
					}
					break;
				}
				if (kDown & KEY_SELECT)
				{
					logged = false;
					break;
				}
				MMAX = 4;
				if (mensel < MMAX)
				{
					if (kDown & KEY_RIGHT)
					{
						mensel += 1;
						break;
					}
				}
				MMIN = 0;
				if (mensel > MMIN)
				{
					if (kDown & KEY_LEFT)
					{
						mensel -= 1;
						break;
					}
				}
				if (kDown & KEY_START)
				{
					killROT = true;
					break;
				}
				if (kDown & KEY_A)
				{
					while(true)
					{
						result = menuOption();
						if (result == 0)
							break;
						if (result == 2)
						{
							killROT = true;
							break;
						}
					}
					break;
				}
				if (kDown & KEY_X)
				{
					setsel = 0;
					while(true)
					{
						result = settings(result);
						if (result == 0)
							break;
						if (result == 2)
						{
							killROT = true;
							break;
						}
						if (result == 3)
						{
							rotError();
							killROT = true;
							break;
						}
					}
					break;
				}
				gfxFlushBuffers();
				gfxSwapBuffers();
				gspWaitForVBlank();
			}
		}

		if (kDown & KEY_START) killROT = true; // break in order to return to hbmenu
		
		if (killROT) break;

		// Flush and swap framebuffers
		gfxFlushBuffers();
		gfxSwapBuffers();

		//Wait for VBlank
		gspWaitForVBlank();
		
		/*if(touchInBox(touch, 239, 217, 81, 24)) {
			printf("touched");
			break;
		}*/
	}

	// Exit services
	hidExit();
	gfxExit();
	fsExit();
	sdmcExit();
	
	return 0;
}