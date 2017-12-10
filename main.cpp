#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "mazzo.h"
#include "qmlstring.h"
#include "qmlint.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    Mazzo m("/Users/sani/mercante_in_fiera/mazzo.txt");

    QmlString back(m.back());
    QmlInt nCarte(m.nCarte());
    QmlInt nVincenti(m.carteVincenti());

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("carte", QVariant::fromValue(m.carte()));
    engine.rootContext()->setContextProperty("etichette", QVariant::fromValue(m.labels()));
    engine.rootContext()->setContextProperty("vincenti", QVariant::fromValue(m.vincenti()));
    engine.rootContext()->setContextProperty("retro", &back);
    engine.rootContext()->setContextProperty("ncarte", &nCarte);
    engine.rootContext()->setContextProperty("nvincenti", &nVincenti);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
