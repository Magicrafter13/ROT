#include <3ds.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "header.h"

PrintConsole topScreen, bottomScreen;

int toggleMultiUser()
{
	return 0;
}

int debugView()
{
	consoleInit(GFX_TOP, &topScreen);
	consoleInit(GFX_BOTTOM, &bottomScreen);
	//do something with files
	//Main deleteData code:
	{
		consoleSelect(&bottomScreen);
		printf("debugView opened\n");
		consoleSelect(&topScreen);
		consoleClear();
		printf("Feature will be added in future release.\n");
		printf("Will return to settings menu in 5 seconds.\n");
		for(int I = 0; I < 300; I++)
			gspWaitForVBlank();
	}
	return 0;
}

int DLC()
{
	consoleInit(GFX_TOP, &topScreen);
	consoleInit(GFX_BOTTOM, &bottomScreen);
	//do something with files
	//Main deleteData code:
	{
		consoleSelect(&bottomScreen);
		printf("DLC opened\n");
		consoleSelect(&topScreen);
		consoleClear();
		printf("Feature will be added in future release.\n");
		printf("Will return to settings menu in 5 seconds.\n");
		for(int I = 0; I < 300; I++)
			gspWaitForVBlank();
	}
	return 0;
}

int deleteData()
{
	consoleInit(GFX_TOP, &topScreen);
	consoleInit(GFX_BOTTOM, &bottomScreen);
	//do something with files
	//Main deleteData code:
	{
		consoleSelect(&bottomScreen);
		printf("deleteData opened\n");
		consoleSelect(&topScreen);
		consoleClear();
		printf("Feature will be added in future release.\n");
		printf("Will return to settings menu in 5 seconds.\n");
		for(int I = 0; I < 300; I++)
			gspWaitForVBlank();
	}
	return 0;
}

int changePassword()
{
	consoleInit(GFX_TOP, &topScreen);
	consoleInit(GFX_BOTTOM, &bottomScreen);
	//do something with files
	//Main changePassword code:
	{
		consoleSelect(&bottomScreen);
		printf("changePassword opened\n");
		consoleSelect(&topScreen);
		consoleClear();
		printf("Feature will be added in future release.\n");
		printf("Will return to settings menu in 5 seconds.\n");
		for(int I = 0; I < 300; I++)
			gspWaitForVBlank();
	}
	return 0;
}

int changeUsername()
{
	consoleInit(GFX_TOP, &topScreen);
	consoleInit(GFX_BOTTOM, &bottomScreen);
	//do something with files
	//Main changeUsername code:
	{
		consoleSelect(&bottomScreen);
		printf("changeUsername opened\n");
		consoleSelect(&topScreen);
		consoleClear();
		printf("Feature will be added in future release.\n");
		printf("Will return to settings menu in 5 seconds.\n");
		for(int I = 0; I < 300; I++)
			gspWaitForVBlank();
	}
	return 0;
}