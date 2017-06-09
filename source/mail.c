#include <3ds.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "header.h"

PrintConsole topScreen, bottomScreen;

int mail(char userDir[30])
{
	gfxInitDefault();
	hidInit();
	consoleInit(GFX_TOP, &topScreen);
	consoleInit(GFX_BOTTOM, &bottomScreen);
	FILE *userFile;
	FILE *settingsFile;
	char uF[30], sF[30];
	sprintf(uF, "%s/userdata.ruf", userDir);
	sprintf(sF, "%s/settings.rsf", userDir);
	userFile = fopen(uF, "r");
	settingsFile = fopen(sF, "r");
	consoleSelect(&bottomScreen);
	printf("mail opened\n");
	consoleSelect(&topScreen);
	printf("Feature not added yet, and probably not for a while :(\nSorry!");
	for (int i = 0; i < 120; i++)
	{
		gspWaitForVBlank();
	}
	fclose(userFile);
	fclose(settingsFile);
	return 0;
}