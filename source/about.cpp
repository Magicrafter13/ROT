#include "header.h"

int matthew()
{
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
	int returnvalue = 0;
	consoleClear();
	gspWaitForVBlank();
	printf("ROT, for those who don't know:\n");
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
	return 0;
}

int timeline(int upperrv)
{
	return upperrv;
}