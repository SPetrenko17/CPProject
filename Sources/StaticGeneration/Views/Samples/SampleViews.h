//
// Created by Сергей Петренко on 2019-12-18.
//

#ifndef CPPROJECT_SAMPLEVIEWS_H
#define CPPROJECT_SAMPLEVIEWS_H

#include <View/View.h>

#include "SecondaryView/SecondaryView.h"
#include "ImageView/ImageView.h"
#include "TextView/TextView.h"
#include "PersonView/PersonView.h"
#include "StaticGeneration/PageData/PageData.h"
#include "Form/FormView.h"
#include "StaticGeneration/PageGenerator/PageGenerator.h"


void
organizeCells(Organize o, int &rows, int &cells, int count) {
    switch (o) {
        case Organize::ONE_LINE_VERTICAL:
            rows = 1;
            cells = count;
            break;
        case Organize::ONE_LINE_HORIZONTAL:
            cells = 2;
            rows = count;
            break;

        case Organize::RECT_HORIZONTAL:
            break;
        case Organize::RECT_VERTICAL:
            break;
    }
}


View* createNavbar(){
    View *navBar = new View("mainNav", Type::NAV, BClass::MAIN_NAVBAR, "mainNav");


    navBar->append(*new View("Container", Type::DIV, BClass::CONTAINER));

    navBar->appendInSubview("Container", *new SecondaryView("jsScripts5", Type::A,
                                                            std::vector<Attribute>{
                                                                    Attribute(
                                                                            "class",
                                                                            enumToString(
                                                                                    BClass::NAVBAR_SCROLL_TRIGGER)),
                                                                    Attribute("href",
                                                                              "#page-top"),
                                                                    Attribute("TEXT",
                                                                              "Наш файндвейс"),
                                                            }));
    navBar->appendInSubview("Container", *new View("navbarResponsive", Type::DIV,
                                                   BClass::NAVBAR_COLLPAPSE,
                                                   "navbarResponsive"));

    navBar->appendInSubview("navbarResponsive",
                            *new View("navbarML", Type::UL, BClass::NAVBAR_ML));
    navBar->appendInSubview("navbarML",
                            *new View("navbarItem1", Type::LI, BClass::NAVBAR_ITEM));


    navBar->appendInSubview("navbarItem1",
                            *new SecondaryView("navbarLinkFind", Type::A,
                                               std::vector<Attribute>{
                                                       Attribute("class",
                                                                 enumToString(
                                                                         BClass::NAVBAR_LINK)),
                                                       Attribute("href", "#about"),
                                                       Attribute("TEXT",
                                                                 "Найти человечка"),
                                               }));

    navBar->appendInSubview("navbarML",
                            *new View("navbarItem2", Type::LI, BClass::NAVBAR_ITEM));
    navBar->appendInSubview("navbarItem2",
                            *new SecondaryView("navbarLinkAbout", Type::A,
                                               std::vector<Attribute>{
                                                       Attribute("class",
                                                                 enumToString(
                                                                         BClass::NAVBAR_LINK)),
                                                       Attribute("href",
                                                                 "#portfolio"),
                                                       Attribute("TEXT", "О нас"),
                                               }));

    return navBar;
}

View* createDecorate(){

    View *decorate = new View("Dec0", Type::DIV, BClass::DECORATION_DCDL);
    decorate->append(*new View("Dec1", Type::DIV, BClass::DECORATION_DCL));
    decorate->append(*new View("Dec2", Type::DIV, BClass::DECORATION_DCI));
    decorate->appendInSubview("Dec2", *new View("Dec3", Type::I,
                                                BClass::DECORATION_FFS));
    decorate->append(*new View("Dec3", Type::DIV, BClass::DECORATION_DCL));

    return decorate;
}

View* createHead(std::string name){
    View* head = new View("Head", Type::HEADER, BClass::MASTHEAD_PRIMARY_CENTER);

    head->append(*new View("FlexColumn", Type::DIV, BClass::FLEX_COLUMN));
    head->appendInSubview("FlexColumn", *new ImageView("Avatar", Type::IMG,
                                                       BClass::MASTHEAD_AVATAR,
                                                       "https://avatanplus.com/files/resources/original/5676944494b52151bf332c01.png"));
    head->appendInSubview("FlexColumn", *new TextView("HeadingText", Type::H1,
                                                      BClass::MASTHEAD_HEADING,
                                                      name));

    head->appendInSubview("FlexColumn", *createDecorate());
    return head;
}

View* createBar(std::string name){
    View* head = new View("Head", Type::HEADER, BClass::MASTHEAD_PRIMARY_CENTER);
    head->append(*new View("FlexColumn", Type::DIV, BClass::FLEX_COLUMN));
    head->appendInSubview("FlexColumn", *new TextView("HeadingText", Type::H1,
                                                      BClass::MASTHEAD_HEADING,
                                                      name));

    return head;
}

TableView* createUserTable(std::vector<UserData *> userData){

    std::vector<PersonView *> persons;
    int i = 0;
    for (auto &u : userData) {
        persons.push_back(new PersonView(*u, i++));
    }

    int rowsCount = 0;
    int cellsCount = 0;
    organizeCells(Organize::ONE_LINE_HORIZONTAL, rowsCount, cellsCount,
                  userData.size());

    TableView *tableView = new TableView("Table", rowsCount, cellsCount);
    int r = 0;
    int c = 0;
    tableView->appendCell(
            std::make_shared<CellView>(*new CellView(c, 4)));
    for (auto &p: persons) {
        tableView->appendRowInCell(c, std::make_shared<RowView>(
                *new RowView(r, *p)));
        r++;
        if (r >= rowsCount) {
            r = 0;
            tableView->appendCell(
                    std::make_shared<CellView>(*new CellView(++c, rowsCount)));
        }
    }
    return tableView;
}

TableView* createUserTable(std::vector<UserData *> userData, Organize organize){

    std::vector<PersonView *> persons;
    int i = 0;
    for (auto &u : userData) {
        persons.push_back(new PersonView(*u, i++));
    }

    int rowsCount = 0;
    int cellsCount = 0;
    organizeCells(organize, rowsCount, cellsCount,
                  userData.size());
    int num = 0;
    for(int i = 2; i <= userData.size();i+=2){
        num+=1;
    }

    switch(organize){
        case Organize::RECT_HORIZONTAL:
            rowsCount= userData.size()/num;
            cellsCount = userData.size()/rowsCount;
            rowsCount+=2;
            break;
    }

    TableView *tableView = new TableView("Table", rowsCount, cellsCount);
    int r = 0;
    int c = 0;
    tableView->appendCell(
            std::make_shared<CellView>(*new CellView(c, 4)));
    for (auto &p: persons) {
        tableView->appendRowInCell(c, std::make_shared<RowView>(
                *new RowView(r, *p)));
        r++;
        if (r >= rowsCount) {
            r = 0;
            c++;
            tableView->appendCell(
                    std::make_shared<CellView>(*new CellView(c, rowsCount)));
        }
    }
    return tableView;
}


View* createDevSection(std::vector<UserData *> userData, std::string title){
    View* devSection = new View("SectionDevelopers", Type::SECTION,
                                BClass::SECTION_PORTFOLIO, "portfolio");



    devSection->append(*new View("DevelopersContainer", Type::DIV,BClass::CONTAINER));

    devSection->append(*new TextView("DevsText", Type::H2,BClass::SECTION_HEADING, title));

    devSection->append( *createDecorate());

    devSection->appendInSubview("DevelopersContainer", *createUserTable(userData));

    return devSection;

}

View* createUserCard(UserData *userData){
    std::string title = userData->firstName + " " + userData->secondName;
    View* devSection = new View("SectionDevelopers", Type::SECTION,
                                BClass::SECTION_PORTFOLIO, "portfolio");


    devSection->append(*new View("FC",Type::DIV,BClass::CONTAINER));



    devSection->appendInSubview("FC",*new View("DevelopersContainer", Type::DIV,BClass::CONTAINER));


    devSection->appendInSubview("FC", *createDecorate());

    devSection->appendInSubview("DevelopersContainer", *new View("CenterUser",Type::DIV,BClass::FLEX_COLUMN));
    devSection->appendInSubview("CenterUser",*new PersonView(*userData, 0));

    devSection->appendInSubview("FC",*new TextView("DevsText", Type::H2,BClass::SECTION_HEADING,title));
    return devSection;

}

View* createFileForm(std::string link){
    View* sectionFile = new View("SectionFile", Type::SECTION, BClass::SECTION_FILE,"about");

    sectionFile->append( *new View("ContainerFile", Type::DIV,BClass::CONTAINER));
    const std::string fileText = "Выберите файл";
    sectionFile->append( *new TextView("UploadFile", Type::H2,BClass::SECTION_FILE_HEADING, fileText));
    sectionFile->append( *createDecorate());

    sectionFile->append(*new FormView("fileForm", link,
                                      "post", "multipart/form-data"));

    sectionFile->appendInSubview("fileForm", *new SecondaryView("FileInput", Type::INPUT,
                                                                std::vector<Attribute>{
                                                                        Attribute("type",
                                                                                  "file"),
                                                                        Attribute("id",
                                                                                  "image_uploads"),
                                                                        Attribute("name",
                                                                                  "image_uploads"),
                                                                        Attribute(
                                                                                "accept",
                                                                                ".jpg, .jpeg, .png")
                                                                }));
    sectionFile->appendInSubview("fileForm",
                                 *new SecondaryView("FileButtonInput", Type::BUTTON,
                                                    std::vector<Attribute>{
                                                            Attribute("TEXT", "Submit"),
                                                    }));
    return sectionFile;
}


View* createContactSection(){
    View* contactInfo = new View("SectionContact", Type::SECTION, BClass::PAGE_SECTION,
                                 "contact");
    contactInfo->append(
            *new View("ContactContainer", Type::DIV,
                      BClass::CONTAINER));
    contactInfo->append( *new View("FooterText", Type::FOOTER,
                                   BClass::FOOTER_TEXT));
    contactInfo->appendInSubview("FooterText", *new TextView("ContactText0", Type::H4,
                                                             BClass::MB4_UPCASE,
                                                             "Мы тута"));
    contactInfo->appendInSubview("FooterText",
                                 *new TextView("ContactFace", Type::P, BClass::MB0_LEAD,
                                               "МГТУ им. Н.Э. Баумана  ГЗ ауд.395"));
    return contactInfo;
}


#endif //CPPROJECT_SAMPLEVIEWS_H
