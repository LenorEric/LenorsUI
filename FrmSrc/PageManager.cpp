//
// Created by Lenor on 2021/6/15.
//

#include "PageManager.h"

PageManager::PageManager(): currentPage(0) {
}

int PageManager::newPage() {
    pg newPage;
    newPage.treeNum = currentPage;
    newPage.currentCol = 0;
    page.push_back(newPage);
    return this->currentPage++;
}

void PageManager::addContent(int pageNumber, string content, ConsoleForegroundColor FC, ConsoleBackGroundColor BC) {
    this->page[pageNumber].content.push_back(content);
    this->page[pageNumber].mapPage.push_back(pageNumber);
    this->page[pageNumber].fcc.push_back(FC);
    this->page[pageNumber].bcc.push_back(BC);
}

pg PageManager::getPage(int pageNumber) {
    return this->page[pageNumber];
}

void PageManager::linkPage(int tp, int column, int pageNumber) {
    this->page[tp].mapPage[column] = pageNumber;
}

string PageManager::getLineContent(int pageNumber) {
    if (this->page[pageNumber].currentCol == this->page[pageNumber].content.size())
        return "";
    return this->page[pageNumber].content[this->page[pageNumber].currentCol++];
}

void PageManager::resetLinePage(int pageNumber) {
    this->page[pageNumber].currentCol = 0;
}

int PageManager::getPageSize(int pageNumber) {
    return this->page[pageNumber].content.size();
}

int PageManager::getLink(int tp, int column) {
    return this->page[tp].mapPage[column];
}

void PageManager::linkFunc(int tp, int column, PF func) {
    int hash;
    string feat = to_string(tp) + to_string(column);
    Hash_x86_32(feat.c_str(), feat.length(), SEED, &hash);
    this->execl.insert(pair<int, PF>(hash, func));
    this->linkPage(tp, column, -2);
}

void PageManager::execFunc(int tp, int column) {
    map<int, PF>::iterator iter;
    int hash;
    string feat = to_string(tp) + to_string(column);
    Hash_x86_32(feat.c_str(), feat.length(), SEED, &hash);
    iter = this->execl.find(hash);
    iter->second();
}


