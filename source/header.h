#ifndef headerfile
#define headerfile

#include <3ds.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
using std::string;
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>

extern PrintConsole topScreen, bottomScreen, versionWin;

extern char versiontxtt[6];
extern char versiontxtn[9];
extern int versionnum;
extern int settingsVersion;
int mail(char userDir[30]);
int toggleMultiUser();
int debugView(char userDir[30]);
int DLC(char userDir[30]);
int deleteData(char userDir[30]);
int changePassword(char userDir[30]);
int changeUsername(char userDir[30]);
int games(char userDir[30], int upperrv);
int tools(char userDir[30], int upperrv);
int store(char userDir[30], int upperrv);
int credits();
//int PathDelete(const char* path);
extern int selTool;
extern int selGame;
extern int selStore;
extern int debugTF;
extern int storeDisp;
const char * keyBoard(char * hintTxt, int maxNumbers, bool multiLine);
int mkdir(const char *pathname, mode_t mode);

#define COLOR "\x1b["
#define RED "31"
#define B_RED "41"
#define GREEN "32"
#define B_GREEN "42"
#define YELLOW "33"
#define B_YELLOW "43"
#define BLUE "34"
#define B_BLUE "44"
#define MAGENTA "35"
#define B_MAGENTA "45"
#define CYAN "36"
#define B_CYAN "46"
#define WHITE "37"
#define B_WHITE "47"
#define BRIGHT "2"
#define RESET "\x1b[0m"
#define CSEP ";"
#define CEND "m"

#endif