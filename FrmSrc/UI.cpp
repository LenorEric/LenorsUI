//
// Created by Lenor on 2021/6/15.
//

#include "UI.h"

void UI::delay(const int &time) {
    clock_t now = clock();
    while (clock() - now < time) {
    }
}

void UI::textAnimation(int x, int y, const string& text, ConsoleForegroundColor FC, ConsoleBackGroundColor BC) {
    SetConsoleTextAttribute(hOut, FC | BC);
    pos(x, y);
    for (char i : text) {
        putchar(i);
        delay(10);
    }
    SetConsoleTextAttribute(hOut, CFC_Black | CBC_Black);
}

void UI::pos(int x, int y) {
    COORD posPoint = {(short) x, (short) y}; //设置坐标
    SetConsoleCursorPosition(hOut, posPoint);
}

void UI::lineAnimation(string text, ConsoleForegroundColor FC, ConsoleBackGroundColor BC) {
    this->textAnimation(this->posX, this->column + this->columns, text, FC, BC);
    this->columns++;
    this->textList.push_back(text);
    this->fcList.push_back(FC);
}

UI::UI(int column, int posX) :
        column(column),
        posX(posX),
        columns(0),
        selectedColumns(0) {}

void UI::clear() {
    system("cls");
    this->columns = 0;
    this->textList.clear();
    this->fcList.clear();
    this->selectedColumns = 0;
}

void UI::highLight(int direction) {
    if (this->selectedColumns + direction < 0 || this->selectedColumns + direction >= columns)
        return;
    changeColor(this->selectedColumns, this->fcList[this->selectedColumns], CBC_Black);
    this->selectedColumns += direction;
    changeColor(this->selectedColumns, this->fcList[this->selectedColumns], CBC_Yellow);
}

void UI::changeColor(int col, ConsoleForegroundColor FC, ConsoleBackGroundColor BC) {
    textAnimation(this->posX, col + this->column, textList[col], FC, BC);
}

void UI::drawPage(pg curPage) {
    this->clear();
    for (int i = 0; i < curPage.mapPage.size(); i++) {
        this->lineAnimation(curPage.content[i], curPage.fcc[i], curPage.bcc[i]);
    }
}


