#include "messages.h"
#include "../gamevars/vars.h"
#include <string.h>
#include <stdio.h>

// color pallete
#define RESET   "\x1b[0m"
#define BLACK   "\x1b[30m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define WHITE   "\x1b[37m"

#define BOLD    "\x1b[1m"
#define UNDERLINE "\x1b[4m"
//

void fillIn (char *str, int size, char what) {
  for (int i = 0; i < size-1; i++) {
    str[i] = what;
  }
  str[size-1] = '\0';
}

int strlenIgnoreSpecialCodes(const char *str) {
int len = 0;
  int code = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == '\x1b') {
      code = 1; // Start of ANSI escape
    } else if (code == 1 && str[i] == 'm') {
      code = 0; // End of ANSI escape
    } else if (code == 0) {
      len++; // Count only visible characters
    }
  }
  return len;
}

void putInsideBox (char items[][stdMaxChars], int lines, int leftBorder, int rightBorder) {
  int max = 80;
  for (int i = 0; i < lines; i++) {
    int len = strlenIgnoreSpecialCodes(items[i]);
    int left = (max-len)/2; int right = (max-len)/2;
    if (left + right != max-len) right++;
    char leftStr[left+1]; char rightStr[right+1];
    char fillLeft = '\0'; char fillRight = '\0';
    if (leftBorder == 1) fillLeft = ' '; if (rightBorder == 1) fillRight = ' ';
    fillIn(leftStr, left, fillLeft); fillIn(rightStr, right, fillRight);
    char temp[85]; strcpy(temp, items[i]);
    sprintf(items[i], "%s%s%s", leftStr, temp, rightStr);
  }
}

void addSideInfo (char items[][stdMaxChars], char add[][stdMaxChars], int lines) {
  for (int i = 0; i < lines; i++) {
    strcat(items[i], " ");
    strcat(items[i], add[i]);
  }
}

/*
MENUS
*/

void printMenu() {
  char string[4][stdMaxChars];
  for (int i = 0; i < 4; i++) memset(string[i], 0, stdMaxChars);
  sprintf(string[0], "buckshot roulette C");
  sprintf(string[1], "choose your game settings");
  sprintf(string[2], "normal");
  sprintf(string[3], "extended");
  putInsideBox(string, 4, 1, 1);
  for (int i = 0; i < 4; i++) {
    printf("%s\n", string[i]);
  }
}

void printCustom(char string[stdMaxChars], int isInput) {
  char temp[1][stdMaxChars];
  strcpy (temp[0], string);
  putInsideBox(temp, 1, 1, 1-isInput);
  printf("%s", temp[0]);
}

void printGamemodes() {
  char string[4][stdMaxChars];
  for (int i = 0; i < 4; i++) memset(string[i], 0, stdMaxChars);
  sprintf(string[0], "pick a gamemode");
  sprintf(string[1], "shotgun");
  sprintf(string[2], "revolver");
  sprintf(string[3], "rifle");
  putInsideBox(string, 4, 1, 1);
  for (int i = 0; i < 4; i++) {
    printf("%s\n", string[i]);
  }
}

void printPlaymodes() {
  char string[4][stdMaxChars];
  for (int i = 0; i < 4; i++) memset(string[i], 0, stdMaxChars);
  sprintf(string[0], "pick a play mode");
  sprintf(string[1], "pve");
  sprintf(string[2], "pvp");
  sprintf(string[3], "multiplayer");
  putInsideBox(string, 4, 1, 1);
  for (int i = 0; i < 4; i++) {
    printf("%s\n", string[i]);
  }
}


/*
GAME SCREENS
*/
void printStats() {
  char string[6][stdMaxChars];
  for (int i = 0; i < 6; i++) memset(string[i], 0, 60);
  //memcpy(string[0], "-----------Player HP: %d-----------", , playerhp);
  sprintf(string[0], "-----------Player HP: %d-----------", player.hp);
  sprintf(string[1], "-%s--%s------%s--%s-", player.inv[0], player.inv[1], player.inv[4], player.inv[5]);
  sprintf(string[2], "-%s--%s------%s--%s-", player.inv[2], player.inv[3], player.inv[6], player.inv[7]);
  sprintf(string[3], "-----------Dealer HP: %d-----------", dealer.hp);
  sprintf(string[4], "-%s--%s------%s--%s-", dealer.inv[0], dealer.inv[1], dealer.inv[4], dealer.inv[5]);
  sprintf(string[5], "-%s--%s------%s--%s-", dealer.inv[2], dealer.inv[3], dealer.inv[6], dealer.inv[7]);
  
}

void printStartingLocation() {
  if (currentGame.gun == 0) {
    // the scenario
    char string[10][stdMaxChars];
    for (int i = 0; i < 10; i++) memset(string[i], 0, stdMaxChars);
    sprintf(string[0], "######################################################################");
    sprintf(string[1], "#############################|----------|#############################");
    sprintf(string[2], "#############################|----------|#############################");
    sprintf(string[3], "-------######################|----------|#############################");
    sprintf(string[4], "  " RED "_" RESET "   |######################|----------|#############################");
    sprintf(string[5], "  " RED "U" RESET " | |######################|--------O-|#############################");
    sprintf(string[6], "  |   |######################|----------|#############################");
    sprintf(string[7], "|    /#######################|----------|#############################");
    sprintf(string[8], "   /##################################################################");
    sprintf(string[9], " /####################################################################");

    //info
    char stringSide[3][stdMaxChars];
    for (int i = 0; i < 3; i++) memset(stringSide[i], 0, stdMaxChars);
    sprintf(stringSide[0], "You are in a bathroom");
    sprintf(stringSide[1], "You can interact with:");
    sprintf(stringSide[2], "Door, pill(red)");

    putInsideBox(string, 10, 1, 1);
    addSideInfo(string, stringSide, 3);
    for (int i = 0; i < 10; i++) {
      printf("%s\n", string[i]);
    }
  }
}

void printSecondaryLocation() {
  if (currentGame.mode == 0) {
    // the scenario
    char string[12][stdMaxChars];
    for (int i = 0; i < 12; i++) memset(string[i], 0, stdMaxChars);
    sprintf(string[0], "########################################                               ");
    sprintf(string[1], "#|-------|##############################                               ");
    sprintf(string[2], "#|-------|#####################--------------------------              ");
    sprintf(string[3], "#|-----o-|#|\\#----------------         /            /    \\             ");
    sprintf(string[4], "#|-------|#|#\\      /    /                               |\\            ");
    sprintf(string[5], "XXXXXXXXXXX|##\\                                            \\           ");
    sprintf(string[6], "XXXXXXXXXXXX  |\\            -------------                  |\\          ");
    sprintf(string[7], "XXXXXXXXXXXXX-|-\\-----------        /     \\                  \\         ");
    sprintf(string[8], "XXXXXXXXXXXXXX|  \\   /                    |\\                 |\\        ");
    sprintf(string[9], "XXXXXXXXXXXXXXX   \\                         \\                  \\       ");
    sprintf(string[10],"XXXXXXXXXXXXXXXX--|\\-----                    \\                 |\\      ");
    sprintf(string[11],"XXXXXXXXXXXXXXXXX | \\   \\                   |\\                  \\     ");

    //info
    char stringSide[4][stdMaxChars];
    for (int i = 0; i < 4; i++) memset(stringSide[i], 0, stdMaxChars);
    sprintf(stringSide[0], "You are in club");
    sprintf(stringSide[1], "Loud music plays in the background");
    sprintf(stringSide[2], "You can interact with:");
    sprintf(stringSide[3], "Door, Bars");

    putInsideBox(string, 12, 1, 1);
    addSideInfo(string, stringSide, 4);
    for (int i = 0; i < 12; i++) {
      printf("%s\n", string[i]);
    }
  }
}

void printGameLocation(int phase) {
  if (currentGame.mode == 0) {
    if (phase == 0) {
      // the scenario
      char string[20][stdMaxChars];
      for (int i = 0; i < 20; i++) memset(string[i], 0, stdMaxChars);
      sprintf(string[0], "                                                                      ");
      sprintf(string[1], "                     /------------\\                                  ");
      sprintf(string[2], "                    |              |                                  ");
      sprintf(string[3], "                    | ( )      ( ) |                                  ");
      sprintf(string[4], "                    |  _________   |                                  ");
      sprintf(string[5], "                    |  \\......./   |                                  ");
      sprintf(string[6], "                     \\____________/                                   ");
      sprintf(string[7], "                     /            \\                                   ");
      sprintf(string[8], "                    /|\\          /|\\                                  ");
      sprintf(string[9], "                  /-------------------\\                               ");
      sprintf(string[10],"                 |                     |                              ");
      sprintf(string[11],"                 |                 ___ |                              ");
      sprintf(string[12],"                 |                 |%d|D|                              ", dealer.hp);
      sprintf(string[13],"                 |    x=======\\\\   | | |                              ");
      sprintf(string[14],"                 |            ||   |%d|P|                              ", player.hp);
      sprintf(string[15],"                 |                 --- |                              ");
      sprintf(string[16],"                 |                     |                              ");
      sprintf(string[17],"                 |                     |                              ");
      sprintf(string[18],"                  \\-------------------/                               ");
      sprintf(string[19],"                          Hello...                                     ");

      //info
      //char stringSide[1][stdMaxChars];
      //for (int i = 0; i < 1; i++) memset(stringSide[i], 0, stdMaxChars);
      //sprintf(stringSide[0], "Hello...");

      putInsideBox(string, 20, 1, 1);
      //addSideInfo(string, stringSide, 1);
      for (int i = 0; i < 20; i++) {
        printf("%s\n", string[i]);
      }
    }
  }
}

void printDeath(int cause) {
  /*
  the causes for one's death:
  0 - commiting suicide by jumping off at the club scene
  
  */
  if (cause == 0) {
    char string[12][stdMaxChars];
    for (int i = 0; i < 12; i++) memset(string[i], 0, stdMaxChars);
    sprintf(string[0], "                                                                      ");
    sprintf(string[1], "                                                                      ");
    sprintf(string[2], "                                                                      ");
    sprintf(string[3], "  You are dead little bro                                             ");
    sprintf(string[4], "                                                                      ");
    sprintf(string[5], "             |     " RED "-." RESET "                                                 ");
    sprintf(string[6], "     ___     "RED "|" RESET "  ___                                                   ");
    sprintf(string[7], "  H_/   ###" RED "##" RESET"### " RED "  |..." RESET "                                               ");
    sprintf(string[8], "     ___########   |                                                  ");
    sprintf(string[9], "  __/        |  \"\"\"                                                   ");
    sprintf(string[10]," H           /                                                        ");
    sprintf(string[11],"                                                                      ");
    //info
    char stringSide[4][stdMaxChars];
    for (int i = 0; i < 4; i++) memset(stringSide[i], 0, stdMaxChars);
    sprintf(stringSide[0], "You are in club");
    sprintf(stringSide[1], "Loud music plays in the background");
    sprintf(stringSide[2], "You can interact with:");
    sprintf(stringSide[3], "Door, Bars");
    // here it breaks
    putInsideBox(string, 12, 1, 1);
    //addSideInfo(string, stringSide, 3);
    for (int i = 0; i < 12; i++) {
      printf("%s\n", string[i]);
    }
  }
}

/*
MISC
*/
void printCareful() {
  printf("Careful, now...");
}

void printNewScreen() {
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

