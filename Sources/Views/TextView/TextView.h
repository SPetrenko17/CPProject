//
// Created by Сергей Петренко on 2019-11-16.
//

#ifndef CPPROJECT_TEXTVIEW_H
#define CPPROJECT_TEXTVIEW_H


#include "../View/View.h"

class TextView: public View{
private:
    string text;
public:
    TextView();
    TextView(string m_text);
    void set_text(string m_text);
    string get_text();

};


#endif //CPPROJECT_TEXTVIEW_H
