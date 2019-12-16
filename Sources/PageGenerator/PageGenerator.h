//
// Created by Сергей Петренко on 2019-11-16.
//

#ifndef CPPROJECT_PAGEGENERATOR_H
#define CPPROJECT_PAGEGENERATOR_H
#include "../../Page/Page.h"

class PageGenerator{
private:
    std::string url;
    PageData data;
protected:
    Page page;
public:
    PageGenerator();
    Page generate_start_page();
    Page generate_result_page(PageData m_data);
    PageData get_page_data();

};


#endif //CPPROJECT_PAGEGENERATOR_H
