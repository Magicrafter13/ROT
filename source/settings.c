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

static SwkbdCallbackResult MyCallback(void* user, const char** ppMessage, const char* text, size_t textlen)
{
	return SWKBD_CALLBACK_OK;
}

int changePassword(char userDir[30])
{
	static char mybuf[60];
	static char mybuf2[60];
	consoleSelect(&bottomScreen);
	printf("changePassword opened\n");
	consoleSelect(&topScreen);
	consoleClear();
	//passKeyb(0);
	//passKeyb(1);
	static SwkbdState swkbd;
	swkbdInit(&swkbd, SWKBD_TYPE_WESTERN, 1, -1);
	swkbdSetValidation(&swkbd, SWKBD_NOTEMPTY_NOTBLANK, SWKBD_FILTER_DIGITS | SWKBD_FILTER_AT | SWKBD_FILTER_PERCENT | SWKBD_FILTER_BACKSLASH | SWKBD_FILTER_PROFANITY, 2);
	swkbdSetFeatures(&swkbd, SWKBD_MULTILINE);
	swkbdSetFilterCallback(&swkbd, MyCallback, NULL);
	swkbdSetHintText(&swkbd, "new password");
	swkbdInputText(&swkbd, mybuf, sizeof(mybuf));
	swkbdInit(&swkbd, SWKBD_TYPE_WESTERN, 1, -1);
	swkbdSetValidation(&swkbd, SWKBD_NOTEMPTY_NOTBLANK, SWKBD_FILTER_DIGITS | SWKBD_FILTER_AT | SWKBD_FILTER_PERCENT | SWKBD_FILTER_BACKSLASH | SWKBD_FILTER_PROFANITY, 2);
	swkbdSetFeatures(&swkbd, SWKBD_MULTILINE);
	swkbdSetFilterCallback(&swkbd, MyCallback, NULL);
	swkbdSetHintText(&swkbd, "confirm");
	swkbdInputText(&swkbd, mybuf2, sizeof(mybuf2));
	FILE *fp;
	char ustring[30];
	char ustring2[30];
	sprintf(ustring, "%s/userdata.ruf", userDir);
	sprintf(ustring2, "%s/temp.rtf", userDir);
	char dummy[30];
	if(strcmp(mybuf, mybuf2) == 0)
	{
		fp = fopen(ustring, "r");
		fseek(fp, 0, SEEK_SET);
		char name[21];
		fscanf(fp, "%s %s %s", dummy, dummy, name);
		fclose(fp);
		FILE *fileptr1, *fileptr2;
		fileptr1 = fopen(ustring, "r");
		fileptr2 = fopen(ustring2, "w");
		fscanf(fileptr1, "%s %s %s %s %s %s", dummy, dummy, dummy, dummy, dummy, dummy);
		for(int I = 0; I < 100; I++)
		{
			//ch = getc(fileptr1);
			//putc(ch, fileptr2);
			fscanf(fileptr1, "%s", dummy);
			fprintf(fileptr2, "%s ", dummy);
		}
		fclose(fileptr1);
		fclose(fileptr2);
		remove(ustring);
		fileptr1 = fopen(ustring, "w");
		fileptr2 = fopen(ustring2, "r");
		fprintf(fileptr1, "name = %s\n", name);
		fprintf(fileptr1, "pass = %s\n", mybuf);
		for(int I = 0; I < 100; I++)
		{
			//ch = getc(fileptr2);
			//putc(ch, fileptr1);
			fscanf(fileptr2, "%s", dummy);
			fprintf(fileptr1, "%s ", dummy);
		}
		fclose(fileptr1);
		fclose(fileptr2);
		remove(ustring2);
		return 0;
	} else {
		printf("Passwords did not match");
		return 1;
	}
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