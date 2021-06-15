//
// Created by Lenor on 2021/6/15.
//

#ifndef LENORSBOOKSTORE_PAGEMANAGER_H
#define LENORSBOOKSTORE_PAGEMANAGER_H

#include "GLOBALINCLUDE.h"
#include "UI.h"

class PageManager {
public:
private:
    vector<pg> page;
    map<int, PF> execl;
    int currentPage;
public:
    PageManager();
    int newPage();
    void addContent(int pageNumber, string content, ConsoleForegroundColor FC, ConsoleBackGroundColor BC);
    void linkPage(int tp, int column, int pageNumber);
    void linkFunc(int tp, int column, PF func);
    void execFunc(int tp, int column);
    pg getPage(int pageNumber);
    string getLineContent(int pageNumber);
    void resetLinePage(int pageNumber);
    int getPageSize(int pageNumber);
    int getLink(int tp, int column);
};


#endif //LENORSBOOKSTORE_PAGEMANAGER_H
