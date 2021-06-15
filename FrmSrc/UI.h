//
// Created by Lenor on 2021/6/15.
//

#ifndef LENORSBOOKSTORE_UI_H
#define LENORSBOOKSTORE_UI_H

#include "GLOBALINCLUDE.h"


class UI {
public:
    int selectedColumns;

private:
    int column, columns;
    int posX;
    vector<string> textList;
    vector<ConsoleForegroundColor> fcList;
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    void pos(int x, int y);

public:
    UI(int column, int posX);

    static void delay(const int &time);

    void lineAnimation(string text, ConsoleForegroundColor FC, ConsoleBackGroundColor BC);

    void clear();

    void changeColor(int col, ConsoleForegroundColor FC, ConsoleBackGroundColor BC);

    void highLight(int direction);

    void textAnimation(int x, int y, const string &text, ConsoleForegroundColor FC, ConsoleBackGroundColor BC);

    void drawPage(pg curPage);
};


#endif //LENORSBOOKSTORE_UI_H
