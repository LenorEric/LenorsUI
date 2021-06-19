//
// Created by Lenor on 2021/6/14.
//

#ifndef LENORSBOOKSTORE_GLOBALINCLUDE_H
#define LENORSBOOKSTORE_GLOBALINCLUDE_H

#include <cstdio>
#include <iosfwd>
#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <vector>
#include <map>


#define LENORDEBUG
#define SEED 0x97c29b3a

using namespace std;

enum ConsoleForegroundColor {
    CFC_Red = FOREGROUND_INTENSITY | FOREGROUND_RED,
    CFC_Green = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
    CFC_Blue = FOREGROUND_INTENSITY | FOREGROUND_BLUE,
    CFC_Yellow = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
    CFC_Purple = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE,
    CFC_Cyan = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
    CFC_Gray = FOREGROUND_INTENSITY,
    CFC_White = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
    CFC_HighWhite = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
    CFC_Black = 0,
};
enum ConsoleBackGroundColor {
    CBC_Red = BACKGROUND_INTENSITY | BACKGROUND_RED,
    CBC_Green = BACKGROUND_INTENSITY | BACKGROUND_GREEN,
    CBC_Blue = BACKGROUND_INTENSITY | BACKGROUND_BLUE,
    CBC_Yellow = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN,
    CBC_Purple = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE,
    CBC_Cyan = BACKGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE,
    CBC_White = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
    CBC_HighWhite = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
    CBC_Black = 0,
};
struct pg{
    int treeNum;
    int currentCol = 0;
    vector<string> content;
    vector<ConsoleForegroundColor> fcc;
    vector<ConsoleBackGroundColor> bcc;
    vector<int> mapPage;
};
typedef void (*PF)();

#endif //LENORSBOOKSTORE_GLOBALINCLUDE_H
