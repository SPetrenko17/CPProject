#pragma once
#include "Crowler.h"
#include <iostream>
#include <utility>
#include <sstream>
#include "PythonMagic.h"




Crowler::Crowler(std::shared_ptr <AbstractAPI> m_api, std::shared_ptr <AbstractIdListGeneratorStrategy> m_lg,
                 DB *m_db) {
    api = std::move(m_api);
    lg = std::move(m_lg);
    db = m_db;
}


void Crowler::startCrowl() {
    t = new std::thread(std::bind(&Crowler::crowl, this));

}

void Crowler::stopCrowl() {
    thread_must_end = true;
    t->join();
}

void Crowler::crowl() {
    int i = 0;
    while (true) {
        std::vector <url> id_list = lg->generate();
        for (auto &id: id_list) {
            std::cout<<"fuck iterator "<<i<<std::endl;
            std::vector <url> photoUrls = api->getPhotoUrlsById(id);
            for (auto &data: photoUrls) {
                i++;
                std::cout<<"fuck in for 1 ";
                for(auto &vec : getFacesVector(data.toStr())){
                    db->add(vec, id.toStr());
                    std::cout<<"fuck in for 2 ";
                }
                std::cout<<"size test  "<< getFacesVector("https://24smi.org/public/media/resize/800x-/2018/10/16/30085313-161676521175028-6270825408061505536-n-768x512.jpg").size()<<std::endl;
                if(i>65) {
                    std::cout << "fuck in if ";
                    //https://sun1-21.userapi.com/aoScR-V4kf9axO199_5HxEhPKvXEU7HLzk9IQQ/I0YMwTxVZDY.jpg
                    // https://sun9-44.userapi.com/c626426/v626426007/3acf7/EmSwIvCDbnI.jpg
                    try {
                        std::cout << "ANSWER 1   "
                                  << db->search_engine->get_best_match(
                                          getFacesVector(
                                                  "https://24smi.org/public/media/resize/800x-/2018/10/16/30085313-161676521175028-6270825408061505536-n-768x512.jpg")[0])[0]
                                  << std::endl;
                        std::cout << "ANSWER 2   "
                                  << db->search_engine->get_best_match(
                                          getFacesVector(
                                                  "https://sun1-21.userapi.com/aoScR-V4kf9axO199_5HxEhPKvXEU7HLzk9IQQ/I0YMwTxVZDY.jpg")[0])[0]
                                  << std::endl;
                        std::cout << "ANSWER 2   "
                                  << db->search_engine->get_best_match(
                                          getFacesVector(
                                                  " https://sun9-44.userapi.com/c626426/v626426007/3acf7/EmSwIvCDbnI.jpg")[0])[0]
                                  << std::endl;
                    }
                    catch(int a){

                    }
                }
                std::cout << data.toStr() <<" ____ "<<id.toStr()<< std::endl;
            }
        }

        lg->save();
        if (thread_must_end) break;

    }

}


std::vector<std::vector<double>> Crowler::getFacesVector(std::string link) {
    char buffer[128];
    std::string cmd = "python3 python_magic.py " + link;
    std::string result = "";
    FILE* pipe = popen(cmd.c_str(), "r");
    if (!pipe) throw std::runtime_error("popen() failed!");
    try {
        while (fgets(buffer, sizeof buffer, pipe) != NULL) {
            result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
    std::stringstream output(result);
    int n;
    output >> n;
    //std::cout << n;
    std::vector<std::vector<double>> faces;
    std::vector<double> tmp_vector;
    std::string num;
    while(output >> num) {
        if(num[0] == '[') {
            tmp_vector.clear();
            num.erase(num.begin());
        } else if(num.back() == ']'){
            num.pop_back();
            if(!num.empty()) {
                tmp_vector.push_back(std::stod(num));
            }
            faces.push_back(tmp_vector);
            continue;
        }
        tmp_vector.push_back(std::stod(num));
    }
    return faces;
}
