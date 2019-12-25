#include <iostream>
#include <vector>
#include <StaticGeneration/PageGenerator/PageGenerator.h>
#include "WebServer/HttpRequest/HttpRequest.h"
#include "WebServer/HttpResponse/HttpResponse.h"
#include "WebServer/Server/Server.h"
#include "WebCrowler/Crowler/Crowler.h"
#include "WebCrowler/Id_list_generator_strategy/Vk_id_list_generator_strategy.h"
#include "WebCrowler/API/VkAPI.h"
#include "DataBase/KD/DB.h"
#include <mongocxx/client.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/instance.hpp>


const int port = 8092;

//////////////////////////////////////////////////////////////////////////////DB
std::string readKeyFromFile() {
    std::string key;
    std::ifstream fin("kdkey.txt");
    fin >> key;
    fin.close();
    return key;
}

void writeKeyToFile(const std::string &key) {
    std::ofstream fout("kdkey.txt");
    fout << key;
    fout.close();
}

mongocxx::instance inst{};
mongocxx::client conn{mongocxx::uri{}};
mongocxx::v_noabi::collection collection = conn["testdb"]["testcollection"];

DB *db;



//////////////////////////////////////////////////////////////////////////Python
std::vector <std::vector<double>> getFacesVector(std::string link) {
    char buffer[128];
    std::string cmd = "python3 python_magic.py " + link;
    std::string result = "";
    FILE *pipe = popen(cmd.c_str(), "r");
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
    std::vector <std::vector<double>> faces;
    std::vector<double> tmp_vector;
    std::string num;
    while (output >> num) {
        if (num[0] == '[') {
            tmp_vector.clear();
            num.erase(num.begin());
        } else if (num.back() == ']') {
            num.pop_back();
            if (!num.empty()) {
                tmp_vector.push_back(std::stod(num));
            }
            faces.push_back(tmp_vector);
            continue;
        }
        tmp_vector.push_back(std::stod(num));
    }
    return faces;
}


//////////////////////////////////////////////////////////////////////////Server
HttpResponse api_method(HttpRequest request) {
    std::vector < UserData * > userData{
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
    HttpResponse response;
    PageGenerator *pageGenerator = new PageGenerator(port);
    pageGenerator->generateStartPage(userData);
    response.setResponseBody(pageGenerator->page->toString());
    response.setOKStatus();

    return response;
}

HttpResponse api_method_user_page(HttpRequest request) {

    UserData *userData = new UserData("Stalin.su", "Новый", "Болдин",
                                      "https://sun9-70.userapi.com/c205424/v205424565/2840/Q9ExfkJtduQ.jpg",
                                      19);


    HttpResponse response;
    PageGenerator *pageGenerator = new PageGenerator(port);
    pageGenerator->generateUserPage(*userData);
    response.setResponseBody(pageGenerator->page->toString());
    response.setOKStatus();

    return response;
}

HttpResponse api_method_similar_users(HttpRequest request) {

    std::vector < UserData * > userData{
            new UserData("Stalin.su", "Дмитрий", "Болдин",
                         "https://sun9-70.userapi.com/c205424/v205424565/2840/Q9ExfkJtduQ.jpg",
                         19), new UserData("Stalin.su", "Дмитрий", "Болдин",
                                           "https://sun9-70.userapi.com/c205424/v205424565/2840/Q9ExfkJtduQ.jpg",
                                           19)
    };

    HttpResponse response;
    PageGenerator *pageGenerator = new PageGenerator(port);
    pageGenerator->generateSimilarUsersPage(userData,
                                            Organize::RECT_HORIZONTAL);
    response.setResponseBody(pageGenerator->page->toString());
    response.setOKStatus();

    return response;
}

HttpResponse request_method_similar(HttpRequest request) {
    PageGenerator *pageGenerator = new PageGenerator(port);
    auto post = request.POST();
    if (!request.noParsingErrors()) {
        return api_method(request);
    }

    auto file_uploads_it = post.find("file_uploads");
    auto url = file_uploads_it->second.s;
    if ((file_uploads_it == post.end()) || (url.empty())) {
        return api_method(request);
    }
    HttpResponse response;
    BaseComporator cmp = BaseComporator();
    BaseMetrificator mth = BaseMetrificator();

    auto vec = getFacesVector(url);
    if (!vec.empty()) {
        auto res = ((SearchEngine *) db->search_engine)->get_best_match(vec[0],
                                                                        &cmp,
                                                                        &mth);
        std::cout << "test" << std::endl;
        for (auto r: res) {
            std::cout << r << std::endl;
        }

        if (!res.empty()) {
            pageGenerator->generateManyLinkWithImgPage(url, res);
            response.setResponseBody(pageGenerator->page->toString());
        } else {
            pageGenerator->generateMessagePage("Мы ничего не нашли(((");
            response.setResponseBody(pageGenerator->page->toString());
        }
    } else {

        pageGenerator->generateMessagePage("Мы не нашли лиц на фото(((");
        response.setResponseBody(pageGenerator->page->toString());
    }
    response.setOKStatus();

    return response;
}
HttpResponse not_found_view(HttpRequest request) {
    HttpResponse response;

    std::stringstream response_body;
    response_body << "<title>Test</title>\n"
                  << "<h1>Test</h1>\n"
                  << "<p>This is body of the test page...</p>\n"
                  << "<h2>Request headers</h2>\n"
                  << "<pre>" << "ofkjsp" << "</pre>\n"
                  << "<em><small>Test C++ Http Server</small></em>\n";


    response.setOKStatus();
    response.setContentType("text/html; charset=utf-8");
    response.setResponseBody(response_body.str());
    response.setStatus("404", "Not Found");
    return response;
}


HttpResponse request_method(HttpRequest request) {
    try {
        PageGenerator *pageGenerator = new PageGenerator(port);
        auto post = request.POST();
        if (!request.noParsingErrors()) {
            return api_method(request);
        }

        auto file_uploads_it = post.find("file_uploads");
        auto url = file_uploads_it->second.s;
        if ((file_uploads_it == post.end()) || (url.empty())) {
            return api_method(request);
        }
        HttpResponse response;
        BaseComporator cmp = BaseComporator();
        BaseMetrificator mth = BaseMetrificator();

        auto vec = getFacesVector(url);

        if (!vec.empty()) {

            std::vector<std::string> res = ((SearchEngine *) db->search_engine)->get_best_match(
                    vec[0], &cmp, &mth);

            if (!res.empty()) {
                pageGenerator->generateLinkWithImgPage(url, res[0]);
                response.setResponseBody(pageGenerator->page->toString());
            } else {
                pageGenerator->generateMessagePage("Мы ничего не нашли((((");
                response.setResponseBody(pageGenerator->page->toString());
            }
        } else {
            pageGenerator->generateMessagePage("Мы не нашли лиц на фото(((");
            response.setResponseBody(pageGenerator->page->toString());
        }
        response.setOKStatus();
        return response;
    }
    catch(...){
        std::cout<<"error in"<<std::endl;

    }
}


int main() {
    std::string key;

    key = readKeyFromFile();

    if (!key.empty()) {
        std::cout << "not null key\n";
        db = new DB(collection, 1024, key);
    } else {
        db = new DB(collection, 1024);
        std::cout << "null key\n";
        std::cout << db->get_kd_tree_key();
        writeKeyToFile(db->get_kd_tree_key());

    }


    std::shared_ptr <VkAPI> vk = std::make_shared<VkAPI>("7753493");
    vk->login();
    std::shared_ptr <VkIdListGeneratorStrategy> vkId = std::make_shared<VkIdListGeneratorStrategy>(
            6, "./vkId.txt");
    Crowler cr(vk, vkId, db);
    cr.startCrowl();


    Server server(port);
    server.set_not_found_view(not_found_view);
    server.add_view(api_method, "/");
    server.add_view(api_method_similar_users, "/similar/");
    server.add_view(api_method_user_page, "/userpage/");
    server.add_view(request_method, "/request/");
    //server.add_view(request_method_similar, "/request/");

    server.run();


    return 0;
}