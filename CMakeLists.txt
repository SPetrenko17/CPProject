cmake_minimum_required(VERSION 3.14)
project(CPProject)



set(CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Sources)




include_directories(${CMAKE_MODULE_PATH})

include_directories(${CMAKE_MODULE_PATH}/Views)
include_directories(${CMAKE_MODULE_PATH}/PageData)
include_directories(${CMAKE_MODULE_PATH}/Page)
include_directories(${CMAKE_MODULE_PATH}/PageGenerator)
include_directories(${CMAKE_MODULE_PATH}/PageManager)

include_directories(${CMAKE_MODULE_PATH}/HttpResponse)
include_directories(${CMAKE_MODULE_PATH}/HttpRequest)
include_directories(${CMAKE_MODULE_PATH}/LRU)
include_directories(${CMAKE_MODULE_PATH}/Server)

set(ALL_SOURCES

        ${CMAKE_MODULE_PATH}/Views/SecondaryView/SecondaryView.cpp
        ${CMAKE_MODULE_PATH}/Views/UserData/UserData.cpp
        ${CMAKE_MODULE_PATH}/Views/Container/ContainerView.cpp
        ${CMAKE_MODULE_PATH}/Views/Cell/CellView.cpp
        ${CMAKE_MODULE_PATH}/Views/Row/RowView.cpp
        ${CMAKE_MODULE_PATH}/Views/ImageView/ImageView.cpp
        ${CMAKE_MODULE_PATH}/Views/TableView/TableView.cpp
        ${CMAKE_MODULE_PATH}/Views/TextView/TextView.cpp
        ${CMAKE_MODULE_PATH}/Views/View/View.cpp
        ${CMAKE_MODULE_PATH}/Views/Samples/SampleViews.cpp
        ${CMAKE_MODULE_PATH}/Views/PersonView/PersonView.cpp
        ${CMAKE_MODULE_PATH}/Views/Form/FormView.cpp



        ${CMAKE_MODULE_PATH}/Page/Page.cpp
        ${CMAKE_MODULE_PATH}/PageGenerator/PageGenerator.cpp
        ${CMAKE_MODULE_PATH}/PageManager/PageManager.cpp
        ${CMAKE_MODULE_PATH}/PageData/PageData.cpp

        ${CMAKE_MODULE_PATH}/HttpRequest/HttpRequest.cpp
        ${CMAKE_MODULE_PATH}/HttpResponse/HttpResponse.cpp
        ${CMAKE_MODULE_PATH}/LRU/LRU.cpp
        ${CMAKE_MODULE_PATH}/Server/Server.cpp
        )


set(ALL_VIEWS_HEADERS
        ${CMAKE_MODULE_PATH}/Views/UserData/
        ${CMAKE_MODULE_PATH}/Views/Container/
        ${CMAKE_MODULE_PATH}/Views/Cell/
        ${CMAKE_MODULE_PATH}/Views/Row/
        ${CMAKE_MODULE_PATH}/Views/ImageView/
        ${CMAKE_MODULE_PATH}/Views/TableView/
        ${CMAKE_MODULE_PATH}/Views/TextView/
        ${CMAKE_MODULE_PATH}/Views/View/
        ${CMAKE_MODULE_PATH}/Views/PersonView/
        ${CMAKE_MODULE_PATH}/Views/SecondaryView/
        ${CMAKE_MODULE_PATH}/Views/Form/
        ${CMAKE_MODULE_PATH}/Views/Samples/

        ${CMAKE_MODULE_PATH}/Page/
        ${CMAKE_MODULE_PATH}/PageGenerator/
        ${CMAKE_MODULE_PATH}/PageManager/
        ${CMAKE_MODULE_PATH}/PageData/
        )

include_directories(${ALL_SOURCES})
include_directories(${ALL_HEADERS})


add_executable(CPProject.out  ${CMAKE_MODULE_PATH}/main.cpp ${ALL_SOURCES} )







#add_executable(CPProject Sources/main.cpp Sources/Views/Container/ContainerView.cpp Sources/Views/Container/ContainerView.h Sources/Views/View/View.cpp Sources/Views/View/View.h Sources/Page/Page.cpp Sources/Page/Page.h Sources/Views/TableView/TableView.cpp Sources/Views/TableView/TableView.h Sources/Views/Column/ColumnView.cpp Sources/Views/Column/ColumnView.h Sources/Views/Row/RowView.cpp Sources/Views/Row/RowView.h Sources/Views/Button/Button.cpp Sources/Views/Button/Button.h Sources/Views/TextView/TextView.cpp Sources/Views/TextView/TextView.h Sources/Views/ImageView/ImageView.cpp Sources/Views/ImageView/ImageView.h Sources/Views/ViewAttributes.cpp Sources/Views/View/ViewAttributes.h Sources/Views/Selector/Selector.cpp Sources/Views/Selector/Selector.h Sources/Views/Type/Type.cpp Sources/Views/Type/Type.h Sources/PageGenerator/PageGenerator.cpp Sources/PageGenerator/PageGenerator.h Sources/PageManager/PageManager.cpp Sources/PageManager/PageManager.h)
