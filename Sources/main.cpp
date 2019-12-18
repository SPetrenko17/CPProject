#include <iostream>

#include <vector>
#include <string>
#include <sstream>

#include <PageGenerator/PageGenerator.h>

#include "HttpRequest/HttpRequest.h"
#include "HttpResponse/HttpResponse.h"
#include "Server/Server.h"







using namespace std;

HttpResponse api_method(HttpRequest request) {




    HttpResponse response;
    PageGenerator* pageGenerator = new PageGenerator();
    pageGenerator->generateStartPage();
    response.setResponseBody(pageGenerator->page->toString());
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




int main(){
    Server server(8081);

    server.set_not_found_view(not_found_view);
    server.add_view(api_method, "/");
    //server.add_view(api_method_USERPAGE, "/boobs/");

    server.run();



    return 0;
}