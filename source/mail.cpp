#include "header.h"

//PrintConsole topScreen, bottomScreen;

int mail(char userDir[30])
{
	FILE *userFile;
	FILE *settingsFile;
	char uF[30], sF[30];
	sprintf(uF, "%s/userdata.ruf", userDir);
	sprintf(sF, "%s/settings.rsf", userDir);
	userFile = fopen(uF, "r");
	settingsFile = fopen(sF, "r");
	consoleSelect(&bottomScreen);
	int dummy = 0;
	fscanf(settingsFile, "%d %d", &dummy, &debugTF);
	if (debugTF)
		printf("mail opened\n");
	consoleSelect(&topScreen);
	consoleClear();
	printf("Feature not added yet, and probably not for a while :(\nSorry!");
	for (int i = 0; i < 120; i++)
	{
		gspWaitForVBlank();
	}
	fclose(userFile);
	fclose(settingsFile);
	return 0;
}