cmake_minimum_required(VERSION 3.14)
project(CPProject)



set(CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Sources)



set(GTESTS ${CMAKE_CURRENT_SOURCE_DIR}/Sources/StaticGeneration/Google_tests)


find_package(libmongocxx REQUIRED)
find_package(libbsoncxx REQUIRED)
include_directories(${LIBMONGOCXX_INCLUDE_DIR})
include_directories(${LIBBSONCXX_INCLUDE_DIR})
include_directories("/usr/local/include/mongocxx/v_noabi")
include_directories("/usr/local/include/bsoncxx/v_noabi")
include_directories("/usr/local/include/libmongoc-1.0")
include_directories("/usr/local/include/libbson-1.0")
include_directories("/usr/local/lib")




include_directories(${CMAKE_MODULE_PATH})

include_directories(${CMAKE_MODULE_PATH}/StaticGeneration/Views)
include_directories(${CMAKE_MODULE_PATH}/StaticGeneration/DataBase)
include_directories(${CMAKE_MODULE_PATH}/StaticGeneration/PageData)
include_directories(${CMAKE_MODULE_PATH}/StaticGeneration/Page)
include_directories(${CMAKE_MODULE_PATH}/StaticGeneration/PageGenerator)
include_directories(${CMAKE_MODULE_PATH}/StaticGeneration/PageManager)

include_directories(${CMAKE_MODULE_PATH}/StaticGeneration/HttpResponse)
include_directories(${CMAKE_MODULE_PATH}/StaticGeneration/HttpRequest)
include_directories(${CMAKE_MODULE_PATH}/StaticGeneration/LRU)
include_directories(${CMAKE_MODULE_PATH}/StaticGeneration/Server)


set(ALL_SOURCES


        ${CMAKE_MODULE_PATH}/StaticGeneration/Views/SecondaryView/SecondaryView.cpp
        ${CMAKE_MODULE_PATH}/StaticGeneration/Views/UserData/UserData.cpp
        ${CMAKE_MODULE_PATH}/StaticGeneration/Views/Container/ContainerView.cpp
        ${CMAKE_MODULE_PATH}/StaticGeneration/Views/Cell/CellView.cpp
        ${CMAKE_MODULE_PATH}/StaticGeneration/Views/Row/RowView.cpp
        ${CMAKE_MODULE_PATH}/StaticGeneration/Views/ImageView/ImageView.cpp
        ${CMAKE_MODULE_PATH}/StaticGeneration/Views/TableView/TableView.cpp
        ${CMAKE_MODULE_PATH}/StaticGeneration/Views/TextView/TextView.cpp
        ${CMAKE_MODULE_PATH}/StaticGeneration/Views/View/View.cpp
        ${CMAKE_MODULE_PATH}/StaticGeneration/Views/PersonView/PersonView.cpp
        ${CMAKE_MODULE_PATH}/StaticGeneration/Views/Form/FormView.cpp



        ${CMAKE_MODULE_PATH}/StaticGeneration/Page/Page.cpp
        ${CMAKE_MODULE_PATH}/StaticGeneration/PageGenerator/PageGenerator.cpp
        ${CMAKE_MODULE_PATH}/StaticGeneration/PageManager/PageManager.cpp
        ${CMAKE_MODULE_PATH}/StaticGeneration/PageData/PageData.cpp

        ${CMAKE_MODULE_PATH}/WebServer/HttpRequest/HttpRequest.cpp
        ${CMAKE_MODULE_PATH}/WebServer/HttpResponse/HttpResponse.cpp
        ${CMAKE_MODULE_PATH}/WebServer/LRU/LRU.cpp
        ${CMAKE_MODULE_PATH}/WebServer/Server/Server.cpp

        ${CMAKE_MODULE_PATH}/WebCrowler/API/FacebookAPI.cpp
        ${CMAKE_MODULE_PATH}/WebCrowler/API/OkAPI.cpp
        ${CMAKE_MODULE_PATH}/WebCrowler/API/VkAPI.cpp

        ${CMAKE_MODULE_PATH}/WebCrowler/Crowler/Crowler.cpp

        ${CMAKE_MODULE_PATH}/WebCrowler/Id_list_generator_strategy/Facebook_id_list_generator_strategy.cpp
        ${CMAKE_MODULE_PATH}/WebCrowler/Id_list_generator_strategy/Ok_id_list_generator_strategy.cpp
        ${CMAKE_MODULE_PATH}/WebCrowler/Id_list_generator_strategy/Vk_id_list_generator_strategy.cpp

        ${CMAKE_MODULE_PATH}/WebCrowler/NetService/NetService.cpp

        ${CMAKE_MODULE_PATH}/WebCrowler/response/response.cpp

        ${CMAKE_MODULE_PATH}/DataBase/Base/BaseContainer.cpp
        ${CMAKE_MODULE_PATH}/DataBase/Base/BaseComporator.cpp
        ${CMAKE_MODULE_PATH}/DataBase/Base/BaseMetrificator.cpp
        ${CMAKE_MODULE_PATH}/DataBase/Base/BaseDataStructure.cpp
        ${CMAKE_MODULE_PATH}/DataBase/Base/BaseSearchEngine.cpp

        ${CMAKE_MODULE_PATH}/DataBase/KD/Container.cpp
        ${CMAKE_MODULE_PATH}/DataBase/KD/DB.cpp
        ${CMAKE_MODULE_PATH}/DataBase/KD/DBManager.cpp
        ${CMAKE_MODULE_PATH}/DataBase/KD/KDTree.cpp
        ${CMAKE_MODULE_PATH}/DataBase/KD/SearchEngine.cpp


        Sources/PythonMagic.h Sources/StaticGeneration/APIJsonSeializator/Serializator.cpp Sources/StaticGeneration/APIJsonSeializator/Serializator.h)


set(ALL_VIEWS_HEADERS

        ${CMAKE_CURRENT_SOURCE_DIR}/PythonMagic.h


        ${CMAKE_MODULE_PATH}/StaticGeneration/Views/UserData/
        ${CMAKE_MODULE_PATH}/StaticGeneration/Views/Container/
        ${CMAKE_MODULE_PATH}/StaticGeneration/Views/Cell/
        ${CMAKE_MODULE_PATH}/StaticGeneration/Views/Row/
        ${CMAKE_MODULE_PATH}/StaticGeneration/Views/ImageView/
        ${CMAKE_MODULE_PATH}/StaticGeneration/Views/TableView/
        ${CMAKE_MODULE_PATH}v/Views/TextView/
        ${CMAKE_MODULE_PATH}/StaticGeneration/Views/View/
        ${CMAKE_MODULE_PATH}/StaticGeneration/Views/PersonView/
        ${CMAKE_MODULE_PATH}/StaticGeneration/Views/SecondaryView/
        ${CMAKE_MODULE_PATH}/StaticGeneration/Views/Form/
        ${CMAKE_MODULE_PATH}/StaticGeneration/Views/Samples/

        ${CMAKE_MODULE_PATH}/StaticGeneration/Page/
        ${CMAKE_MODULE_PATH}/StaticGeneration/PageGenerator/
        ${CMAKE_MODULE_PATH}/StaticGeneration/PageManager/
        ${CMAKE_MODULE_PATH}/StaticGeneration/PageData/

        ${CMAKE_MODULE_PATH}/WebServer/HttpRequest/
        ${CMAKE_MODULE_PATH}/WebServer/HttpResponse/
        ${CMAKE_MODULE_PATH}/WebServer/LRU/
        ${CMAKE_MODULE_PATH}/WebServer/Server/



        ${CMAKE_MODULE_PATH}/WebCrowler/AbstractClasses/
        ${CMAKE_MODULE_PATH}/WebCrowler/API/
        ${CMAKE_MODULE_PATH}/WebCrowler/Crowler/
        ${CMAKE_MODULE_PATH}/WebCrowler/Id_list_generator_straregy/
        ${CMAKE_MODULE_PATH}/WebCrowler/NetService/
        ${CMAKE_MODULE_PATH}/WebCrowler/response/
        ${CMAKE_MODULE_PATH}/WebCrowler/url/


        ${CMAKE_MODULE_PATH}/DataBase/Base/BaseContainer.h
        ${CMAKE_MODULE_PATH}/DataBase/Base/BaseDataStructure.h
        ${CMAKE_MODULE_PATH}/DataBase/Base/BaseDB.h
        ${CMAKE_MODULE_PATH}/DataBase/Base/BaseDBManager.h
        ${CMAKE_MODULE_PATH}/DataBase/Base/BaseSearchEngine.h


        ${CMAKE_MODULE_PATH}/DataBase/Base/BaseMetrificator.h

        ${CMAKE_MODULE_PATH}/DataBase/KD/Contaier.h
        ${CMAKE_MODULE_PATH}/DataBase/KD/DB.h
        ${CMAKE_MODULE_PATH}/DataBase/KD/DBManager.h
        ${CMAKE_MODULE_PATH}/DataBase/KD/KDTree.h
        ${CMAKE_MODULE_PATH}/DataBase/KD/SearchEngine.h

        )

include_directories(${ALL_SOURCES})
include_directories(${ALL_HEADERS})



add_executable(CPProject.out  ${CMAKE_MODULE_PATH}/main.cpp ${ALL_SOURCES} )



find_package(Boost)

include_directories(${Boost_INCLUDE_DIRS})

target_link_libraries(CPProject.out  ${Boost_LIBRARIES})

set(CURL_LIBRARY "-lcurl")
find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})
target_link_libraries(CPProject.out ${CURL_LIBRARIES})

target_link_libraries(CPProject.out ${LIBMONGOCXX_LIBRARIES})
target_link_libraries(CPProject.out ${LIBBSONCXX_LIBRARIES})

add_subdirectory(Sources/StaticGeneration/Google_tests)



