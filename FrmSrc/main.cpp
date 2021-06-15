#include "main.h"

using namespace std;

UI *Global_UI = nullptr;
PageManager *Global_PM = nullptr;

inline void setPage(){
	/// set your page here
}

inline void setLinkPage(){
	/// link your page here
}

inline void setLinkFunc(){
    /// link your function here
}

int main() {
    Global_PM = new PageManager;
    Global_UI = new UI(16, 16);
    SetConsoleTitle("Lenor's UI Presentation!");
    system("mode con cols=80 lines=40");
    UI::delay(500);
    Global_UI->textAnimation(20, 17, "Welcome to Lenor's UI Presentation!", CFC_Yellow, CBC_Black);
    UI::delay(1000);
    Global_UI->clear();
    char key;
    int page = 0, pre_page = -1;
    setPage();
    setLinkPage();
    setLinkFunc();
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
