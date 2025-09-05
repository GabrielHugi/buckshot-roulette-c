#include "messages.h"
#include "../gamevars/vars.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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
  int max = 200;
  for (int i = 0; i < lines; i++) {
    int len = strlenIgnoreSpecialCodes(items[i]);
    int left = (max-len)/2; int right = (max-len)/2;
    if (left + right != max-len) right++;
    char leftStr[left+1]; char rightStr[right+1];
    char fillLeft = '\0'; char fillRight = '\0';
    if (leftBorder == 1) fillLeft = ' '; if (rightBorder == 1) fillRight = ' ';
    fillIn(leftStr, left, fillLeft); fillIn(rightStr, right, fillRight);
    char temp[max]; strcpy(temp, items[i]);
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

void transformNumberIntoPrintable(char *cool, char n) {
  //does not check for non numbers so use it properly, loser
  for (char i = 0; i < n; i++) {
    if (cool[i] == -1) cool[i] = ' ';
    else if (cool[i] < 10) cool[i]+=48;
  }
}

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

// these are for pve, later i will make for pvp and multiplayer and I may or may not sum up
// pve and pvp screens because they r practically the same shi but without the dealer so yeah
// i might aswell just do it later

void printStartingLocation() {
  if (strcmp(currentGame.weapon->name, "shotgun") == 0 && currentGame.mode == 1) {
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
  if (strcmp(currentGame.weapon->name, "shotgun") == 0 && currentGame.mode == 1) {
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

void printGameLocation() {
  if (strcmp(currentGame.weapon->name, "shotgun") == 0 && currentGame.mode == 1) {
    /*
    phases:
    0 - start
    1 - sign the waiver
    2 - waver signed
    3 - show bullets
    */
    int stringSideSize = 9;
    if (currentGame.extended == 1) stringSideSize = 15;
    char stringSide[stringSideSize][stdMaxChars];
    for (int i = 0; i < stringSideSize; i++) memset(stringSide[i], 0, stdMaxChars);
    sprintf(stringSide[0], "Item cheatsheet:");
    sprintf(stringSide[1], "1 - Beer");
    sprintf(stringSide[2], "2 - Adrenaline");
    sprintf(stringSide[3], "3 - Cigarette");
    sprintf(stringSide[4], "4 - Expired medicine");
    sprintf(stringSide[5], "5 - Handsaw");
    sprintf(stringSide[6], "6 - Handsaw");
    sprintf(stringSide[7], "7 - Inverter");
    sprintf(stringSide[8], "8 - Magnifying glass");
    if (currentGame.extended == 1) {
      // continue the sprintfs with the shit extended or sum 
    }
    if (currentGame.phase == 0) {
      // the scenario
      char charPlayerInv[8], charDealerInv[8];
      for (int i = 0; i < 8; i++) {
        charPlayerInv[i] = player.inv[i];
        charDealerInv[i] = dealer.inv[i];
      }
      transformNumberIntoPrintable(charPlayerInv, 8);
      transformNumberIntoPrintable(charDealerInv, 8);
      char string[20][stdMaxChars];
      for (int i = 0; i < 20; i++) memset(string[i], 0, stdMaxChars);
      sprintf(string[0], "                                                        ");
      sprintf(string[1], "                     /------------\\                     ");
      sprintf(string[2], "                    |              |                    ");
      sprintf(string[3], "                    | (O)      (O) |                    ");
      sprintf(string[4], "                    |  _________   |                    ");
      sprintf(string[5], "                    |  \\......./   |                    ");
      sprintf(string[6], "                     \\____________/                     ");
      sprintf(string[7], "                     /            \\                     ");
      sprintf(string[8], "                    /|\\          /|\\                    ");
      sprintf(string[9], "                  /-------------------\\     ___         ");
      sprintf(string[10],"                 | | %c %c |     | %c %c | |    | |        ",charPlayerInv[0],charPlayerInv[1],charPlayerInv[2],charPlayerInv[3]);
      sprintf(string[11],"                 | | %c %c |     | %c %c | |    | |        ",charPlayerInv[4],charPlayerInv[5],charPlayerInv[6],charPlayerInv[7]);
      sprintf(string[12],"                 |                     |    | |        ");
      sprintf(string[13],"                 |    ========\\\\   |%d|D|    | |        ", dealer.hp);
      sprintf(string[14],"                 |     \"\"\"    ||   |%d|P|    | |        ", player.hp);
      sprintf(string[15],"                 | items:              |    | |        ");
      sprintf(string[16],"                 | | %c %c |     | %c %c | |    | |        ",charDealerInv[0],charDealerInv[1],charDealerInv[2],charDealerInv[3]);
      sprintf(string[17],"                 | | %c %c |     | %c %c | |    | |        ",charDealerInv[4],charDealerInv[5],charDealerInv[6],charDealerInv[7]);
      sprintf(string[18],"                  \\-------------------/     \"\"\"         ");
      sprintf(string[19],"Hello...");

      putInsideBox(string, 20, 1, 1);
      //addSideInfo(string, stringSide, stringSideSize);
      for (int i = 0; i < 20; i++) {
        printf("%s\n", string[i]);
      }
      return;
    }
    if (currentGame.phase == 1) {
      // the scenario
      char string[20][stdMaxChars];
      for (int i = 0; i < 20; i++) memset(string[i], 0, stdMaxChars);
      sprintf(string[0], "                                                        ");
      sprintf(string[1], "                     /------------\\                     ");
      sprintf(string[2], "                    |              |                    ");
      sprintf(string[3], "                    | (O)      (O) |                    ");
      sprintf(string[4], "                    |  _________   |                    ");
      sprintf(string[5], "                    |  \\......./   |                    ");
      sprintf(string[6], "                     \\____________/                     ");
      sprintf(string[7], "                     /            \\                     ");
      sprintf(string[8], "                    /|\\          /|\\                    ");
      sprintf(string[9], "                  /-------------------\\     ___          ");
      sprintf(string[10],"                 |  |---------------|  |    | |          ");
      sprintf(string[11],"                 |  |General release|  |    | |          ");
      sprintf(string[12],"                 |  | of liability  |  |    | |          ");
      sprintf(string[13],"                 |  | ,.,..,......  |  |    | |          ");
      sprintf(string[14],"                 |  | ...,..,...,.. |  |    | |          ");
      sprintf(string[15],"                 |  | .,.......,.,. |  |    | |          ");
      sprintf(string[16],"                 |  | Name:         |  |    | |          ");
      sprintf(string[17],"                 |  |---------------|  |    | |          ");
      sprintf(string[18],"                  \\-------------------/     \"\"\"          ");
      sprintf(string[19],"Please sign the waiver");

      putInsideBox(string, 20, 1, 1);
      //addSideInfo(string, stringSide, stringSideSize);
      for (int i = 0; i < 20; i++) {
        printf("%s\n", string[i]);
      }
      return;
    }
    if (currentGame.phase == 2) {
      // the scenario
      char displayName[7];
      // this shi fills the displayname with spaces so it makes 6 characters so format n shit doesn't break
      strcpy(displayName, player.name);
      for (int i = strlen(displayName)-1; i < 6; i++) {
        strcat(displayName, " ");
      }
      char string[20][stdMaxChars];
      for (int i = 0; i < 20; i++) memset(string[i], 0, stdMaxChars);
      sprintf(string[0], "                                                        ");
      sprintf(string[1], "                     /------------\\                     ");
      sprintf(string[2], "                    |              |                    ");
      sprintf(string[3], "                    | (O)      (O) |                    ");
      sprintf(string[4], "                    |  _________   |                    ");
      sprintf(string[5], "                    |  \\......./   |                    ");
      sprintf(string[6], "                     \\____________/                     ");
      sprintf(string[7], "                     /            \\                     ");
      sprintf(string[8], "                    /|\\          /|\\                    ");
      sprintf(string[9], "                  /-------------------\\     ___          ");
      sprintf(string[10],"                 |  |---------------|  |    | |          ");
      sprintf(string[11],"                 |  |General release|  |    | |          ");
      sprintf(string[12],"                 |  | of liability  |  |    | |          ");
      sprintf(string[13],"                 |  | ,.,..,......  |  |    | |          ");
      sprintf(string[14],"                 |  | ...,..,...,.. |  |    | |          ");
      sprintf(string[15],"                 |  | .,.......,.,. |  |    | |          ");
      sprintf(string[16],"                 |  | Name: %s |  |    | |          ", displayName);
      sprintf(string[17],"                 |  |---------------|  |    | |          ");
      sprintf(string[18],"                  \\-------------------/     \"\"\"          ");
      sprintf(string[19],"                            ...                           ");

      putInsideBox(string, 20, 1, 1);
      //addSideInfo(string, stringSide, stringSideSize);
      for (int i = 0; i < 20; i++) {
        printf("%s\n", string[i]);
      }
      return;
    }
    if (currentGame.phase == 3) {
      // the scenario
      char bulletColor[currentGame.weapon->capacity][10];
      char bullet[currentGame.weapon->capacity];
      for (int i = 0; i < currentGame.weapon->capacity; i++) {
        if (currentGame.weapon->loadOrder[i] == 0) {
          strcpy(bulletColor[i], RESET);
          bullet[i] = ' ';
        }
        if (currentGame.weapon->loadOrder[i] == 1) {
          strcpy(bulletColor[i], RESET);
          bullet[i] = 'H';
        }
        if (currentGame.weapon->loadOrder[i] == 2) {
          strcpy(bulletColor[i], RED);
          bullet[i] = 'H';
        }
        
      }

      char charPlayerInv[8], charDealerInv[8];
      for (int i = 0; i < 8; i++) {
        charPlayerInv[i] = player.inv[i];
        charDealerInv[i] = dealer.inv[i];
      }
      transformNumberIntoPrintable(charPlayerInv, 8);
      transformNumberIntoPrintable(charDealerInv, 8);
      char string[20][stdMaxChars];
      for (int i = 0; i < 20; i++) memset(string[i], 0, stdMaxChars);
      sprintf(string[0], "                                                        ");
      sprintf(string[1], "                     /------------\\                     ");
      sprintf(string[2], "                    |              |                    ");
      sprintf(string[3], "                    | (O)      (O) |                    ");
      sprintf(string[4], "                    |  _________   |                    ");
      sprintf(string[5], "                    |  \\......./   |                    ");
      sprintf(string[6], "                     \\____________/                     ");
      sprintf(string[7], "                     /            \\                     ");
      sprintf(string[8], "                    /|\\          /|\\                    ");
      sprintf(string[9], "                  /-------------------\\     ___         ");
      sprintf(string[10],"                 | | %c %c |     | %c %c | |    |%s%c%s|        ",charPlayerInv[0],charPlayerInv[1],charPlayerInv[2],charPlayerInv[3], bulletColor[0], bullet[0], RESET);
      sprintf(string[11],"                 | | %c %c |     | %c %c | |    |%s%c%s|        ",charPlayerInv[4],charPlayerInv[5],charPlayerInv[6],charPlayerInv[7], bulletColor[1], bullet[1], RESET);
      sprintf(string[12],"                 |                     |    |%s%c%s|        ", bulletColor[2], bullet[2], RESET);
      sprintf(string[13],"                 |    ========\\\\   |%d|D|    |%s%c%s|        ", dealer.hp, bulletColor[3], bullet[3], RESET);
      sprintf(string[14],"                 |     \"\"\"    ||   |%d|P|    |%s%c%s|        ", player.hp, bulletColor[4], bullet[4], RESET);
      sprintf(string[15],"                 | items:              |    |%s%c%s|        ", bulletColor[5], bullet[5], RESET);
      sprintf(string[16],"                 | | %c %c |     | %c %c | |    |%s%c%s|        ",charDealerInv[0],charDealerInv[1],charDealerInv[2],charDealerInv[3], bulletColor[6], bullet[6], RESET);
      sprintf(string[17],"                 | | %c %c |     | %c %c | |    |%s%c%s|        ",charDealerInv[4],charDealerInv[5],charDealerInv[6],charDealerInv[7], bulletColor[7], bullet[7], RESET);
      sprintf(string[18],"                  \\-------------------/     \"\"\"         ");
      sprintf(string[19],"Here are the rounds");

      putInsideBox(string, 20, 1, 1);
      //addSideInfo(string, stringSide, stringSideSize);
      for (int i = 0; i < 20; i++) {
        printf("%s\n", string[i]);
      }
      return;
    }
  }
}

void printDeath() {
  /*
  the causes for one's death:
  0 - commiting suicide by jumping off at the club scene
  
  */
  // this shit is overflowing for sum reason idk why so find out why you stupid
  if (currentGame.over == 1) {
    char string[12][stdMaxChars];
    for (int i = 0; i < 12; i++) memset(string[i], 0, stdMaxChars);
    sprintf(string[0], "                                                                      ");
    sprintf(string[1], "                                                                      ");
    sprintf(string[2], "                                                                      ");
    sprintf(string[3], "  You are dead little bro                                             ");
    sprintf(string[4], "                                                                      ");
    sprintf(string[5], "             |     " RED "-." RESET "                                                 ");
    sprintf(string[6], "     ___     "RED "|" RESET "  ___                                                   ");
    sprintf(string[7], "  H_/   ###" RED "##" RESET "### " RED "   |..." RESET "                                               ");
    sprintf(string[8], "     ___########   |                                                  ");
    sprintf(string[9], "  __/        |  \"\"\"                                                   ");
    sprintf(string[10]," H           /                                                        ");
    sprintf(string[11],"                                                                      ");
    //info
    //char stringSide[4][stdMaxChars];
    //for (int i = 0; i < 4; i++) memset(stringSide[i], 0, stdMaxChars);
    //sprintf(stringSide[0], "lil bro is dead lmao lmao lmaoooo");
    //sprintf(stringSide[1], "lil bro is dead lmao lmao lmaoooo");
    //sprintf(stringSide[2], "lil bro is dead lmao lmao lmaoooo");
    //sprintf(stringSide[3], "lil bro is dead lmao lmao lmaoooo");
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
  system("clear");
}

