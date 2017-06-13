#include "header.h"

PrintConsole topScreen, bottomScreen;

int toggleMultiUser()
{
	return 0;
}

int debugView()
{
	consoleSelect(&bottomScreen);
	printf("debugView opened\n");
	consoleSelect(&topScreen);
	consoleClear();
	printf("Feature will be added in future release.\n");
	printf("Will return to settings menu in 5 seconds.\n");
	for(int I = 0; I < 300; I++)
		gspWaitForVBlank();
	return 0;
}

int DLC()
{
	consoleSelect(&bottomScreen);
	printf("DLC opened\n");
	consoleSelect(&topScreen);
	consoleClear();
	printf("Feature will be added in future release.\n");
	printf("Will return to settings menu in 5 seconds.\n");
	for(int I = 0; I < 300; I++)
		gspWaitForVBlank();
	return 0;
}

int deleteData()
{
	consoleSelect(&bottomScreen);
	printf("deleteData opened\n");
	consoleSelect(&topScreen);
	consoleClear();
	printf("Feature will be added in future release.\n");
	printf("Will return to settings menu in 5 seconds.\n");
	for(int I = 0; I < 300; I++)
		gspWaitForVBlank();
	return 0;
}

int changePassword()
{
	consoleSelect(&bottomScreen);
	printf("changePassword opened\n");
	consoleSelect(&topScreen);
	consoleClear();
	printf("Feature will be added in future release.\n");
	printf("Will return to settings menu in 5 seconds.\n");
	for(int I = 0; I < 300; I++)
		gspWaitForVBlank();
	return 0;
}

int changeUsername()
{
	consoleSelect(&bottomScreen);
	printf("changeUsername opened\n");
	consoleSelect(&topScreen);
	consoleClear();
	printf("Feature will be added in future release.\n");
	printf("Will return to settings menu in 5 seconds.\n");
	for(int I = 0; I < 300; I++)
		gspWaitForVBlank();
	return 0;
}