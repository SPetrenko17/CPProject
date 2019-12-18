//
// Created by Сергей Петренко on 2019-11-16.
//

#include "PageGenerator.h"

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

Page *
PageGenerator::generateTablePage(std::vector<UserData *> userData, Organize o) {
    page = new Page();
    std::vector<PersonView *> persons;
    for (auto &u : userData) {
        persons.push_back(new PersonView(*u));
    }

    int rowsCount = 0;
    int cellsCount = 0;
    organizeCells(o, rowsCount, cellsCount, userData.size());

    View *view = new View("Main", Type::DIV, BClass::CARD_DECK);

    TableView *tableView = new TableView("Table", rowsCount, cellsCount);
    int r = 0;
    int c = 0;
    tableView->appendCell(
            std::make_shared<CellView>(*new CellView(c, rowsCount)));
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
    page->appendInBody(*tableView);
    return page;
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

View* createDevSection(){
    View* devSection = new View("SectionDevelopers", Type::SECTION,
                                BClass::SECTION_PORTFOLIO, "portfolio");

    devSection->append(*new View("DevelopersContainer", Type::DIV,BClass::CONTAINER));
    devSection->append(*new TextView("DevsText", Type::H2,BClass::SECTION_HEADING, "Лучшие разрабы"));
    devSection->append( *createDecorate());

    std::vector<UserData *> userData{
            new UserData("Stalin.su", "Дмитрий", "Болдин",
                         "https://sun9-70.userapi.com/c205424/v205424565/2840/Q9ExfkJtduQ.jpg",
                         19),
            new UserData("Kek", "Дмитрий", "Гуляченков",
                         "https://sun9-14.userapi.com/c844321/v844321164/1e3f38/sjVui97PcoU.jpg",
                         19),
            new UserData("Averkiller", "Александр", "Аверкиев",
                         "https://sun9-6.userapi.com/c857536/v857536032/10e4a0/yPxRO3gAIb0.jpg",
                         19),
            new UserData("Sarkiss", "Сергей", "Петренко",
                         "https://sun9-49.userapi.com/c850732/v850732072/7dac/26Ja2edmJwU.jpg",
                         19)
    };



    std::vector<PersonView *> persons;
    for (auto &u : userData) {
        persons.push_back(new PersonView(*u));
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

    devSection->append( *tableView);


    return devSection;

}


Page *PageGenerator::generateStartPage() {
    page = new Page();

    View *v = new View("Main", Type::DIV);
    View *nav = createNavbar();
    v->append(*nav);


    const std::string name = "Наш файндфейс!";
    const std::string devs = "Лучшие разрабы";

    v->append(*createHead(name));


    v->append(*createDevSection());




    v->append(*new View("SectionFile", Type::SECTION, BClass::SECTION_FILE,
                        "about"));
    v->appendInSubview("SectionFile", *new View("ContainerFile", Type::DIV,
                                                BClass::CONTAINER));
    const std::string fileText = "Выберите файл";
    v->appendInSubview("ContainerFile", *new TextView("UploadFile", Type::H2,
                                                      BClass::SECTION_FILE_HEADING,
                                                      fileText));
    v->appendInSubview("ContainerFile", *createDecorate());

    v->appendInSubview("ContainerFile",
                       *new FormView("fileForm", "http://127.0.0.1:8000",
                                     "post", "multipart/form-data"));

    v->appendInSubview("fileForm", *new SecondaryView("FileInput", Type::INPUT,
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
    v->appendInSubview("fileForm",
                       *new SecondaryView("FileButtonInput", Type::BUTTON,
                                          std::vector<Attribute>{
                                                  Attribute("TEXT", "Submit"),
                                          }));


    v->append(*new View("SectionContact", Type::SECTION, BClass::PAGE_SECTION,
                        "contact"));

    v->appendInSubview("SectionContact",
                       *new View("ContactContainer", Type::DIV,
                                 BClass::CONTAINER));
    v->appendInSubview("ContactContainer", *new View("FooterText", Type::FOOTER,
                                                     BClass::FOOTER_TEXT));
    v->appendInSubview("FooterText", *new TextView("ContactText0", Type::H4,
                                                   BClass::MB4_UPCASE,
                                                   "Мы тута"));
    v->appendInSubview("FooterText",
                       *new TextView("ContactFace", Type::P, BClass::MB0_LEAD,
                                     "МГТУ им. Н.Э. Баумана  ГЗ ауд.395"));


    page->appendInBody(*v);

    return page;
}

Page *PageGenerator::generateUserPage(UserData userData) {
    Page *page = new Page();
    return page;
}

