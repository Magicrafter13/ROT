#include "header.h"

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
		std::cout << "debugView opened\n";
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
		std::cout << "Debug View turned off.";
	} else {
		rewind(settingsFile);
		sprintf(thing3, "%d\n%d\n", settingsVersion, 1);
		fputs(thing3, settingsFile);
		std::cout << "Debug View turned on.";
	}
	fclose(settingsFile);
	for(int i = 0; i < 120; i++)
	{
		gfxFlushBuffers();
		gfxSwapBuffers();
		gspWaitForVBlank();
	}
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
		std::cout << "DLC opened\n";
	fclose(settingsFile);
	consoleSelect(&topScreen);
	consoleClear();
	std::cout << "Feature will be added in future release.\n";
	std::cout << "Will return to settings menu in 5 seconds.\n";
	for(int I = 0; I < 300; I++)
	{
		gfxFlushBuffers();
		gfxSwapBuffers();
		gspWaitForVBlank();
	}
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
		std::cout << "deleteData opened\n";
	fclose(settingsFile);
	fclose(userFile);
	consoleSelect(&topScreen);
	consoleClear();
	if ((fp = fopen("sdmc:/3ds/ROT_Data/userdata.ruf", "r")) == NULL)
	{
	} else {
		std::cout << name << "\n";
		std::cout << "Press A to delete all ROT data, press B to return";
		while(true)
		{
			hidScanInput();
			u32 kDown = hidKeysDown();
			if (kDown & KEY_A)
			{
				std::string tempss = "Verify with Password";
				char * tempcs = new char[tempss.size() + 1];
				std::copy(tempss.begin(), tempss.end(), tempcs);
				tempcs[tempss.size()] = '\0';
				FILE *userFile;
				userFile = fopen("sdmc:/3ds/ROT_Data/userdata.ruf", "r");
				char dummy[21];
				fscanf(userFile, "%s %s %s %s %s %s", dummy, dummy, dummy, dummy, dummy, dummy);
				int i;
				for (i = 0; i < 5; i++)
				{
					strcpy(tempcs, keyBoard(tempcs, 0, false));
					if (strcmp(dummy, tempcs) == 0)
						i = 6;
				}
				if (i == 5)
				{
					returnvaluei = 1;
					break;
				}
				delete[] tempcs;
				s32 delcomp = 0;
				openSD();
				s32 delcomp2 = FSUSER_DeleteDirectoryRecursively(sdmcArchive, fsMakePath(PATH_ASCII, "/3ds/ROT_Data"));
				closeSD();
				std::cout << delcomp2;
				for (int i = 0; i < 120; i++)
					gspWaitForVBlank();
				if (delcomp2 == delcomp)
					returnvaluei = 2;
				else
					returnvaluei = 3;
				break;
			}
			if (kDown & KEY_B)
			{
				returnvaluei = 0;
				gfxFlushBuffers();
				gfxSwapBuffers();
				gspWaitForVBlank();
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
		std::cout << "changePassword opened\n";
	fclose(settingsFile);
	consoleSelect(&topScreen);
	consoleClear();
	//passKeyb(0);
	//passKeyb(1);
	static char mybuf[21], mybuf2[21];
	std::string tempss = "Enter new Password:";
	std::string tempss2 = "Verify";
	for (int i = 0; i < 2; i++)
	{
		char * tempcs = new char[tempss.size() + 1];
		if (i)
			std::copy(tempss2.begin(), tempss2.end(), tempcs);
		else
			std::copy(tempss.begin(), tempss.end(), tempcs);
		tempcs[tempss.size()] = '\0';
		if(i)
			strcpy(mybuf2, keyBoard(tempcs, 0, false));
		else
			strcpy(mybuf, keyBoard(tempcs, 0, false));
		delete[] tempcs;
	}
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
		while(true)
		{
			//ch = getc(fileptr1);
			//putc(ch, fileptr2);
			fscanf(fileptr1, "%s", dummy);
			if (strcmp(dummy, "-EOF-") == 0)
				break;
			else
				fprintf(fileptr2, "%s ", dummy);
		}
		fprintf(fileptr2, "-EOF-");
		fclose(fileptr1);
		fclose(fileptr2);
		remove(ustring);
		fileptr1 = fopen(ustring, "w");
		fileptr2 = fopen(ustring2, "r");
		fprintf(fileptr1, "name = %s\n", name);
		fprintf(fileptr1, "pass = %s\n", mybuf);
		while(true)
		{
			//ch = getc(fileptr2);
			//putc(ch, fileptr1);
			fscanf(fileptr2, "%s", dummy);
			if (strcmp(dummy, "-EOF-") == 0)
				break;
			else
				fprintf(fileptr1, "%s ", dummy);
		}
		fprintf(fileptr1, "-EOF-");
		fclose(fileptr1);
		fclose(fileptr2);
		remove(ustring2);
		return 0;
	} else {
		std::cout << "Passwords did not match";
		return 1;
	}
}

int changeUsername(char userDir[30])
{
	int thing = 0, dummy11 = 0;
	char thing2[53];
	FILE *settingsFile;
	sprintf(thing2, "%s/settings.rsf", userDir);
	settingsFile = fopen(thing2, "r");
	fscanf(settingsFile, "%d %d", &dummy11, &thing);
	consoleSelect(&bottomScreen);
	if (thing)
		std::cout << "changePassword opened\n";
	fclose(settingsFile);
	consoleSelect(&topScreen);
	consoleClear();
	static char mybuf[21];
	std::string tempss = "Username";
	char * tempcs = new char[tempss.size() + 1];
	std::copy(tempss.begin(), tempss.end(), tempcs);
	tempcs[tempss.size()] = '\0';
	strcpy(mybuf, keyBoard(tempcs, 0, false));
	delete[] tempcs;
	FILE *fp;
	char ustring[30];
	char ustring2[30];
	sprintf(ustring, "%s/userdata.ruf", userDir);
	sprintf(ustring2, "%s/temp.rtf", userDir);
	char dummy[30];
	fp = fopen(ustring, "r");
	fseek(fp, 0, SEEK_SET);
	char name[21], pass[21];
	fscanf(fp, "%s %s %s %s %s %s", dummy, dummy, name, dummy, dummy, pass);
	fclose(fp);
	FILE *fileptr1, *fileptr2;
	fileptr1 = fopen(ustring, "r");
	fileptr2 = fopen(ustring2, "w");
	fscanf(fileptr1, "%s %s %s", dummy, dummy, dummy);
	while(true)
	{
		//ch = getc(fileptr1);
		//putc(ch, fileptr2);
		fscanf(fileptr1, "%s", dummy);
		if (strcmp(dummy, "-EOF-") == 0)
			break;
		else
			fprintf(fileptr2, "%s ", dummy);
	}
	fprintf(fileptr2, "-EOF-");
	fclose(fileptr1);
	fclose(fileptr2);
	remove(ustring);
	fileptr1 = fopen(ustring, "w");
	fileptr2 = fopen(ustring2, "r");
	fprintf(fileptr1, "name = %s\n", mybuf);
	fprintf(fileptr1, "pass = %s\n", pass);
	while(true)
	{
		//ch = getc(fileptr2);
		//putc(ch, fileptr1);
		fscanf(fileptr2, "%s", dummy);
		if (strcmp(dummy, "-EOF-") == 0)
			break;
		else
			fprintf(fileptr1, "%s ", dummy);
	}
	fprintf(fileptr1, "-EOF-");
	fclose(fileptr1);
	fclose(fileptr2);
	remove(ustring2);
	return 0;
}