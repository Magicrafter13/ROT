#include <3ds.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "header.h"

PrintConsole topScreen, bottomScreen;

int games()
{
	consoleInit(GFX_TOP, &topScreen);
	consoleInit(GFX_BOTTOM, &bottomScreen);
	{
		consoleSelect(&bottomScreen);
		printf("games opened\n");
		consoleSelect(&topScreen);
		consoleClear();
		printf("Feature will be added in future release.\n");
		printf("Will return to settings menu in 5 seconds.\n");
		for(int I = 0; I < 300; I++)
			gspWaitForVBlank();
	}
	return 0;
}

int tools()
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