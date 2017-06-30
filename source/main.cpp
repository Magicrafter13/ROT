#include "header.h"

//init
int selTool = 0;
int selGame = 0;
int selStore = 0;
int debugTF = 1;
int storeDisp = 0;
char versiontxtt[6] = " Beta";
char versiontxtn[9] = " 1.00.0 ";
int versionnum = 0;
int vernumqik = 2;
int settingsVersion = 5;

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
char tempvar[30], dummy[5], username[21], menOption[40];
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
	printf(RESET "\n");
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
	char setOption[17], setOptionP1[17], setOptionN1[17], setOptionP2[17], setOptionN2[17];
	char dummy[30], username[30];
	fscanf(userFile, "%s %s %s", dummy, dummy, username);
	fclose(userFile);
	consoleSelect(&bottomScreen);
	if (upperrv != 1)
		if (debugTF)
			printf("%s Opened Settings\n", username);
	if (setsel == 0)
	{
		strcpy(setOption, "Change Password ");
		strcpy(setOptionP1, "                ");
		strcpy(setOptionN1, "Change Username ");
		strcpy(setOptionP2, "                ");
		strcpy(setOptionN2, "Delete Save Data");
	}
	if (setsel == 1)
	{
		strcpy(setOption, "Change Username ");
		strcpy(setOptionP1, "Change Password ");
		strcpy(setOptionN1, "Delete Save Data");
		strcpy(setOptionP2, "                ");
		strcpy(setOptionN2, "      DLC       ");
	}
	if (setsel == 2)
	{
		strcpy(setOption, "Delete Save Data");
		strcpy(setOptionP1, "Change Username ");
		strcpy(setOptionN1, "      DLC       ");
		strcpy(setOptionP2, "Change Password ");
		strcpy(setOptionN2, "  Toggle Debug  ");
	}
	if (setsel == 3)
	{
		strcpy(setOption, "      DLC       ");
		strcpy(setOptionP1, "Delete Save Data");
		strcpy(setOptionN1, "  Toggle Debug  ");
		strcpy(setOptionP2, "Change Username ");
		strcpy(setOptionN2, "                ");
	}
	if (setsel == 4)
	{
		strcpy(setOption, "  Toggle Debug  ");
		strcpy(setOptionP1, "      DLC       ");
		strcpy(setOptionN1, "                ");
		strcpy(setOptionP2, "Delete Save Data");
		strcpy(setOptionN2, "                ");
	}
	consoleSelect(&topScreen);
	consoleClear();
	printf("\n\n\n\n\n\n\n\n");
	printf("                 \x1b[2;37m%s\x1b[0m\n\n", setOptionP2);
	printf("                 %s\n\n", setOptionP1);
	printf("        [A] Select   [B] Back to mainmenu         \n");
	printf("               \x1b[47;30m                    \x1b[0m               ");
	printf("===============\x1b[47;30m  %s  \x1b[0m===============", setOption);
	printf("               \x1b[47;30m                    \x1b[0m               ");
	printf("                   [Start] Exit                   \n");
	printf("                 %s\n\n", setOptionN1);
	printf("                 \x1b[2;37m%s\x1b[0m\n\n", setOptionN2);
	char returnvalue[30];
	while(true)
	{
		hidScanInput();
		u32 kDown = hidKeysDown();
		u32 kDownOld = hidKeysDown();
		u32 kHeldOld = hidKeysHeld();
		u32 kUpOld = hidKeysHeld();
		SMAX = 4;
		if (setsel < SMAX)
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
						setsel += 1;
						break;
					}
				}
				break;
			}
		}
		SMIN = 0;
		if (setsel > SMIN)
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
						setsel -= 1;
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
						result = settingsOption();
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

int main(int argc, char **argv)
{
	hidInit();
	gfxInitDefault();
	consoleInit(GFX_TOP, &topScreen);
	consoleInit(GFX_BOTTOM, &bottomScreen);
	consoleInit(GFX_BOTTOM, &versionWin);
	
	consoleSetWindow(&versionWin, 13, 29, 27, 1);

	consoleSelect(&topScreen);
	printf("ROT\n");

	consoleSelect(&bottomScreen);
	printf("Loading...\n");
	
	consoleSelect(&versionWin);
	printf("ROT Version: " COLOR GREEN CEND "%s" RESET " " COLOR YELLOW CEND "%s", versiontxtt, versiontxtn);

	consoleSelect(&topScreen);
	printf("\x1b[29;15Hby Matthew Rease\n");
	
	if(access("sdmc:/3ds/ROT_Data/isset.rvf", F_OK) == -1)
	{
		fclose(fp);
		bool usepass = false;
		char mybuf[21];
		consoleSelect(&bottomScreen);
		printf("First Time Setup is Running\n");
		consoleSelect(&topScreen);
		consoleClear();
		printf("Welcome to ROT!\n");
		printf("Welcome, user\n");
		printf("ROT is a hub of sorts, it will contain games,\ntools, etc. ");
		printf("ROT stands for RFGEP On ThreeDS\n");
		printf("RFGEP was a program I used to work on for Windows,if you want to check it out, go search it on\nsourceforge. However I no longer update it,\nbecause I got bored, and I lost my flashdrive containing all the code :/\n");
		printf("You will now be guided through the setup process.\n");
		printf("Press A to continue with setup.");
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
		printf("You are using ROT version: ");
		printf(versiontxtt);
		printf(versiontxtn);
		printf("\n");
		printf("Would you like a password?\n");
		printf("A - Yes | B - No\n");
		while (true)
		{
			hidScanInput();
			u32 kDown = hidKeysDown();
			if (kDown & KEY_START)
				break;
			//static SwkbdState swkbd;
			//SwkbdButton button = SWKBD_BUTTON_NONE;
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
					printf("Password set to: ");
					std::cout << mybuf;
					//printf(mybuf);
					printf("\n");
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
		fprintf(fp, "version = %d\n", vernumqik);
		fprintf(fp, "color = 40 37 \n");
		fprintf(fp, "XP = %d \n", 100);
		fprintf(fp, "XPEarned = %d \n", 100);
		fprintf(fp, "lvl = %d \n", 1);
		fprintf(fp, "Battleship = %d \n", 0);
		fprintf(fp, "Blackjack = %d \n", 0);
		fprintf(fp, "Chess = %d \n", 0);
		fprintf(fp, "ConnectFour = %d \n", 0);
		fprintf(fp, "Sudoku = %d \n", 0);
		fprintf(fp, "DodgeFall = %d \n", 0);
		fprintf(fp, "Minesweeper = %d \n", 0);
		fprintf(fp, "Mastermind = %d \n", 0);
		fprintf(fp, "War = %d \n", 0);
		fprintf(fp, "Nanogram = %d \n", 0);
		fprintf(fp, "TTT = %d \n", 0);
		fprintf(fp, "Timer = %d \n", 0);
		fprintf(fp, "Mancala = %d \n", 0);
		fprintf(fp, "Monopoly = %d \n", 0);
		fprintf(fp, "Journal = %d \n", 0);
		fprintf(fp, "Pawn = %d \n", 0);
		fprintf(fp, "SlotMach = %d \n", 0);
		fprintf(fp, "Snake = %d \n", 0);
		fprintf(fp, "Alarm = %d \n", 0);
		fprintf(fp, "msg = %d \n", 0);
		fprintf(fp, "Media = %d\n", 1);
		fprintf(fp, "-EOF-");
		fclose(fp);
		fp = fopen("sdmc:/3ds/ROT_Data/isset.rvf", "w");
		fprintf(fp, "c");
		fclose(fp);
		//Remember this for colors:
		//\x1b[back;textm(then the text)
		//30-37 for text 40-47 for back
		//0 = Black 1 = Red 2 = Green 3 = Yellow 4 = Blue 5 = Magenta 6 = Cyan 7 = White
		consoleClear();
		consoleSelect(&bottomScreen);
		printf("Option: ");
		consoleSelect(&topScreen);
		printf("Press \x1b[40;31mA \x1b[40;37mto begin the walkthrough. Not added yet.\n");
		printf("Press \x1b[40;33mB \x1b[40;37mto continue to program.\n");
		bool walkthrough;
		while(true)
		{
			hidScanInput();
			u32 kDown = hidKeysDown();
			if (kDown & KEY_A)
			{
				walkthrough = true;
				consoleSelect(&bottomScreen);
				printf("A\n");
				consoleSelect(&topScreen);
				break;
			}
			if (kDown & KEY_B)
			{
				walkthrough = false;
				consoleSelect(&bottomScreen);
				printf("B\n");
				consoleSelect(&topScreen);
				break;
			}
		}
		if (walkthrough)
		{
			printf("NOT ADDED YET\n");
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
				printf("USER DATA NOT FOUND :(\n");
				printf("Multi User Feature not added yet.\n");
				break;
			} else {
				printf("Data found\n");
				userFile = fopen("sdmc:/3ds/ROT_Data/userdata.ruf", "r");
				char t1[4], t2[1], t3[30], t4[4], t5[1], t6[30];
				fscanf(userFile, "%s %s %s %s %s %s", t1, t2, t3, t4, t5, t6);
				sprintf(sendusername, "%s", t3);
				bool incorrect = true;
				printf("Press A to open keyboard to enter password\n");
				static char mybuf[21];
				bool didit = false;
				while (incorrect)
				{
					hidScanInput();
					u32 kDown = hidKeysDown();
					if (didit)
					{
						logged = true;
						printf("Log in Successful");
						consoleSelect(&bottomScreen);
						printf("%s Logged in\n", t3);
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
			//printf("&userdir/userdata.ruf");
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
			if (mensel == 0)
			{
				strcpy(menOption, "\x1b[31m         Games          \x1b[0m");
			}
			if (mensel == 1)
			{
				strcpy(menOption, "\x1b[32m        Tool Box        \x1b[0m");
			}
			if (mensel == 2)
			{
				strcpy(menOption, "\x1b[33m        XP Store        \x1b[0m");
			}
			if (mensel == 3)
			{
				strcpy(menOption, "\x1b[34m        Credits         \x1b[0m");
			}
			printf("###                                            ###");
			printf(" ###                                          ### ");
			printf("  ###            [Select] Log-off            ###  ");
			printf("   ###                                      ###   ");
			printf("    ###                                    ###    ");
			printf("     ###                                  ###     ");
			printf("      ###                                ###      ");
			printf("       ###         [X] Settings         ###       ");
			printf("        ###                            ###        ");
			printf("         ###                          ###         ");
			printf("          ###                        ###          ");
			printf("           ############################           ");
			printf("           ##                        ##           ");
			printf("           ##                        ##           ");
			printf(" [<] Left  ##%s## Right [>] ", menOption);
			printf("           ##                        ##           ");
			printf("           ##                        ##           ");
			printf("           ############################           ");
			printf("          ###                        ###          ");
			printf("         ###        [A] Select        ###         ");
			printf("        ###                            ###        ");
			printf("       ###                              ###       ");
			printf("      ###                                ###      ");
			printf("     ###             Messages             ###     ");
			printf("    ###                [00]                ###    ");
			printf("   ###               [Y] View               ###   ");
			printf("  ###                                        ###  ");
			printf(" ###                                          ### ");
			printf("###                                            ###");
			printf("%s Logged in:", username);
			//hidWaitForEvent(HIDEVENT_PAD0, false);
			while(true)
			{
				hidScanInput();
				u32 kDown = hidKeysDown();
				u32 kDownOld = hidKeysDown();
				u32 kHeldOld = hidKeysHeld();
				u32 kUpOld = hidKeysHeld();
				if (kDown & KEY_Y)
				{
					while(true)
					{
						hidScanInput();
						u32 kDown = hidKeysDown();
						if (kDown != kDownOld)
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
					}
					break;
				}
				if (kDown & KEY_SELECT)
				{
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
					logged = false;
					break;
				}
				MMAX = 3;
				if (mensel < MMAX)
				{
					if (kDown & KEY_RIGHT)
					{
						
						while(true)
						{
							hidScanInput();
							u32 kDown = hidKeysDown();
							u32 kHeld = hidKeysHeld();
							u32 kUp = hidKeysUp();
							if (kDown != kDownOld && kHeld != kHeldOld && kUp != kUpOld)
							{
								mensel += 1;
								break;
							}
						}
						break;
					}
				}
				MMIN = 0;
				if (mensel > MMIN)
				{
					if (kDown & KEY_LEFT)
					{
						while(true)
						{
							hidScanInput();
							u32 kDown = hidKeysDown();
							u32 kHeld = hidKeysHeld();
							u32 kUp = hidKeysUp();
							if (kDown != kDownOld && kHeld != kHeldOld && kUp != kUpOld)
							{
								mensel -= 1;
								break;
							}
						}
						break;
					}
				}
				if (kDown & KEY_START)
				{
					while(true)
					{
						hidScanInput();
						u32 kDown = hidKeysDown();
						u32 kHeld = hidKeysHeld();
						u32 kUp = hidKeysUp();
						if (kDown != kDownOld && kHeld != kHeldOld && kUp != kUpOld)
						{
							killROT = true;
							break;
						}
					}
					break;
				}
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
					}
					break;
				}
				if (kDown & KEY_X)
				{
					setsel = 0;
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
								result = settings(result);
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
					}
					break;
				}
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
	
	return 0;
}