#include <3ds.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
int settingsVersion;
int mail();
int toggleMultiUser();
int debugView();
int DLC();
int deleteData();
int changePassword();
int changeUsername();
int games();
int tools();
int selGame;
int toolsel;
const char * keyBoard(char hintTxt[30], int maxNumbers, bool multiLine);
#define COLOR "\x1b["
#define RED "31"
#define B_BRED "41"
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