//
// Created by Lenor on 2021/6/15.
//

#ifndef LENORSBOOKSTORE_UI_H
#define LENORSBOOKSTORE_UI_H

#include "GLOBALINCLUDE.h"


class UI {
public:
    /// 当前选择的行
    int selectedColumns;

private:
    /// 起始绘制行与绘制的行数
    int column, columns;
    /// 起始绘制的字符数
    int posX;
    /// 当前文字列表
    vector<string> textList;
    /// 默认前景色列表
    vector<ConsoleForegroundColor> fcList;
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    /// 定位器
    void pos(int x, int y);

public:
    UI(int column, int posX);
    /// 延时函数
    static void delay(const int &time);
    /// 以动画的形式绘制下一行
    void lineAnimation(const string& text, ConsoleForegroundColor FC, ConsoleBackGroundColor BC);
    ///清除当前页面
    void clear();
    /// 更改某一行的颜色（不改变文字）
    void changeColor(int col, ConsoleForegroundColor FC, ConsoleBackGroundColor BC);
    /// 高亮上一行或下一行
    void highLight(int direction);
    /// 动画的形式在特定位置绘制内容
    void textAnimation(int x, int y, const string &text, ConsoleForegroundColor FC, ConsoleBackGroundColor BC);
    /// 在特定位置显示内容
    void textDisplay(int x, int y, const string &text, ConsoleForegroundColor FC, ConsoleBackGroundColor BC);
    /// 绘制一整个页面
    void drawPage(Pg curPage);
};


#endif //LENORSBOOKSTORE_UI_H
