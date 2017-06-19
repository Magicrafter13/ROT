#include "header.h"

PrintConsole topScreen, bottomScreen;

int toggleMultiUser()
{
	return 0;
}

int debugView(char userDir[30])
{
	int thing = 0, dummy = 0;
	char thing2[53], thing3[60];
	FILE *settingsFile;
	sprintf(thing2, "%s/settings.rsf", userDir);
	settingsFile = fopen(thing2, "r");
	fscanf(settingsFile, "%d %d", &dummy, &thing);
	consoleSelect(&bottomScreen);
	if (thing)
		printf("debugView opened\n");
	fclose(settingsFile);
	consoleSelect(&topScreen);
	consoleClear();
	fclose(settingsFile);
	settingsFile = fopen(thing2, "r+");
	if (thing == 1)
	{
		rewind(settingsFile);
		sprintf(thing3, "%d\n%d\n", settingsVersion, 0);
		fputs(thing3, settingsFile);
		printf("Debug View turned off.");
	} else {
		rewind(settingsFile);
		sprintf(thing3, "%d\n%d\n", settingsVersion, 1);
		fputs(thing3, settingsFile);
		printf("Debug View turned on.");
	}
	fclose(settingsFile);
	for(int i = 0; i < 120; i++)
		gspWaitForVBlank();
	return 0;
}

int DLC(char userDir[30])
{
	int thing = 0, dummy = 0;
	char thing2[53];
	FILE *settingsFile;
	sprintf(thing2, "%s/settings.rsf", userDir);
	settingsFile = fopen(thing2, "r");
	fscanf(settingsFile, "%d %d", &dummy, &thing);
	consoleSelect(&bottomScreen);
	if (thing)
		printf("DLC opened\n");
	fclose(settingsFile);
	consoleSelect(&topScreen);
	consoleClear();
	printf("Feature will be added in future release.\n");
	printf("Will return to settings menu in 5 seconds.\n");
	for(int I = 0; I < 300; I++)
		gspWaitForVBlank();
	return 0;
}

int getPermission(){
	return 7;
}

int deleteData(char userDir[30])
{
	int thing = 0, dummy = 0, returnvaluei = 0;
	char thing2[53], thing4[53], dummys[21], name[21], pass[50];
	FILE *settingsFile, *userFile, *fp;
	sprintf(thing2, "%s/settings.rsf", userDir);
	sprintf(thing4, "%s/userdata.ruf", userDir);
	settingsFile = fopen(thing2, "r");
	userFile = fopen(thing4, "r");
	fscanf(settingsFile, "%d %d", &dummy, &thing);
	fscanf(userFile, "%s %s %s %s %s %s", dummys, dummys, name, dummys, dummys, pass);
	consoleSelect(&bottomScreen);
	if (thing)
		printf("deleteData opened\n");
	fclose(settingsFile);
	fclose(userFile);
	consoleSelect(&topScreen);
	consoleClear();
	if ((fp = fopen("sdmc:/3ds/ROT_Data/userdata.ruf", "r")) == NULL)
	{
		NULL;
	} else {
		printf("%s\n", name);
		printf("Press A to delete all ROT data, press B to return");
		while(true)
		{
			hidScanInput();
			u32 kDown = hidKeysDown();
			if (kDown & KEY_A)
			{
				char input[50];
				for (int i = 0; i < 5; i++)
					strcpy(input, keyBoard("Verify with Password", 0, false));
				returnvaluei = 2;
				break;
			}
			if (kDown & KEY_B)
			{
				returnvaluei = 0;
				break;
			}
		}
	}
	return returnvaluei;
}

static SwkbdCallbackResult MyCallback(void* user, const char** ppMessage, const char* text, size_t textlen)
{
	return SWKBD_CALLBACK_OK;
}

int changePassword(char userDir[30])
{
	int thing = 0, dummy11 = 0;
	char thing2[53];
	FILE *settingsFile;
	sprintf(thing2, "%s/settings.rsf", userDir);
	settingsFile = fopen(thing2, "r");
	fscanf(settingsFile, "%d %d", &dummy11, &thing);
	consoleSelect(&bottomScreen);
	if (thing)
		printf("changePassword opened\n");
	fclose(settingsFile);
	static char mybuf[60];
	static char mybuf2[60];
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

int changeUsername(char userDir[30])
{
	int thing = 0, dummy = 0;
	char thing2[53];
	FILE *settingsFile;
	sprintf(thing2, "%s/settings.rsf", userDir);
	settingsFile = fopen(thing2, "r");
	fscanf(settingsFile, "%d %d", &dummy, &thing);
	consoleSelect(&bottomScreen);
	if (thing)
		printf("changeUsername opened\n");
	fclose(settingsFile);
	consoleSelect(&topScreen);
	consoleClear();
	printf("Feature will be added in future release.\n");
	printf("Will return to settings menu in 5 seconds.\n");
	for(int I = 0; I < 300; I++)
		gspWaitForVBlank();
	return 0;
}