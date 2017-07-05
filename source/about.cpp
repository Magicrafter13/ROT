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
	for(int i = 0; i < 1200; i++)
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
	for(int i = 0; i < 900; i++)
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

int commitDetail()
{
	printf("test success\n");
	return 0;
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

int length = 850;

char timelineArray[10][851] =
{
	"[Jun 2017]--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------[Jul 2017]                                                                                                                                                                                    ",
	"     |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   |                                                                                                                                                                                        ",
	"     +-----[ 6/06/17]---------------------------------------------[ 6/07/17]-----------------------------------------------------------------------------------------------------------------------------------------------------------[ 6/08/17]------------------------------------------------------------------------------[ 6/09/17]-----------------------[ 6/12/17]---------------------------------------------[ 6/13/17]-----------------------[ 6/14/17]-[ 6/15/17]-[ 6/16/17]-[ 6/19/17]-[ 6/22/17]-[ 6/24/17]-------------------------------------------------------------------[ 6/26/17]-[ 6/29/17]----------------------------------[ 6/30/17]                       [ 7/01/17]----------------------------------------------------------------------------------------------------[ 7/02/17]----------------------------------[ 7/04/17]                          ",
	"                |                                                      |                                                                                                                                                                    |                                                                                       |                                |                                                      |                                |          |          |          |          |          |                                                                            |          |                                           |                                |                                                                                                             |                                           |                              ",
	"                +------ d42d9c0 -- 09b8859 -- 0c1cf90 -- 21dc50c       +------ d5c4cc8 -- 481f2ad -- 87bfbf0 -- d5674c6 -- 41985fe -- 3e50737 -- ee3dea8 -- a34a237 -- 820fe6d -- 370dd4e -- 80b7c51 -- 9399406 -- 50696a0 -- e1bcba5       +------ cc66dbb -- 1291e05 -- 33e0c28 -- 73bb65d -- e6df68b -- c6c1fe0 -- 32adbd8       +------ 15fb9b2 -- 3f97168       +------ ce5feaf -- 9addb0a -- 90e65e8 -- 1a4415f       +------ 2779ea3               b947377    0480203    ae26aae    7619981    6734a2d       +------ ab0e8c6 -- f66a570 -- 0ac5225 -- 9650fc6 -- 2a77db0 -- 724d973    b41a2d4       +------ 54f53f2 -- 888ebdb -- 71f038d       +------ f5377c7 -- 85b900c       +------ 37f62e8 -- fa916b5 -- 0cb5c5b -- a00cef1 -- 19c503b -- 34fe371 -- a2bcce4 -- fad3e1a -- 11b0bb6       +------ c591cda -- 15337ce -- 9f7b58a    current                           ",
	"                           |                     |                                                                            |                                           |                                                                            |          |                     |                     |                                           |                     |          |          |          |                     |                     |                                |          |                                |          |                     |                     |                     |          |          |                     |          |                     |          |          |          |          |          |                     |          |                                |                     |                              ",
	"                         A 1.3                 A 1.4                                                                          |                                         A 1.5                                                                        A 1.6        |                   A 1.7                   |                                           |                     ]----------+----[]----+----------[                   A 1.8                   |                                |        A 1.9                            A 1.10   A 1.11.2                  |                 A 1.11.3              A 1.16.6   A 1.16.7    B 1.0.1                  |       B 1.0.1                  |       B 1.0.2    B 1.0.3       ]----------+----------[                     |          |                                |                     |                              ",
	"                                                                                                                              |                                                                                                                                   |                                           |                                           |                                     []                                     |                     |                                |                                           |                                |                                           |                                           |                                |                                           |                                |          |                                |                     |                              ",
	"                       [Alpha 1.3 was the first time I had used GitHub.]                                              Settings Menu POC                                                    Between A 1.4 and A 1.5...                                 First GitHub related file.              Felt so stupid here. This commit was               First Issue I fixed     Although these commit's by themselves are boring     This is in my opinion   One of the first real   As you can see, commits became                   Is also A 1.10.1   This commit, the one before, and the one after   Second time having releases right after             FINALLY! Commits inBETWEEN             First dabble in          Haven't done commits this close together   Began work on timeline   Added                    First change due to  Found out the scroll bar doesn't actually",
	"                 I do have cia files for Alpha 1.0 - 1.2, and may release them someday.            I remember thinking this was awesome, now we have XP Store               I wish I still made that many commit's between versions                          [Readme.md]             literally just the 3dsx files from the previous commit             [#1]                      They lead up to....: [Right -->]        The first major/cool release.   features (change pass)   infrequent. Day by day if that.           But got mixed up somehow   Just contained some of GitHub's 'MD' files.   each other. First was 1.10.1 to 1.11.2   Releases (and breathing room for the timeline)   Random numbers.    In a while. (Less than an hour apart I believe.)          ;p       timeline feature                 a user request.    work, it depends on the length.         "
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
	printf("\n" COLOR CYAN CEND "           Use Left and Right to move.\n           Or use L and R to fast move.\n        Or use ZL and ZR to move one page.");
	int twoPercent = (length / 49);
	int area = (selTimeline / twoPercent);
	int otherNumber = (49 - area);
	std::string scrollBar;
	for (int i = 0; i < area; i++)
		scrollBar.append(" ");
	scrollBar.append("|");
	for (int i = 0; i < otherNumber; i++)
		scrollBar.append(" ");
	printf("\x1b[18;0H       To view details of specific commits.");
	printf("\x1b[19;0H                     Press Y");
	printf("\x1b[22;0H" RESET "+------------------------------------------------+");
	printf("\x1b[23;0H" RESET "" COLOR BRIGHT CSEP WHITE CEND "%s" RESET "|", scrollBar.c_str());
	printf("\x1b[24;0H" RESET "+------------------------------------------------+");
	return 0;
}

int timeline(int upperrv)
{
	int ireturnvalue = 3;
	char returnvalue[30];
	strcpy(returnvalue, "ERROR");
	int tlMin = 0;
	int tlMax = 800;
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
			if (kDown & KEY_LEFT || kHeld & KEY_L)
			{
				sprintf(returnvalue, "LEFT");
				selTimeline--;
				break;
			}
			if (kDown & KEY_ZL)
			{
				sprintf(returnvalue, "LEFT");
				selTimeline -= 50;
				if (selTimeline < tlMin)
					selTimeline = tlMin;
				break;
			}
		}
		if (selTimeline < tlMax)
		{
			if (kDown & KEY_RIGHT || kHeld & KEY_R)
			{
				sprintf(returnvalue, "RIGHT");
				selTimeline++;
				break;
			}
			if (kDown & KEY_ZR)
			{
				sprintf(returnvalue, "RIGHT");
				selTimeline += 50;
				if (selTimeline > tlMax)
					selTimeline = tlMax;
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
		if (kDown & KEY_Y)
		{
			while(true)
			{
				hidScanInput();
				u32 kDown = hidKeysDown();
				if (kDown != kDownOld)
				{
					sprintf(returnvalue, "Y");
					while(true)
					{
						int result = commitDetail();
						if (result == 2)
						{
							sprintf(returnvalue, "START");
							break;
						}
						if (result == 0)
							break;
					}
					break;
				}
			}
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
	if ((strcmp(returnvalue, "LEFT") == 0) || (strcmp(returnvalue, "RIGHT") == 0) || (strcmp(returnvalue, "Y") == 0))
		ireturnvalue = 1;
	if (strcmp(returnvalue, "B") == 0)
		ireturnvalue = 0;
	return ireturnvalue;
}