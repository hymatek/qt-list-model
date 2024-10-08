#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "PersonModel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    PersonModel personModel;
    engine.rootContext()->setContextProperty("personModel", &personModel);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
