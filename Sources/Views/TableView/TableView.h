//
// Created by Сергей Петренко on 2019-11-16.
//

#ifndef CPPROJECT_TABLEVIEW_H
#define CPPROJECT_TABLEVIEW_H


#include <vector>
#include "../Container/ContainerView.h"
#include "../Column/ColumnView.h"
#include "../View/View.h"

class TableView: public ContainerView{
private:
    int rows_count;
    int columns_count;
protected:
    vector<ColumnView> rows;
public:
    TableView();
    TableView(int rows, int columns);
    void append_in_row(View m_view, string path);
    void remove_column(View m_view, string path);
    void remove_row(View m_row, string path);
    int get_row_count();
    int get_colums_count();

};


#endif //CPPROJECT_TABLEVIEW_H
