#include "main.h"

using namespace std;

UI *Global_UI = nullptr;
PageManager *Global_PM = nullptr;

namespace func {
/// 样例函数1
    void printTestString1() {
        Global_UI->textAnimation(0, 0, "Hello? Would you stay with me for a while?", CFC_Green, CBC_Yellow);
        UI::delay(1000);
        Global_UI->textAnimation(0, 0, "                                             ", CFC_Black, CBC_Black);
    }

/// 样例函数2
    void printTestString2() {
        Global_UI->textAnimation(0, 0, "I will show you my frame!", CFC_Green, CBC_Yellow);
        UI::delay(1000);
        Global_UI->textAnimation(0, 0, "                                       ", CFC_Black, CBC_Black);
    }

    void printTestString3() {
        Global_UI->textAnimation(0, 0, "Lenours!", CFC_Green, CBC_Yellow);
        UI::delay(1000);
        Global_UI->textAnimation(0, 0, "                                       ", CFC_Black, CBC_Black);
    }
}

namespace init {
/// 初始化页面信息，新建页面并添加内容
    inline void setPage() {
        int currentPage;
        currentPage = Global_PM->newPage();
        Global_PM->addContent(currentPage, "Login", CFC_Green, CBC_Yellow);
        Global_PM->addContent(currentPage, "Register", CFC_Green, CBC_Black);
        Global_PM->addContent(currentPage, "Quit(Esc)", CFC_Gray, CBC_Black);
        currentPage = Global_PM->newPage();
        Global_PM->addContent(currentPage, "User1", CFC_Green, CBC_Yellow);
        Global_PM->addContent(currentPage, "User2", CFC_Green, CBC_Black);
        Global_PM->addContent(currentPage, "Return", CFC_Gray, CBC_Black);
        currentPage = Global_PM->newPage();
        Global_PM->addContent(currentPage, "User1", CFC_Green, CBC_Yellow);
        Global_PM->addContent(currentPage, "User2", CFC_Green, CBC_Black);
        Global_PM->addContent(currentPage, "Return", CFC_Gray, CBC_Black);
    }

/// 设置选项与页面之间的跳转关系
    inline void setLinkPage() {
        Global_PM->linkPage(0, 0, 1);
        Global_PM->linkPage(0, 1, 2);
        Global_PM->linkPage(0, 2, -1);
        Global_PM->linkPage(1, 2, 0);
        Global_PM->linkPage(2, 3, 0);
    }

/// 设置选项与函数的调用关系
    inline void setLinkFunc() {
        Global_PM->linkFunc(1, 0, func::printTestString1);
        Global_PM->linkFunc(1, 1, func::printTestString2);
        Global_PM->linkFunc(2, 0, func::printTestString1);
        Global_PM->linkFunc(2, 1, func::printTestString3);
    }
}

int main() {
    /// 类的实例化
    Global_PM = new PageManager;
    Global_UI = new UI(16, 16);
    /// 显示欢迎界面并初始化
    SetConsoleTitle("Lenor's UI Presentation!");
    system("mode con cols=80 lines=40");
    UI::delay(500);
    Global_UI->textAnimation(20, 17, "Welcome to Lenor's UI Presentation!", CFC_Yellow, CBC_Black);
    UI::delay(1000);
    Global_UI->clear();
    char key;
    int page = 0, pre_page = -1;
    init::setPage();
    init::setLinkPage();
    init::setLinkFunc();
#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
    /// 开始页面检测
    while (true) {
        /// 如果页面切换了，则更新页面
        if (page != pre_page) {
            pre_page = page;
            Global_UI->drawPage(Global_PM->getPage(page));
        }
        key = (char)getch();
        /// 检测是否有上下键的操作（72是上，80是下）
        switch (key) {
            case 72:
                Global_UI->highLight(-1);
                break;
            case 80:
                Global_UI->highLight(1);
                break;
            default:
                break;
        }
        /// 如果选择了某一选项(enter)
        if (key == 13) {
            if (Global_PM->getLink(page, Global_UI->selectedColumns) != -2)
                page = Global_PM->getLink(page, Global_UI->selectedColumns);
            else {
                Global_PM->execFunc(page, Global_UI->selectedColumns);
            }
        }
        /// 如果按了ESC或者选择了退出页面的选项
        if (key == 27 || page == -1)
            break;
    }
#pragma clang diagnostic pop
    return 0;
}
