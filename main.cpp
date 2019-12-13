#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "HotelRoom.h"
#include "Hotel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    qmlRegisterType<RoomModel>("Hotel",0,0,"HotelModel");
    qmlRegisterUncreatableType<Hotel>("Hotels",0,0, "Hotels",
                                          QStringLiteral("not in QML"));
    QQmlApplicationEngine engine;

    Hotel Hotel;

    engine.rootContext()->setContextProperty("Hotel",&Hotel);

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
       return -1;

    return app.exec();
}
