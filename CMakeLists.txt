cmake_minimum_required(VERSION 3.14)

project(PersonListApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Core Quick REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        PersonModel.h
        PersonModel.cpp
        qml.qrc
)

qt_add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCES}
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    AUTOMOC TRUE
    AUTORCC TRUE
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        Qt6::Core
        Qt6::Quick
)
