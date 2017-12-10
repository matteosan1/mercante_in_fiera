#ifndef MAZZO_H
#define MAZZO_H

#include <QObject>
#include <QString>

class Mazzo
{

public:
    Mazzo(const QString& filename);

    //QList<QObject*> carte() const { return m_carte; }
    //QList<QObject*> vincenti() const { return m_vincenti; }
    QList<QObject*> labels() const { return m_label; }
    QString back() const { return m_back; }
    //int carteVincenti() const { return m_vincenti.size(); }
    //int nCarte() const { return m_carte.size(); }

    QList<QString> carte() const { return m_carte; }
    QList<QString> carteVincenti() const { return m_carte_vincenti; }

private:
    //QList<QObject*> m_carte;
    //QList<QObject*> m_vincenti;
    QList<QObject*> m_label;
    QString m_back;
    QList<QString> m_carte;
    QList<QString> m_carte_vincenti;
};

#endif // MAZZO_H
