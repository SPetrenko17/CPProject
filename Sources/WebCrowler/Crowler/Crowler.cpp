#include "Crowler.h"
#include <iostream>
#include <utility>


void addToBd(const std::vector<double> &vec, const std::string &url) {} //Функция из библиотеки Александра


Crowler::Crowler(std::shared_ptr<AbstractAPI> m_api, std::shared_ptr<AbstractIdListGeneratorStrategy> m_lg, DB* m_db) {
    api = std::move(m_api);
    lg = std::move(m_lg);
    db=m_db;
}


void Crowler::startCrowl() {
    t = new std::thread(std::bind(&Crowler::crowl, this));

}

void Crowler::stopCrowl() {
    thread_must_end = true;

}


std::vector<double> vectorize(const std::string &url) { //Функция из библиотеки Димы
    std::vector<double> res = {1.1,2.1,3.2,4.1};
    return res;
}

void Crowler::crowl() {

    while (true) {

        std::vector<url> id_list = lg->generate();
        for (const auto &id: id_list) {
            std::vector<url> photoUrls = api->getPhotoUrlsById(id);
            for (auto &data: photoUrls) {
                db->add(vectorize(data.toStr()), data.toStr());
                std::cout << data.toStr() << std::endl;
            }
        }

        lg->save();
        if (thread_must_end) break;

    }

}
