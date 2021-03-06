//
// Created by Сергей Петренко on 2019-11-08.
//
#include <ImageView/ImageView.h>
#include <TextView/TextView.h>
#include <TableView/TableView.h>
#include "gtest/gtest.h"
#include "Container/ContainerView.h"
#include "Container/ContainerView.cpp"
#include "View/View.h"
#include "View/View.cpp"

class TestViews : public ::testing::Test
{
protected:
    View*  view;

    void SetUp() override
    {
    view = new View("testname", Type::DIV,BClass::CARD_DECK);
    }
    void TearDown() override
    {
        delete view;
    }
};

TEST_F(TestViews, test_view_constructor)
{
    EXPECT_EQ(view->toString(),"<div class=\"card-deck mb-3 text-center\" action= id= \"\">\n\n</div>\n\n");
}

TEST_F(TestViews, test_append_in_view)
{
    view->append(*new View("testsubview",Type::DIV,BClass::CARD_MB4_SHADOW));
    EXPECT_EQ(view->toString(),"<div class=\"card-deck mb-3 text-center\" action= id= \"\">\n\n   <div class=\"card mb-4 shadow-sm\">\n\n   </div>\n\n</div>\n\n");
}

TEST_F(TestViews, test_delete_subview)
{
    //view->append(*new View("test",Type::DIV,BClass::CARD_MB4_SHADOW));
    view->removeSubview("testsubview");
    EXPECT_EQ(view->toString(),"<div class=\"card-deck mb-3 text-center\" action= id= \"\">\n\n</div>\n\n");
}







