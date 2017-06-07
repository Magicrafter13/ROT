/*
	Both Screen Text example made by Aurelio Mannara for ctrulib
	This code was modified for the last time on: 12/12/2014 23:20 UTC+1

*/

#include <3ds.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
int mkdir(const char *pathname, mode_t mode);

char versiontxt[10] = "Alpha 1.3";
int versionnum = 0;
touchPosition touch;
int selection;
bool logged = false;
bool multiuser = false;
char sendusername[30];
bool killROT = false;

static SwkbdCallbackResult MyCallback(void* user, const char** ppMessage, const char* text, size_t textlen)
{
	return SWKBD_CALLBACK_OK;
}

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

int main(int argc, char **argv)
{
	// Initialize services
	gfxInitDefault();
	hidInit();

	//In this example we need one PrintConsole for each screen
	PrintConsole topScreen, bottomScreen;

	//Initialize console for both screen using the two different PrintConsole we have defined
	consoleInit(GFX_TOP, &topScreen);
	consoleInit(GFX_BOTTOM, &bottomScreen);

	//Before doing any text printing we should select the PrintConsole in which we are willing to write, otherwise the library will print on the last selected/initialized one
	//Let's start by printing something on the top screen
	consoleSelect(&topScreen);
	printf("ROT\n");

	//Now write something else on the bottom screen
	consoleSelect(&bottomScreen);
	printf("Loading...\n");

	consoleSelect(&topScreen);
	printf("\x1b[29;15Hby Matthew Rease");
	
	FILE *fp;
	FILE *userdata;
	if ((fp = fopen("sdmc:/ROT_Data/isset.rvf", "r")) == NULL)
	{
		bool usepass = false;
		static char mybuf[60];
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
			//Scan all the inputs. This should be done once for each frame
			hidScanInput();

			//hidKeysDown returns information about which buttons have been just pressed (and they weren't in the previous frame)
			u32 kDown = hidKeysDown();

			if (kDown & KEY_A) break; // break in order to return to hbmenu

			// Flush and swap framebuffers
			gfxFlushBuffers();
			gfxSwapBuffers();

			//Wait for VBlank
			gspWaitForVBlank();
		}
		consoleClear();
		printf("You are using ROT version: ");
		printf(versiontxt);
		printf("\n");
		printf("Would you like a password?\n");
		printf("A - Yes | B - No\n");
		while (true)
		{
			hidScanInput();
			u32 kDown = hidKeysDown();
			if (kDown & KEY_START)
				break;
			static SwkbdState swkbd;
			SwkbdButton button = SWKBD_BUTTON_NONE;
			bool didit = false;
			if (kDown & KEY_A)
			{
				didit = true;
				usepass = true;
				swkbdInit(&swkbd, SWKBD_TYPE_WESTERN, 1, -1);
				swkbdSetValidation(&swkbd, SWKBD_NOTEMPTY_NOTBLANK, SWKBD_FILTER_DIGITS | SWKBD_FILTER_AT | SWKBD_FILTER_PERCENT | SWKBD_FILTER_BACKSLASH | SWKBD_FILTER_PROFANITY, 2);
				swkbdSetFeatures(&swkbd, SWKBD_MULTILINE);
				swkbdSetFilterCallback(&swkbd, MyCallback, NULL);
				swkbdSetHintText(&swkbd, "password");
				button = swkbdInputText(&swkbd, mybuf, sizeof(mybuf));
			}
			if (kDown & KEY_B)
			{
				didit = true;
				usepass = false;
			}

			if (didit)
			{
				if (button != SWKBD_BUTTON_NONE)
				{
					consoleSelect(&bottomScreen);
					printf("Password set to: ");
					printf(mybuf);
					printf("\n");
					consoleSelect(&topScreen);
					break;
				} else {
					printf("swkbd event: %d\n", swkbdGetResult(&swkbd));
					break;
				}
			}

			// Flush and swap framebuffers
			gfxFlushBuffers();
			gfxSwapBuffers();

			gspWaitForVBlank();
		}
		mkdir("sdmc:/3ds/ROT_Data/", 0777);
		/*fp = fopen("sdmc:/3ds/ROT_Data/isset.rvf", "w");
		putc("c",fp);
		fclose(fp);*/
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
		fprintf(fp, "color = 40;37 \n");
		fprintf(fp, "XP = %d \n", 100);
		fprintf(fp, "XPEarned = %d \n", 100);
		fprintf(fp, "lvl = %d \n", 1);
		fprintf(fp, "Battleship = %d \n", 0);
		fprintf(fp, "Blackjack = %d \n", 0);
		fprintf(fp, "Chess = %d \n", 0);
		fprintf(fp, "ConnectFour = %d \n", 0);
		fprintf(fp, "DOND = %d \n", 0);
		fprintf(fp, "FakeVirus = %d \n", 0);
		fprintf(fp, "GTA = %d \n", 0);
		fprintf(fp, "Sudoku = %d \n", 0);
		fprintf(fp, "DodgeFall = %d \n", 0);
		fprintf(fp, "Stress = %d \n", 0);
		fprintf(fp, "Minesweeper = %d \n", 0);
		fprintf(fp, "Mastermind = %d \n", 0);
		fprintf(fp, "War = %d \n", 0);
		fprintf(fp, "Nanogram = %d \n", 0);
		fprintf(fp, "TTT = %d \n", 0);
		fprintf(fp, "RC = %d \n", 0);
		fprintf(fp, "RPS = %d \n", 0);
		fprintf(fp, "Timer = %d \n", 0);
		fprintf(fp, "WorkLock = %d \n", 0);
		fprintf(fp, "Mancala = %d \n", 0);
		fprintf(fp, "Monopoly = %d \n", 0);
		fprintf(fp, "NGG = %d \n", 0);
		fprintf(fp, "Journal = %d \n", 0);
		fprintf(fp, "Pawn = %d \n", 0);
		fprintf(fp, "SlotMach = %d \n", 0);
		fprintf(fp, "Snake = %d \n", 0);
		fprintf(fp, "Trivia = %d \n", 0);
		fprintf(fp, "Alarm = %d \n", 0);
		fprintf(fp, "msg = %d \n", 0);
		fclose(fp);
		/*int c;
		fp = fopen("sdmc:/3ds/ROT_Data/userdata.ruf", "r");
		while(1)
		{
			c = fgetc(fp);
			if(feof(fp))
			{
				break;
			}
			printf("%c", c);
		}*/
		//Remember this for colors:
		//\x1b[back;textm(then the text)
		//30-37 for text 40-47 for back
		//0 = Black 1 = Red 2 = Green 3 = Yellow 4 = Blue 5 = Magenta 6 = Cyan 7 = White
		fclose(fp);
		/*printf("Test with fresh variables:\n");
		char name1[4], name2[1], name3[30], pass1[4], pass2[1], pass3[30];
		fp = fopen("sdmc:/3ds/ROT_Data/userdata.ruf", "r");
		fscanf(fp, "%s %s %s %s %s %s", name1, name2, name3, pass1, pass2, pass3);
		fclose(fp);
		printf("%s %s %s %s %s %s", name1, name2, name3, pass1, pass2, pass3);*/
		consoleClear();
		consoleSelect(&bottomScreen);
		consoleClear();
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
				break;
			}
			if (kDown & KEY_B)
			{
				walkthrough = false;
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
		FILE *userfile;
		//Scan all the inputs. This should be done once for each frame
		hidScanInput();
		hidTouchRead(&touch);

		//hidKeysDown returns information about which buttons have been just pressed (and they weren't in the previous frame)
		
		u32 kDown = hidKeysDown();
		if (logged == false)
		{
			if ((fp = fopen("sdmc:/3ds/ROT_Data/userdata.ruf", "r")) == NULL)
			{
				printf("USER DATA NOT FOUND :(\n");
				printf("Multi User Feature not added yet.\n");
				break;
			} else {
				printf("Data found\n");
				userdata = fopen("sdmc:/3ds/ROT_Data/userdata.ruf", "r");
				char t1[4], t2[1], t3[30], t4[4], t5[1], t6[30];
				fscanf(userdata, "%s %s %s %s %s %s", t1, t2, t3, t4, t5, t6);
				sprintf(sendusername, "%s", t3);
				bool incorrect = true;
				printf("Press A to open keyboard to enter password\n");
				static char mybuf[30];
				bool didit = false;
				while (incorrect)
				{
					hidScanInput();
					u32 kDown = hidKeysDown();
					static SwkbdState swkbd;
					SwkbdButton button = SWKBD_BUTTON_NONE;
					if (didit)
					{
						logged = true;
						printf("Log in Successful");
						consoleSelect(&bottomScreen);
						printf("User Logged in");
						incorrect = false;
						break;
					}
					if (kDown & KEY_A)
					{
						swkbdInit(&swkbd, SWKBD_TYPE_WESTERN, 1, -1);
						swkbdSetValidation(&swkbd, SWKBD_NOTEMPTY_NOTBLANK, SWKBD_FILTER_DIGITS | SWKBD_FILTER_AT | SWKBD_FILTER_PERCENT | SWKBD_FILTER_BACKSLASH | SWKBD_FILTER_PROFANITY, 2);
						swkbdSetFeatures(&swkbd, SWKBD_MULTILINE);
						swkbdSetFilterCallback(&swkbd, MyCallback, NULL);
						swkbdSetHintText(&swkbd, "password");
						button = swkbdInputText(&swkbd, mybuf, sizeof(mybuf));
						/*printf("mybuf = %s \n", mybuf);
						printf("t6 = %s \n", t6);*/
						if (strcmp(mybuf, t6) == 0)
						{
							didit = true;
						}
					}
				}
			}
		}else{
			
			//Main Program
			char userdir[30];
			if (multiuser)
			{
				sprintf(userdir, "sdmc:/3ds/ROT_Data/%s", sendusername);
			}else{
				sprintf(userdir, "sdmc:/3ds/ROT_Data");
			}
			consoleSelect(&bottomScreen);
			//printf("&userdir/userdata.ruf");
			char tempvar[30];
			sprintf(tempvar, "%s/userdata.ruf", userdir);
			userfile = fopen(tempvar, "r");
			char dummy[30], username[30];
			fscanf(userfile, "%s %s %s", dummy, dummy, username);
			consoleSelect(&topScreen);
			consoleClear();
			printf("###                                            ###");
			printf(" ###                                          ### ");
			printf("  ###               [B] Logoff               ###  ");
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
			printf(" [<] Left  ##                        ## Right [>] ");
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
			while(true)
			{
				hidScanInput();
				u32 kDown = hidKeysDown();
				if (kDown & KEY_A){
					NULL;
					break;
				}
					//do thing: function(userdir);
				if (kDown & KEY_B)
				{
					logged = false;
					break;
				}
				if (kDown & KEY_X)
				{
					NULL;
					break;
				}
					//settings(userdir);
				if (kDown & KEY_Y)
				{
					NULL;
					break;
				}
					//mail(userdir);
				if (kDown & KEY_LEFT)
				{
					NULL;
					break;
				}
					//moveMenu(left, curMenuItem);
				if (kDown & KEY_RIGHT)
				{
					NULL;
					break;
				}
					//moveMenu(right, curMenuItem);
				if (kDown & KEY_START)
				{
					killROT = true;
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