#ifndef MENUTOOLS_H
#define MENUTOOLS_H

#include <cctype>
#include "songlist.h"


void start();
void displayMenu();
char readInCommand();
void executeCommand(SongList& list, const char filename[], char cmd);
void farewell();
void logo();

#endif
