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
    /// 页面列表
    vector<pg> page;
    /// 函数调用关系
    map<int, PF> execl;
    /// 当前待写入的页面
    int currentPage;
public:
    PageManager();

    /// 建立一个新的页面
    int newPage();

    /// 向页面添加内容
    void addContent(int pageNumber, string content, ConsoleForegroundColor FC, ConsoleBackGroundColor BC);

    /// 链接一个选项和一个页面
    void linkPage(int tp, int column, int pageNumber);

    /// 链接一个选项和一个函数
    void linkFunc(int tp, int column, PF func);
    /// 执行某一个函数
    void execFunc(int tp, int column);
    /// 返回某一个页面的信息（供绘制页面）
    pg getPage(int pageNumber);
    /// 获取页面文字内容(未使用)
    string getLineContent(int pageNumber);
    ///重置页面行计数器(未使用)
    void resetLinePage(int pageNumber);
    /// 获取页面条目个数(未使用)
    int getPageSize(int pageNumber);
    /// 获取选项与页面的链接
    int getLink(int tp, int column);
};


#endif //LENORSBOOKSTORE_PAGEMANAGER_H
