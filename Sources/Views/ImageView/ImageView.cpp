//
// Created by Сергей Петренко on 2019-11-16.
//

#include "ImageView.h"


ImageView::ImageView() {

}

ImageView::ImageView(string m_image_path) : View(m_image_path) {

}

void ImageView::set_image_path(string m_image_path) {

}

string ImageView::get_image_path() {
    return std::string();
}
