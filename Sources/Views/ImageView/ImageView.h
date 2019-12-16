//
// Created by Сергей Петренко on 2019-11-16.
//

#ifndef CPPROJECT_IMAGEVIEW_H
#define CPPROJECT_IMAGEVIEW_H


#include "../View/View.h"

class ImageView: public View{
private:
    string image_path;
public:
    ImageView();
    ImageView(string m_image_path);
    void set_image_path(string m_image_path);
    string get_image_path();

};


#endif //CPPROJECT_IMAGEVIEW_H
