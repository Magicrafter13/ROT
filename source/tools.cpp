#include "header.h"

int timer(char userDir[30])
{
	return 0;
	FILE *settingsFile;
	char *tempstr = new char[50];
	sprintf(tempstr, "%s/settings.rsf", userDir);
	fopen(tempstr, "r");
	int *debugTF = new int;
	while(true)
	{
		fscanf(settingsFile, "%d %d", debugTF, debugTF);
		consoleSelect(&bottomScreen);
		if(debugTF)
			printf("timer opened\n");
	}
	delete[] tempstr;
	fclose(settingsFile);
	//stuff
	delete[] debugTF;
	return 0;
}

int journal(char userDir[30])
{
	return 0;
}

int pawn(char userDir[30])
{
	return 0;
}

int alarm(char userDir[30])
{
	return 0;
}

int media(char userDir[30])
{
	return 0;
}