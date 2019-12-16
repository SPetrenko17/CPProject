//
// Created by Сергей Петренко on 2019-11-16.
//

#ifndef CPPROJECT_PAGEMANAGER_H
#define CPPROJECT_PAGEMANAGER_H

#include "../PageGenerator/Pagegenerator.cpp"
class PageManager {

};

class PageManager{
private:
    PageData data;
    PageGenerator pageGenerator;
public:
    PageManager();
    PageManager(PageData m_data);
    void get_from_server();
    void push_to_server();
    PageGenerator get_page_generator();

};

#endif //CPPROJECT_PAGEMANAGER_H
