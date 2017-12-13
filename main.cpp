#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "mazzo.h"
#include "cartaobject.h"
#include "cartavincentemodel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    Mazzo m("/Users/sani/mercante_in_fiera/mazzo.txt");


    CartaVincenteModel carteVincentiModel;
    for (int i=0; i<m.carteVincenti().size(); i++) {
        carteVincentiModel.addTmpCarta(CartaVincente(m.carteVincenti().at(i), m.back(), 0));
    }

    CartaVincenteModel carteModel;
    for (int i=0; i<m.carte().size(); i++) {
        carteModel.addTmpCarta(CartaVincente(m.carte().at(i), m.back(), i));
    }

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("etichette", QVariant::fromValue(m.labels()));
    engine.rootContext()->setContextProperty("carteVincentiModel", &carteVincentiModel);
    engine.rootContext()->setContextProperty("carteModel", &carteModel);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
