#include "main.h"

using namespace std;

UI *Global_UI = nullptr;
PageManager *Global_PM = nullptr;

void printTestString1() {
    Global_UI->textAnimation(0, 0, "Hello? Would you stay with me for a while?", CFC_Green, CBC_Yellow);
    Global_UI->delay(1000);
    Global_UI->textAnimation(0, 0, "                                             ", CFC_Black, CBC_Black);
}

void printTestString2() {
    Global_UI->textAnimation(0, 0, "I will show you my frame!", CFC_Green, CBC_Yellow);
    Global_UI->delay(1000);
    Global_UI->textAnimation(0, 0, "                                       ", CFC_Black, CBC_Black);
}

int main() {
    Global_PM = new PageManager;
    Global_UI = new UI(16, 16);
    SetConsoleTitle("Lenor's UI Presentation!");
    system("mode con cols=80 lines=40");
    Global_UI->delay(500);
    Global_UI->textAnimation(20, 17, "Welcome to Lenor's UI Presentation!", CFC_Yellow, CBC_Black);
    Global_UI->delay(1000);
    Global_UI->clear();
    char key;
    int page = 0, pre_page = -1;

    Global_PM->newPage();
    Global_PM->addContent(0, "Login", CFC_Green, CBC_Yellow);
    Global_PM->addContent(0, "Register", CFC_Green, CBC_Black);
    Global_PM->addContent(0, "Quit(Esc)", CFC_Gray, CBC_Black);
    Global_PM->newPage();
    Global_PM->addContent(1, "User1", CFC_Green, CBC_Yellow);
    Global_PM->addContent(1, "User2", CFC_Green, CBC_Black);
    Global_PM->addContent(1, "Return", CFC_Gray, CBC_Black);
    Global_PM->newPage();
    Global_PM->addContent(2, "User1", CFC_Green, CBC_Yellow);
    Global_PM->addContent(2, "User2", CFC_Green, CBC_Black);
    Global_PM->addContent(2, "User3", CFC_Green, CBC_Black);
    Global_PM->addContent(2, "Return", CFC_Gray, CBC_Black);
    Global_PM->linkPage(0, 0, 1);
    Global_PM->linkPage(0, 1, 2);
    Global_PM->linkPage(0, 2, -1);
    Global_PM->linkPage(1, 2, 0);
    Global_PM->linkPage(2, 3, 0);
    Global_PM->linkFunc(1, 0, printTestString1);
    Global_PM->linkFunc(1, 1, printTestString2);
    Global_PM->linkFunc(2, 0, printTestString1);
    Global_PM->linkFunc(2, 1, printTestString2);
    Global_PM->linkFunc(2, 2, printTestString2);

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
    while (true) {
        if (page != pre_page) {
            pre_page = page;
            Global_UI->drawPage(Global_PM->getPage(page));
        }
        key = getch();
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
        if (key == 13) {
            if (Global_PM->getLink(page, Global_UI->selectedColumns) != -2)
                page = Global_PM->getLink(page, Global_UI->selectedColumns);
            else {
                Global_PM->execFunc(page, Global_UI->selectedColumns);
            }
        }
        if (key == 27 || page == -1)
            break;
    }

#pragma clang diagnostic pop
    return 0;
}
