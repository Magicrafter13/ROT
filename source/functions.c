#include "header.h"

static SwkbdCallbackResult MyCallback(void* user, const char** ppMessage, const char* text, size_t textlen)
{
	return SWKBD_CALLBACK_OK;
}

const char * keyBoard(char hintTxt[30], int maxNumbers, bool multiLine)
{
	static char string[21];
	static SwkbdState swkbd;
	SwkbdButton button = SWKBD_BUTTON_NONE;
	swkbdInit(&swkbd, SWKBD_TYPE_WESTERN, 1, -1);
	swkbdSetValidation(&swkbd, SWKBD_NOTEMPTY_NOTBLANK, SWKBD_FILTER_AT | SWKBD_FILTER_PERCENT | SWKBD_FILTER_BACKSLASH | SWKBD_FILTER_PROFANITY, maxNumbers);
	if (multiLine)
		swkbdSetFeatures(&swkbd, SWKBD_MULTILINE);
	swkbdSetFilterCallback(&swkbd, MyCallback, NULL);
	swkbdSetHintText(&swkbd, hintTxt);
	button = swkbdInputText(&swkbd, string, sizeof(string));
	return string;
}