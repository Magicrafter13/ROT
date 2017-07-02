#include "header.h"

int matthew()
{
	consoleSelect(&bottomScreen);
	if (debugTF)
		printf("matthew [about] opened\n");
	consoleSelect(&topScreen);
	int returnvalue = 0;
	consoleClear();
	gspWaitForVBlank();
	printf(RESET "My name is Matthew,\n");
	printf("I've been interested in computers since\n");
	printf("I was really young. My first game (written\n");
	printf("in batch) was called Dungeon Escape, and was\n");
	printf("a 'first person' maze game. Though it was\n");
	printf("still static 2d ascii images.\n\n");
	printf("I then made RFGEP which if you know what that\n");
	printf("is, then you know where I got the inspiration\n");
	printf("for ROT.\n\n");
	printf("I have made other games, but the only one\n");
	printf("worth mentioning is '1946' made in GameMaker\n");
	printf("Studio. It's on the steam workshop if you're\n");
	printf("interested. Although I haven't updated the\n");
	printf("Steam version in a while, and it doesn't have\n");
	printf("a lot of the cool things I added to it. I\n");
	printf("can't update it either because I lost the\n");
	printf("source files.\n\n");
	printf("If you got any questions for me, feel free\n");
	printf("to contact me via social media or otherwise.\n");
	gspWaitForVBlank();
	for(int i = 0; i < 600; i++)
	{
		hidScanInput();
		u32 kDown = hidKeysDown();
		if (kDown & KEY_START)
		{
			returnvalue = 2;
			break;
		}
		if (kDown & KEY_B)
			break;
		gspWaitForVBlank();
	}
	return returnvalue;
}

int rot()
{
	consoleSelect(&bottomScreen);
	if (debugTF)
		printf("rot [about] opened\n");
	consoleSelect(&topScreen);
	int returnvalue = 0;
	consoleClear();
	gspWaitForVBlank();
	printf(RESET "ROT, for those who don't know:\n");
	printf("RFGEP On ThreeDS\n");
	printf("RFGEP which in and of itself stands for\n");
	printf("Rease Family Gaming Entertainment Package\n");
	printf("If you're curious about this batch program\n");
	printf("look it up on sourceforge.net\n\n");
	printf("Other than that, (as I've told many people\n");
	printf("before) what this program is/does is hard\n");
	printf("to explain.\n\n");
	printf("So feel free to come up with a definition\n");
	printf("for yourself. Have fun!\n");
	gspWaitForVBlank();
	for(int i = 0; i < 600; i++)
	{
		hidScanInput();
		u32 kDown = hidKeysDown();
		if (kDown & KEY_START)
		{
			returnvalue = 2;
			break;
		}
		if (kDown & KEY_B)
			break;
		gspWaitForVBlank();
	}
	return returnvalue;
}

int height = 10;

char dispArray[10][51] =
{
	"                                                  ",
	"                                                  ",
	"                                                  ",
	"                                                  ",
	"                                                  ",
	"                                                  ",
	"                                                  ",
	"                                                  ",
	"                                                  ",
	"                                                  "
};

char timelineArray[10][286] =
{
	"[June '17]-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------",
	"     |                                                                                                                                                                                                                                                                                       ",
	"     +-----[ 6/06/17]---------------------------------------------[ 6/07/17]-----------------------------------------------------------------------------------------------------------------------------------------------------------[ 6/08/17]--------------------------------------------",
	"                |                                                      |                                                                                                                                                                    |                                                ",
	"                +------ d42d9c0 -- 09b8859 -- 0c1cf90 -- 21dc50c       +------ d5c4cc8 -- 481f2ad -- 87bfbf0 -- d5674c6 -- 41985fe -- 3e50737 -- ee3dea8 -- a34a237 -- 820fe6d -- 370dd4e -- 80b7c51 -- 9399406 -- 50696a0 -- e1bcba5       +------ cc66dbb -- 1291e05 -- 33e0c28 -- 73bb65d ",
	"                           |                     |                                                                            |                                           |                                                                            |          |                     |    ",
	"                         A 1.3                 A 1.4                                                                          |                                         A 1.5                                                                        A 1.6        |                   A 1.7  ",
	"                                                                                                                              |                                                                                                                                   |                          ",
	"                       [Alpha 1.3 was the first time I had used GitHub.]                                              Settings Menu POC                                                    Between A 1.4 and A 1.5...                                 First GitHub related file.             ",
	"                 I do have cia files for Alpha 1.0 - 1.2, and may release them someday.            I remember thinking this was awesome, now we have XP Store               I wish I still made that many commit's between versions                          [Readme.md]                     "
};

int timelineDisplay()
{
	printf(RESET);
	for (int i = 0; i < height; i++)
	{
		std::string temp1;
		std::copy(&timelineArray[i][selTimeline], &timelineArray[i][selTimeline+50], back_inserter(temp1));
		sprintf(dispArray[i], "%s", temp1.c_str());
	}
	for (int i = 0; i < height; i++)
	{
		if (i == 0)
			printf(COLOR RED CEND);
		if (i == 1)
			printf(RESET);
		if (i == 2)
			printf(COLOR GREEN CEND);
		if (i == 3)
			printf(RESET);
		if (i == 4)
			printf(COLOR BLUE CEND);
		if (i == 5)
			printf(RESET);
		if (i == 6)
			printf(COLOR MAGENTA CEND);
		if (i == 7)
			printf(RESET);
		if (i == 8 || i == 9)
			printf(COLOR YELLOW CEND);
		printf("%s", dispArray[i]);
	}
	printf(COLOR CYAN CEND "           Use Left and Right to move.\n           Or use L and R to fast move.\n");
	return 0;
}

int timeline(int upperrv)
{
	int ireturnvalue = 3;
	char returnvalue[30];
	strcpy(returnvalue, "ERROR");
	int tlMin = 0;
	int tlMax = 235;
	consoleSelect(&bottomScreen);
	if (upperrv != 1)
		if (debugTF)
			printf("timeline [about] opened\n");
	consoleSelect(&topScreen);
	consoleClear();
	timelineDisplay();
	while(true)
	{
		hidScanInput();
		gspWaitForVBlank();
		hidScanInput();
		u32 kDown = hidKeysDown();
		u32 kDownOld = hidKeysDown();
		u32 kHeld = hidKeysHeld();
		if (selTimeline > tlMin)
		{
			if (kDown & KEY_LEFT)
			{
				sprintf(returnvalue, "LEFT");
				selTimeline--;
				break;
			}
			if (kHeld & KEY_L)
			{
				sprintf(returnvalue, "L");
				selTimeline--;
				break;
			}
		}
		if (selTimeline < tlMax)
		{
			if (kDown & KEY_RIGHT)
			{
				sprintf(returnvalue, "RIGHT");
				selTimeline++;
				break;
			}
			if (kHeld & KEY_R)
			{
				sprintf(returnvalue, "R");
				selTimeline++;
				break;
			}
		}
		if (kDown & KEY_B)
		{
			while(true)
			{
				hidScanInput();
				u32 kDown = hidKeysDown();
				if (kDown != kDownOld)
				{
					sprintf(returnvalue, "B");
					break;
				}
			}
			break;
		}
		if (kDown & KEY_START)
		{
			while(true)
			{
				hidScanInput();
				u32 kDown = hidKeysDown();
				if (kDown != kDownOld)
				{
					sprintf(returnvalue, "START");
					break;
				}
			}
			break;
		}
	}
	if (strcmp(returnvalue, "START") == 0)
		ireturnvalue = 2;
	if ((strcmp(returnvalue, "LEFT") == 0) || (strcmp(returnvalue, "RIGHT") == 0) || (strcmp(returnvalue, "L") == 0) || (strcmp(returnvalue, "R") == 0))
		ireturnvalue = 1;
	if (strcmp(returnvalue, "B") == 0)
		ireturnvalue = 0;
	return ireturnvalue;
}